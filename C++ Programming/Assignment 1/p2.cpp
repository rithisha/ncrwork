#include<iostream>
#include<cstring>
using namespace std;
class Student {
	char *sptr;
	int marks[3];
	char gradee;
	float avg;
public:
	void set_Data(char* studentName,char grade, int marks1,int marks2, int marks3)
	{
		int len;
		len = strlen(studentName);
		sptr = (char *)malloc(sizeof(char)*(len + 1));
		strcpy_s(sptr,sizeof(sptr), studentName);
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
		avg =(float) sum / i;
		

	}
	void ComputeGrade()
	{
		if (avg > 60)
			gradee = 'A';
		else if (avg > 50&&avg<60)
			gradee = 'B';
		else if (avg > 40&&avg<50)
		gradee = 'C';
		else gradee = 'F';
		
	}
	void display()
	{
		cout << "name:" << *sptr << endl;
		cout << "avg:" << avg << endl;
			cout << "grade is:" << gradee << endl;
			
	}
};
void main()
{
	Student s1;
	s1.set_Data("sai",' ',20,30,40);
	s1.calculateAverage();
	s1.ComputeGrade();
	s1.display();
	getchar();


}