#pragma once

enum class MoveWay {
	Right,
	Up,
	Left,
	Down
};

class Actor {

	
public:
MoveWay myWay;
	int x;
	int y;
	int sp;
	Actor();
};