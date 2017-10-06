#include <iostream>
#include <list>
#define TCHAR char

// if each visit is coded in each class, then it is just callback pattern
// but functionality of each component are implemented in the visitor
// so separation of functionality to visitor

using namespace std;
#if _UNICODE
typedef wstring tstring;
#else
typedef string tstring;
#endif

//------------------------------------------------------------------
// Element 인터페이스

class Visitor;

class Element
{
public:
	virtual void accept(Visitor* v) = 0; // this is base of composite pattern
};
//------------------------------------------------------------------
// Wheel 상속 클래스
class Wheel : public Element
{
public:
	Wheel(const TCHAR* name) : mName(name) {}

public:
	void accept(Visitor* v) override;
	const TCHAR* getName() const { return mName.c_str(); }

private:
	tstring mName;
};

//------------------------------------------------------------------
// Engine 상속 클래스
class Engine : public Element
{
public:
	void accept(Visitor* v) override;
};

//------------------------------------------------------------------
// Body 상속 클래스
class Body : public Element
{
public:
	void accept(Visitor* v) override;
};

//------------------------------------------------------------------
// Car 상속 클래스 (컴포지트 패턴)
class Car : public Element
{
public:
	void append(Element* e) { mList.push_back(e); }
	void accept(Visitor* v) override;
private:
	list<Element*> mList;
};

//------------------------------------------------------------------
// Visitor 인터페이스
class Visitor
{
public:
	virtual void visit(Wheel* e) = 0;
	virtual void visit(Engine* e) = 0;
	virtual void visit(Body* e) = 0;
	virtual void visit(Car* e) = 0;
};

//------------------------------------------------------------------
// CarPrintVisitor 상속 클래스
class CarPrintVisitor : public Visitor
{
public:
	void visit(Wheel* e) override { cout << "Visiting " << e->getName() << " Wheel" << endl; }
	void visit(Engine* e) override { cout << "Visiting engine" << endl; }
	void visit(Body* e) override { cout << "Visiting body" << endl; }
	void visit(Car* e) override { cout << "Visiting car" << endl; }
};

//------------------------------------------------------------------
// CarStartVisitor 상속 클래스
class CarStartVisitor : public Visitor
{
public:
	void visit(Wheel* e) override { cout << "Kicking my " << e->getName() << " Wheel" << endl; }
	void visit(Engine* e) override { cout << "Starting my engine" << endl; }
	void visit(Body* e) override { cout << "Moving my body" << endl; }
	void visit(Car* e) override { cout << "Starting my car" << endl; }
};

//------------------------------------------------------------------
// 전방 선언에 따른 하단 구현
void Wheel::accept(Visitor* v) { v->visit(this); }
void Engine::accept(Visitor* v) { v->visit(this); }
void Body::accept(Visitor* v) { v->visit(this); }
void Car::accept(Visitor* v) { for (auto i = mList.begin(); i != mList.end(); ++i) (*i)->accept(v); v->visit(this); }

//------------------------------------------------------------------
// Main
int testCompositorVisotrPattern(int argc, TCHAR* argv[])
{
	// 부품 생성
	Wheel mWheel[4] = { "front left", "front right", "back left", "back right" };
	Engine mEngine;
	Body mBody;
	Car mCar;

	// 파트 추가
	mCar.append(&mWheel[0]);
	mCar.append(&mWheel[1]);
	mCar.append(&mWheel[2]);
	mCar.append(&mWheel[3]);
	mCar.append(&mEngine);
	mCar.append(&mBody);

	// visitor 생성
	CarPrintVisitor mCarPrintVisitor;
	CarStartVisitor mCarStartVisitor;

	// visitor accept 처리
	mCar.accept(&mCarPrintVisitor);
	mCar.accept(&mCarStartVisitor);

	return 0;
}

