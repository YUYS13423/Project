#pragma once
#include "Actor.h"

enum class PhaseXY {
	xx,
	ox,
	xo,
	oo
};

class Move 
{
private:
	PhaseXY XY;
	Actor a1;
	Actor a2;
	int num;
public:
	
	Move();

	void moveup(Actor& m);
	void movedown(Actor& m);
	void start();
	void Tick();
	void PrintLocation();
	void move(Actor& m);
	void RevisedPhase();
	void PrintPhase();
};