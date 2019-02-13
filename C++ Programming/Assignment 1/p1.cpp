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
		cout << hr<<":"<<min<<":"<<sec;
	}
};

int main()
{
	Time t1(5, 5, 14),t2(4,5,6),t3;
	
	t3.add_time(t1, t2);
	t3.display();
	getchar();
	return 0;
}
