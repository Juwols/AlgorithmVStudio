#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<typename T>
class SimpleTemplate {
public:
	SimpleTemplate(T& inObject);
	const T& get() const;
	void set(T& inObject);
protected:
	T& mObject;
};

template<typename T>
SimpleTemplate<T>::SimpleTemplate(T& inObject) : mObject(inObject)
{

}

template<typename T>
const T& SimpleTemplate<T>::get() const
{
	return mObject;
}

template<typename T> // memo_201706 : add a class and all methods definitions
void SimpleTemplate<T>::set(T& inObject)
{
	mObject = inObject;
}