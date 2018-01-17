#pragma once
#include "Observer.h"

class Subject;

class SoundObserver : public Observer
{
public:
	SoundObserver(Subject &s);
	void update();
private:
	Subject & s;
};