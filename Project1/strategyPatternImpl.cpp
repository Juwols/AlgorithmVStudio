#include <iostream>

/*
  Behavioral, behavior is selected at runtime
  getWeather may return simple one day, 15 days, ... selected by runtime
  calling same method but changes at runtime
  Example, logger give more based on status
  Example, sort => various sort based on situation
  In the below example, Hero can change superpower. and it is always ExerciseSuperpower
  which is ISuperPower.ExerciseSuperPower
  As conclustion, similar to Command pattern separate execution


  Difference between Command and Strategy???
  In remote control command case, at runtime change DVR, VCR....

*/
#if 0
using namespace std;
class ISuperPower {
public: 
	virtual string ExerciseSuperPower() = 0;
	void something() {

	}
};

class IHero {
public: 
	virtual string DoHeroStuff() = 0; 
	virtual void ChangeSuperPower(ISuperPower power) = 0;
};

class RegularJoe : public IHero{
public:

};
class WebWedding : public ISuperPower {
public:

};

int testStrategy() {
	IHero spider = new Spiderman();
	spider.ChangeSuperPower(new WebWedding());
	spider.DoHeroStuff();
	spider.ChangeSuperPower(new Flying());
	return 0;
}
#endif