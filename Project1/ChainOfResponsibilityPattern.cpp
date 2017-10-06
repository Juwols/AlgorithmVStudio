// [NF]

#include <iostream>

using namespace std;

class Handler {
public:
	Handler(Handler *pHandle) : pHandler(pHandle) {

	}
	~Handler() {
		if (pHandler) delete pHandler;
	}

	virtual void handleRequest(int i) {
		if (pHandler != NULL) {
			pHandler->handleRequest(i);
		}
	}

private:
	Handler* pHandler;
};

class ConcreteHandler1 : public Handler {
public:
	ConcreteHandler1(Handler* pHandle) : Handler(pHandle) {}

public:
	void handleRequest(int i) override
	{
		cout << "class 1" << endl;
		if (i % 2 == 0) {
			cout << "even number " << endl;
		}
		else {
			Handler::handleRequest(i);
		}
	}
};

class ConcreteHandler2 : public Handler {
public:
	ConcreteHandler2(Handler* pHandle) : Handler(pHandle) {}

public:
	void handleRequest(int i) override
	{
		cout << "class 2" << endl;
		if (i % 2 != 0) {
			cout << "odd number " << endl;
		}
		else {
			Handler::handleRequest(i);
		}
	}
};


class ConcreteHandler3 : public Handler {
public:
	ConcreteHandler3(Handler* pHandle) : Handler(pHandle) {}

public:
	void handleRequest(int i) override
	{
		cout << "class 3" << endl;
		if (i > 2) {
			cout << "bigger " << endl;
		}
		else {
			Handler::handleRequest(i);
		}
	}
};

int testChainOfResponsibility() {
	Handler* pHandler = new ConcreteHandler3(new ConcreteHandler2(new ConcreteHandler1(NULL)));
	pHandler->handleRequest(1);
	return 0;
}