#include<iostream>
using namespace std;
class Student{
    int rollno;
    char name[20];
    int marks[3];
    int total;
    char grade;
public:
    friend istream & operator>>(istream &, Student &);
    friend ostream & operator<<(ostream &, Student &);
    friend void generate_results(Student [], int n);
};

ostream & operator<<(ostream &out, Student &s){
        out<<"Name: "<<s.name<<endl;
        out<<"roll no: "<<s.rollno<<endl;
        out<<"Marks in 3 subjects: ";
        for(int i=0;i<3;i++)
            out<<s.marks[i]<<" ";
        out<<"\nTotal marks: "<<s.total<<endl;
        out<<"Grade: "<<s.grade<<endl;
        return out;
    }
    istream & operator>>(istream &in, Student &s){
        cout<<"enter roll no, name, marks of 3 subjects\n";
        in>>s.rollno>>s.name;
        for(int i=0;i<3;i++)
            cin>>s.marks[i];
        return in;
    }
void generate_results(Student s[], int n){
    for(int j=0;j<n;j++){
            s[j].total=0;
        for(int i=0;i<3;i++)
            s[j].total += s[j].marks[i];

    float avg=s[j].total/3;
    if (avg >= 80)
			s[j].grade = 'A';
		else if (avg >= 60 && avg < 80)
			s[j].grade = 'B';
		else if (avg >= 40 && avg < 60)
			s[j].grade = 'C';
		else
			s[j].grade = 'F';
    }
}

int main(){

    Student s[5];
    for(int i=0;i<5;i++)
    {
        cin>>s[i];
    }
    generate_results(s,5);
    for(int i=0;i<5;i++)
    {
        cout << s[i];
    }
return 0;
}
