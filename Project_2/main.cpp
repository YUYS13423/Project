#include <iostream>
#include <Windows.h>

using namespace std;

	//함수 만들기
	//함수 이름:printTo100
	//동작   : 0~100까지 출력
	//입력값 : 없음
	//출력값 : 없음
void printTo100()
{
	int number[100] = { 0 };

	for (int i = 0; i < 100; i++)
	{
		number[i] =i;
		cout << number[i] << endl;
	}
}

	//함수 만들기
	//함수 이름:printToEvent
	//동작   : 0~100까지 짝수 출력
	//입력값 : 없음
	//출력값 : 없음
void printToEvent()
{
	int number[100] = { 0 };

	for (int i = 0; i < 51; i++)
	{
		number[i] = 2*i;
		cout << number[i] << endl;
	}
}

	//함수 이름:printToOdd
	//동작   : 0~100까지 홀수 출력
	//입력값 : 없음
	//출력값 : 없음
void printToOdd()
{
	int number[100] = { 0 };

	for (int i = 0; i < 50; i++)
	{
		number[i] = 2 * i+1;
		cout << number[i] << endl;
	}
}

	//함수 이름:printTo3Dra
	//동작   : 0~100까지 3배수 출력
	//입력값 : 없음
	//출력값 : 없음
void printTo3Dra()
{
	int number[100] = { 0 };

	for (int i = 1; i < 34; i++)
	{
		number[i] = 3 * i;
		cout << number[i] << endl;
	}
}

	//함수 이름:printTo3multi
	//동작   : 0~100까지 3승수 출력
	//입력값 : 없음
	//출력값 : 없음
void printTo3multi()
{
	int number[100] = { 0 };
	number[0] = 1;
	for (int i = 1; i < 5; i++)
	{
		number[i] = number[i-1]*3;
		cout << number[i] << endl;
	}
}

//함수 이름:printToGogodan
//동작   : n의 구구단 * 9 까지 출력
//입력값 : int n
//출력값 : 없음
void printToGogodan(int n)
{
	int number[100] = { 0 };
	for (int j = 2; j < 10; j++)
	{
		number[j] = n * j;
		cout << n << " * " << j << " = ";
		if (number[j] < 10)
		{
			cout << " " << number[j];
		}
		else if (number[j] >= 10)
		{
			cout << number[j];
		}
		cout << endl;
	}
}

//함수 이름: printFactorial
//동작   : n!를 구한 값을 반환한다
//입력값 : int n
//출력값 : int
int printFactorial(int n)
{
	int s = { 1 };
	for (int i = 1; i <= n; ++i)
	{
		s = s * i;
	}
	return s;
}

void stringprint(int x) {
	cout << x << endl;
	Sleep(500);			//500ms
	system("cls");
}

int main()
{
	//x를 Location X라고 가정하고 +방향으로 갔다가 -방향으로 움직이자
	int x = { 0 };
	bool tr = true;
	while (1)
	{
		if (tr ==true && 100 > x) 
		{
			x++;
		}
		else if (tr ==false && 0 < x)
		{
			x--;
		}
		else if (tr == true && x <= 100)
		{
			tr = false;
		}
		else if (tr == false && x >= 0)
		{
			tr = true;
		}
		stringprint(x);
	}
}