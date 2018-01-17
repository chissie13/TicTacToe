#include "stdafx.h"
#include "SoundObserver.h"
#include "Subject.h"
#include <windows.h>
#include "iostream"


using namespace std;

SoundObserver::SoundObserver(Subject &sub) :s(sub)
{
}

void SoundObserver::update()								//Makes sounds depending on player
{
	int sound = s.get_board_object().get_turn_int();
	Beep(250*(2^sound), 250);
}