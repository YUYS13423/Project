#include <iostream>
#include <Windows.h>
#include "Move.h"
#include "Actor.h"
using namespace std;

void main() 
{
	Move m;
	m.start();

	while (1)
	{
		m.PrintLocation();
		m.RevisedPhase();
		m.PrintPhase();
		m.Tick();
		Sleep(100);
	}
}