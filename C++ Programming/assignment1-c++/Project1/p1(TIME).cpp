#include<iostream>
using namespace std;
class Time
{
	int hr;
	int min;
	int sec;
public:
	Time()
	{
		hr = min = sec = 0;
	}
	Time(int h, int m, int s)
	{
		hr = h;
		min = m;
		sec = s;
	}
	void add_time(Time t1, Time t2)
	{
		hr = t1.hr + t2.hr;
		min = t1.min + t2.min;
		sec = t1.sec + t2.sec;
	}
	void display()
	{
		cout << hr << ":" << min << ":" << sec;
	}
};

int main()
{
	int hr1, hr2, min1, min2, sec1, sec2;
	cout << "enter time1 in 24 hr format hr:min:sec\n";
	cin >> hr1 >> min1 >> sec1;
	cout << "enter time2 in 24 hr format hr:min:sec\n";
	cin >> hr2 >> min2 >> sec2;
	Time t1(hr1, min1, sec1), t2(hr2, min2, sec2), t3;

	t3.add_time(t1, t2);
	t3.display();
	system("pause");
	return 0;
}
