#include <iostream>
#include <Windows.h>

using namespace std;

	//�Լ� �����
	//�Լ� �̸�:printTo100
	//����   : 0~100���� ���
	//�Է°� : ����
	//��°� : ����
void printTo100()
{
	int number[100] = { 0 };

	for (int i = 0; i < 100; i++)
	{
		number[i] =i;
		cout << number[i] << endl;
	}
}

	//�Լ� �����
	//�Լ� �̸�:printToEvent
	//����   : 0~100���� ¦�� ���
	//�Է°� : ����
	//��°� : ����
void printToEvent()
{
	int number[100] = { 0 };

	for (int i = 0; i < 51; i++)
	{
		number[i] = 2*i;
		cout << number[i] << endl;
	}
}

	//�Լ� �̸�:printToOdd
	//����   : 0~100���� Ȧ�� ���
	//�Է°� : ����
	//��°� : ����
void printToOdd()
{
	int number[100] = { 0 };

	for (int i = 0; i < 50; i++)
	{
		number[i] = 2 * i+1;
		cout << number[i] << endl;
	}
}

	//�Լ� �̸�:printTo3Dra
	//����   : 0~100���� 3��� ���
	//�Է°� : ����
	//��°� : ����
void printTo3Dra()
{
	int number[100] = { 0 };

	for (int i = 1; i < 34; i++)
	{
		number[i] = 3 * i;
		cout << number[i] << endl;
	}
}

	//�Լ� �̸�:printTo3multi
	//����   : 0~100���� 3�¼� ���
	//�Է°� : ����
	//��°� : ����
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

//�Լ� �̸�:printToGogodan
//����   : n�� ������ * 9 ���� ���
//�Է°� : int n
//��°� : ����
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

//�Լ� �̸�: printFactorial
//����   : n!�� ���� ���� ��ȯ�Ѵ�
//�Է°� : int n
//��°� : int
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
	//x�� Location X��� �����ϰ� +�������� ���ٰ� -�������� ��������
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