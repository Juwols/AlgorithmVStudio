#include <iostream>
#include <stack>

/*
  Originater with state
  Caretaker who calls actions
  Memento

  Memento.Add(MementoCustomerEntity);

  execute () {
    new
  }

  var cmd = new ChangeCustomerCommand(cust);
  cmd.Execute(newName);
  cmd.UnExecute();

  object level keeping by certain point state
  
  no matter how many changes of 30 properties, do not care

  private List<MementoForCustomerEntity> _mementos; // not just adding customer

  public void Execute(string newName) {
    _mementos.Add(new MementosForCustomerEntity(Customer));
	Customer.Name = newName;
  }

  public class MementoForCustomerEntity { // memo-20171119: this needed because customer will be just pointer which will change
    public MementoForCustomerEntity(Customer customer) {
	  _customer = customer.Clone();
	}

	public Customer GetCustomer() {
	  _customer;
	}
  }
*/

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