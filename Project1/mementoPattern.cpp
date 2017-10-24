#include <iostream>
#include <stack>

using namespace std;

//------------------------------------------------------------------
// Memento 클래스
class Memento
{
public:
	Memento(string _state) { state = _state; }

public:
	string getState() const { return state; }

private:
	string state;
};

//------------------------------------------------------------------
// Originator 클래스
class Originator
{
public:
	void setState(string _state)
	{
		state = _state;
		cout << "Originator: Setting state to " << state.c_str() << endl;
	}

public:
	void setMemento(Memento *m)
	{
		if (m)
		{
			state = m->getState();
			delete m;
			cout << "Originator: State after restoring from Memento " << state.c_str() << endl;
		}
	}

	Memento* createMemento()
	{
		cout << "Originator: Create to Memento " << state.c_str() << endl;
		return new Memento(state);
	}

private:
	string state;
};

//------------------------------------------------------------------
// Caretaker 클래스 (Memento 관리)
class Caretaker
{
public:
	void pushMemento(Memento* m) { mStack.push(m); }
	Memento* popMemento() { Memento* m = mStack.top(); mStack.pop(); return m; }

private:
	stack<Memento*> mStack;
};

//------------------------------------------------------------------
// Main
int testMemento()
{
	Caretaker mCaretaker;
	Originator *originator = new Originator();

	originator->setState("state1");
	mCaretaker.pushMemento(originator->createMemento());

	originator->setState("state2");
	mCaretaker.pushMemento(originator->createMemento());

	originator->setMemento(mCaretaker.popMemento());
	originator->setMemento(mCaretaker.popMemento());

	delete originator;

	return 0;
}