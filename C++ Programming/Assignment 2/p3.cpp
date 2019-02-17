#include<iostream>
using namespace std;
class Employee
{
    char name[24];
    int empno;
    float salary;
    public:
        Employee(){empno=1;salary=10;}
        ~Employee(){}
    friend istream& operator >>(istream &,Employee &);
    void display_data()
    {
        cout<<name<<endl;
        cout<<empno<<endl<<salary;
    }
};
istream& operator>>(istream & in,Employee &e)
{
    cout<<"enter employee name,empno and salary"<<endl;
    in>>e.name>>e.empno;
    in>>e.salary;
}
int  main()
{
    Employee e[5];
    for(int i=0;i<5;i++)
    cin>>e[i];
    for(int i=0;i<5;i++)
    {e[i].display_data();cout<<endl;}


    return 0;
}
