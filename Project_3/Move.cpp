#include "Move.h"
#include "Actor.h"
#include <iostream>
#include <Windows.h>

using namespace std;

Move::Move() : a1{}, a2{}, num(0),XY{ PhaseXY::xx}
{
}

void Move::start()
{
	cout << "scale is ? ";
	cin >> num;
	cout << "a1 sp is ? ";
	cin >> a1.sp;
	cout << "a2 sp is ? ";
	cin >> a2.sp;

	for (int i = 0; i < num; i++)
	{
		if (i == 0 || i == num - 1) {
			for (int j = 0; j < num; j++) {
				cout << "* ";
			}
			cout << "\n";
		}
		else {
			cout << "*";
			for (int j = 0; j < num - 2; j++)
			{
				cout << "  ";
			}
			cout << " * " << endl;
		}
	}
	cout << "직전라이니안ㅁ히노히닌ㅇ;ㅣㅇ너;ㅣㄴㅁ";
	Sleep(1000);
}

void Move::Tick()
{
	move(a1);
	move(a2);
}

void Move::PrintLocation()
{
	system("cls");

	cout << endl;
	cout << endl;
	cout << "a1 = (" << a1.x << ", " << a1.y << "), " << "a2 = (" << a2.x << ", " << a2.y << ")" << endl;
}

void Move::move(Actor& m) {
	if (m.sp >= 0) {
		moveup(m);
	}
	else if (m.sp < 0) {
		movedown(m);
		m.myWay = MoveWay::Up;
	}
}

void Move::moveup(Actor& m)
{
	switch (m.myWay)
	{
	case MoveWay::Right:
		//오른쪽으로 이동(+방향)
		m.x = m.x +m.sp;
		if (m.x >= num)
		{
			m.myWay = MoveWay::Up;
			m.y = m.x - num;
			m.x = num;
		}
		break;
	case MoveWay::Up:
		//오른쪽으로 이동(+방향)
		m.y = m.y + m.sp;
		if (m.y >= num)
		{
			m.myWay = MoveWay::Left;
			m.x = num - (m.y - num);
			m.y = num;
		}	
		break;
	case MoveWay::Left:
		//오른쪽으로 이동(+방향)
		m.x = m.x - m.sp;
		if (m.x <= 0)
		{
			m.myWay = MoveWay::Down;
			m.y = num + m.x;
			m.x = 0;
		}
		break;
	case MoveWay::Down:
		//오른쪽으로 이동(+방향)
		m.y = m.y - m.sp;
		if (m.y <= 0)
		{
			m.myWay = MoveWay::Right;
			m.x = -m.y;
			m.y = 0;
		}
		break;
	}
}

void Move::movedown(Actor& m)
{
	switch (m.myWay)
	{
	case MoveWay::Right:
		//오른쪽으로 이동(+방향)
		m.x = m.x + m.sp;
		if (m.x >= num)
		{
			m.myWay = MoveWay::Down;
			m.y = num-(m.x - num);
			m.x = num;
		}
		break;
	case MoveWay::Up:
		//오른쪽으로 이동(+방향)
		m.y = m.y + m.sp;
		if (m.y >= num)
		{
			m.myWay = MoveWay::Right;
			m.x = m.y - num;
			m.y = num;
		}
		break;
	case MoveWay::Left:
		//오른쪽으로 이동(+방향)
		m.x = m.x - m.sp;
		if (m.x <= 0)
		{
			m.myWay = MoveWay::Up;
			m.y = - m.x;
			m.x = 0;
		}
		break;
	case MoveWay::Down:
		//오른쪽으로 이동(+방향)
		m.y = m.y - m.sp;
		if (m.y <= 0)
		{
			m.myWay = MoveWay::Left;
			m.x = num + m.y;
			m.y = 0;
		}
		break;
	}
}

void Move::RevisedPhase()
{
	if (a1.x == a2.x && a1.y == a2.y)
	{
		XY = PhaseXY::oo;
	}
	else if (a1.x == a2.x && a1.y != a2.y)
	{
		XY = PhaseXY::ox;
	}
	else if (a1.x != a2.x && a1.y == a2.y)
	{
		XY = PhaseXY::xo;
	}
	else if (a1.x != a2.x && a1.y != a2.y)
	{
		XY = PhaseXY::xx;
	}
}

void Move::PrintPhase()
{
	int ux, uy, dx, dy = { 0 };
	if (XY == PhaseXY::xx|| XY == PhaseXY::ox)
	{
		if (a1.y > a2.y) {
			uy = a1.y;
			ux = a1.x;
			dy = a2.y;
			dx = a2.x;
		}
		else if (a1.y < a2.y) {
			dy = a1.y;
			dx = a1.x;
			uy = a2.y;
			ux = a2.x;
		}

		for (int i = 0; i < num-uy; i++)
		{
			cout << endl;
		}
		for (int i = 0; i < ux; i++)
		{
			cout << "  ";
		}
		cout << "*";
		for (int i = 0; i <  uy-dy; i++)
		{
			cout << endl;
		}
		for (int i = 0; i < dx; i++)
		{
			cout << "  ";
		}
		cout << "*";
		for (int i = 0; i < dy+1; i++)
		{
			cout << endl;
		}

	}

	else if (XY == PhaseXY::xo)
	{
		if (a1.x > a2.x) {
			uy = a1.y;
			ux = a1.x;
			dx = a2.x;
		}
		else if (a1.x < a2.x) {
			dx = a1.x;
			uy = a2.y;
			ux = a2.x;
		}

		for (int i = 0; i < num - uy; i++)
		{
			cout << endl;
		}
		for (int i = 0; i < dx; i++)
		{
			cout << "  ";
		}
		cout << "* " ;
		for (int i = 0; i < ux-dx; i++)
		{
			cout << "  ";
		}
		cout << "*" ;
		for (int i = 0; i < uy+1; i++)
		{
			cout << endl;
		}

	}
	else if (XY == PhaseXY::oo)
	{
		for (int i = 0; i < num - a1.y; i++)
		{
			cout << endl;
		}
		for (int i = 0; i < a1.x; i++)
		{
			cout << "  ";
		}
		cout << "*";
		for (int i = 0; i < a1.y+1; i++)
		{
			cout << endl;
		}

	}
	cout << "스케일 = " << num<<"  a1.sp = " << a1.sp << "  a2.sp = " << a2.sp << endl;
}



