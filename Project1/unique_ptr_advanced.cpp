#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>
using namespace std;

struct UniqueTest {
	virtual void bar() { std::cout << "UniqueTest::bar" << endl; }
	virtual ~UniqueTest() = default; // memo_201710: Prevent default constructor http://en.cppreference.com/w/cpp/language/default_constructor
};

struct UniqueTestSub : UniqueTest {
	UniqueTestSub() { std::cout << "D::D" << endl; }
	~UniqueTestSub() { std::cout << "D::~D" << endl; }
	void bar() override { std::cout << "D::bar" << endl; } // memo_201710: explicit overriding to make sure parents has it
};

std::unique_ptr<UniqueTest> pass_through(std::unique_ptr<UniqueTest> p) {
	p->bar();
	return p;
}

int uniqueAdvanced() {
	cout << "unique ownersip semantics demo" << endl;
	{
		auto p = std::make_unique<UniqueTest>(); // // memo_201710: do not forge make_unique param 1 and 2
		auto q = pass_through(move(p)); // memo_201710: do not forge make_unique param 1 and 2
		assert(!p); // assert in c++
		q->bar();
	}
	cout << "runtime polymorphism" << endl;
	{
		unique_ptr<UniqueTest> p = std::make_unique<UniqueTest>(); //http://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared
		cout << "Expect D" << endl;
		p->bar();
		vector<unique_ptr<UniqueTest>> v;
		v.push_back(std::make_unique<UniqueTestSub>());
		v.push_back(move(p));
		v.emplace_back(new UniqueTestSub); // TODO: emplace_back ???
		cout << "now for loop....." << endl;
		cout << "expect: D, D, D " << endl;
		for (auto& p : v) p->bar();
	}
	cout << "custom deleter demo" << endl;
	ofstream("demo.txt") << 'x';
	{
#ifdef __unix__ 
		unique_ptr<FILE, decltype(&fclose)> fp(std::fopen("demo.txt", "r"), &std::fclose); // TODO: function reference for return
		if (fp) cout << fgetc(fp.get()) << endl;
#elif defined(_WIN32) || defined(WIN32)
#endif
	}

	cout << "custom lambda-expression delete demo" << endl;
	{
		unique_ptr<UniqueTestSub, std::function<void(UniqueTestSub*)>> p(new UniqueTestSub, [](UniqueTestSub* ptr) { // just anonimouse with this type : remeber function to be function pointer
			std::cout << "Destroying from a custom delete.... " << endl;
			delete ptr;
		});
		p->bar();
	}

	cout << "Array form of unique_ptr demo" << endl;
	{
		unique_ptr<UniqueTestSub[]> p{ new UniqueTestSub[3] };
	}
	return 0;
}

