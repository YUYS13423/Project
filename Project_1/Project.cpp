#include <iostream>

using namespace std;

//포인트 4나8바이트 인트 4바이트 용도에 따라 정한다
//함수
double GetArraySum(double arr[], int n);
void printSum(double sum);
double variance(double arr[], int n);
void SwapValues1(int x, int y);
void SwapValues2(int& x, int& y);

//구조체
struct SalesRec {                   //62byte
    char pID[10];                   //10Byte
    int dYear, dMonth, dData;       //3 * 4Byte = 12Byte
    char deliverAddr[40];           //40Byte
};

struct TimeRec {
    int hours;
    int minutes;
    int seconds;
};

void PrSalesRec(SalesRec srec);

//시간 t1에 t2를 더한다.
void AddTime(TimeRec& t1, const TimeRec& t2);
void AddTime(TimeRec& t1, int minutes = 100);//디폴트 값 정의 빈칸으로 두면 100으로 디폴트를 줌

int main()
{
    /*
    double a[50], b[100] ;
    double sum = 0;

    sum = GetArraySum(a, 50);
    printSum(sum);

    sum = GetArraySum(b, 100);
    printSum(sum);
    */
    /*
    int a, b = { 0 };
    cout << "두개의 수를 입력하세요 : ";
    cin >> a >> b;
    SwapValues1(a, b);
    cout << "a = " << a << "b = " << b << endl;
    SwapValues2(a, b);
    cout << "a = " << a << "b = " << b << endl;

    SalesRec stRec;                             //62Byte
    strcpy_s(stRec.pID, "123456789");
    stRec.dYear = 2022;
    stRec.dMonth = 6;
    stRec.dData = 8;
    strcpy_s(stRec.deliverAddr, "강남구 논현");
    PrSalesRec(stRec);
    */

    /*다중정의 오류 사항
 
    매계변수는 달라도 되지만 반환값이 틀릴순 없다
    x
    void func(int a, int b);
    int func(int a, int b);

    o
    void func(int a, int b);
    void func(int a, bool b);


    디폴트 값을 마지막부터 넣어줄 수있다 중간에만 넣어줄 순 없다

    void func(int a, int b, int c=100);     o
    void func(int a, int b=100, int c);     x


    함수에 정의한 매계변수의 갯수이상의 것을 넣을순 없다
    void func(int a,int b)          o
    void func(int a,int b,int c)    x
    -->
    func(a, b)


    다중정의하는 중 없는거 호출하면 에러
    a.void func(int a)
    b.void func(float a)

    func(10)    o
    func(10.0f) o
    func(10.0)  x



    */

    /*
    inline 함수란?
    - 함수 호출 절차를 따르지 않고 함수 호출 위치에 함수의 처리 문장이 삽입되게 번역하도록 선언된 함수
    - 함수를 사용함으로써 얻을 수 있는 모듈화의 장점을 살리면서, 함수 호출에 따른 부수적인 처리시간이 생략됨
    - 함수 호출 루틴으로부터 함수로 넘어가는 부분의 코드 최적화가 가능해짐
    - 매우 빈번히 호출되며 빠른 실행이 요구되는 함수를 inline 함수로 선언하면 성능을 높이는데 도움이 됨
    inline 함수로 선언하더라도 반드시 inline으로 번연되는 것은 아님
    inline 선언을 무시하고 일반 함수로 번역하는 경우
    - 함수가 너무 큰 경우
    - 순환 호출(recursive call)을 하는 경우, 재귀 함수
    - 프로그램 내에서 그 함수에 대한 포인터를 사용하는 경우, 콜백 함수
    inline void SwapValues(int& x, int& y);
    */



    TimeRec time1 = { 2,20,30 };
    TimeRec time2 = { 1,55,48 };

    cout << time1.hours << "시간" << time1.minutes << "분" << time1.seconds << "초 + ";
    cout << time2.hours << "시간" << time2.minutes << "분" << time2.seconds << "초 = ";
    AddTime(time1, time2);
    cout << time1.hours << "시간" << time1.minutes << "분"<< time1.seconds << "초 " << endl;


    cout << time1.hours << "시간" << time1.minutes << "분" << time1.seconds << "초 + ";
    cout << "100분 = ";
    AddTime(time1);
    cout << time1.hours << "시간" << time1.minutes << "분" << endl;
    cout << "210분 = ";
    AddTime(time1, 210);
    cout << time1.hours << "시간" << time1.minutes << "분" << endl;

}

void PrSalesRec(SalesRec srec)//4Byte, 8Byte
{
    cout << "품목코드 : " << srec.pID << endl;
    cout << "배달일자 : " << srec.dYear << endl;
    cout << srec.dMonth <<"월" << srec.dData <<"일" << endl;
    cout << "배달주소 : " << srec.deliverAddr << endl;
}


//각 배열 번호의 값을 넣어주고 전부 합한 값을 반환
double GetArraySum(double arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
        sum += arr[i];
    }
    return sum;
}

void printSum(double sum)
{
    cout << "sum = " << sum << endl;
}

//분산구하기
double variance(double arr[], int n)
{
    double sum = 0, sqSum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
        sqSum += arr[i] * arr[i];
    }
    double result = sqSum / n - sum / (n * n);
    return result;
}
//두개의 수를 서로 바꾸기
void SwapValues1(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    cout << "a = " << x << "b = " << y << endl;
}
void SwapValues2(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

//시간 t1에 t2를 더한다.
void AddTime(TimeRec& t1, const TimeRec& t2)
{
    t1.seconds += t2.seconds;
    t1.minutes += t2.minutes + (t1.seconds / 60);
    t1.hours += t2.hours + (t1.minutes / 60);
    t1.seconds %= 60;
    t1.minutes %= 60;
}

//다중정의
void AddTime(TimeRec& t1, int minutes)
{
    t1.minutes += minutes;
    t1.hours +=(t1.minutes / 60);
    t1.minutes %= 60;
}