#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
#pragma warning(disable:4996)
class Student {
	char *sptr;
	int marks[3];
	char gradee;
	float avg;
public:
	void set_Data(char* studentName, char grade, int marks1, int marks2, int marks3)
	{  
		int len;
		len = strlen(studentName);
	    sptr = (char *)malloc((sizeof(char))*(len+1));
		strcpy(sptr,studentName);
		marks[0] = marks1;
		marks[1] = marks2;
		marks[2] = marks3;
		//gradee = grade;

	}
	void calculateAverage()
	{
		int i, sum = 0;
		for (i = 0; i < 3; i++)
		{
			sum = sum + marks[i];
		}
		avg = (float)sum / i;


	}
	void ComputeGrade()
	{
		if (avg > 60)
			gradee = 'A';
		else if (avg > 50 && avg < 60)
			gradee = 'B';
		else if (avg > 40 && avg < 50)
			gradee = 'C';
		else gradee = 'F';

	}
	void display()
	{
		printf("%s\n", sptr);
		cout << "avg:" << avg << endl;
		cout << "grade is:" << gradee << endl;

	}
};
int main()
{
	int size;
	Student s1;
	cout << "enter size of student name" << endl;
	cin >> size;
	int m1, m2, m3;
	char *name = (char *)malloc(size * sizeof(char));
	cout << "enter name of student\n";
	cin >> name;
	cout << "enter marks of 3 subjects" << endl;
	cin >> m1 >> m2 >> m3;
	s1.set_Data(name, ' ', m1, m2, m3);
	s1.calculateAverage();
	s1.ComputeGrade();
	s1.display();
	system("pause");
   return 0;

}