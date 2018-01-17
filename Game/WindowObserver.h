#pragma once
#include "Observer.h"

class WindowObserver : public Observer
{
public:
	WindowObserver(Subject &sub);
	~WindowObserver();
	void update();
private:
	void print();
	Subject &s;
};