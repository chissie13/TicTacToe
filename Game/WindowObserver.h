#pragma once
#include "Observer.h"

class WindowObserver : public Observer
{
public:
	void update(Subject &s);
	WindowObserver();
	~WindowObserver();
private:
	void print(Subject &s);
	void WindowObserver::setupConsole();
};