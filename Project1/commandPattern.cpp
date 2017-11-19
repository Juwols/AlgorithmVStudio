/*
  Encapsulate and separate action with event.
  Command has just Execute and setReceiver
  Invoker was set by command and call command.Execute which 
  subsequently call Receiver's action
*/
// advantage: invoker only sees command (command can be any)
// task can be presented as encapsulated object
// good when each task is independent and just execute is needed
// TODO: Undo can be implemented often
#include <iostream>

using namespace std;

class Receiver {
public:
	void action() {
		cout << "Receiver: to do something ";
	}
};

class Command {
public: 
	virtual void execute() = 0;
};

class ConcreteCommand : public Command {
public:
	void setReceiver(Receiver* r) {
		pReceiver = r;
	}
	void execute() override {
		pReceiver->action();
	}
private:
	Receiver *pReceiver;
};

class Invoker {
public:
	void setCommand(Command *command) {
		pCommand = command;
	}
	void execute() {
		pCommand->execute();
	}
private:
	Command* pCommand;
};

int testCommand() {
	Invoker mInvoker;
	Receiver mReceiver;
	ConcreteCommand mCommand;
	mCommand.setReceiver(&mReceiver);
	mInvoker.setCommand(&mCommand);
	mInvoker.execute();
	return 0;
}