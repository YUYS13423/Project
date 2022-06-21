#include "Actor.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Actor::Actor() : x(0), y(0), myWay{ MoveWay::Right }, sp(1)
{
}
