#include<iostream>
using namespace std;
class Complex
{
	float real, imag;
public:
	Complex()
	{
		real = 0;
		imag = 0;
	}
	Complex(float r)
	{
		real = r;
		imag = r;
	} 
	Complex(float r, float i)
	{
		real = r;
		imag = i;
	}
	friend void addcomplex(Complex &, Complex &);
	friend void mulcomplex(Complex &, Complex &);
};
void addcomplex(Complex &c1, Complex &c2)
{
	float real, imag;
	real = c1.real + c2.real;
	imag = c1.imag + c2.imag;
	cout << "result :" << real <<","<< imag << endl;
}
void mulcomplex(Complex &c1, Complex &c2)
{
	float real, imag;
	real = (c1.real*c2.real)-(c1.imag*c2.imag);
	imag = (c1.real*c2.imag) + (c1.imag*c2.real);
	cout << "result :" << real << "," << imag << endl;
}
void main()
{
	Complex c1(3, 4),c2(7, 1),c3;
	addcomplex(c1, c2);
	mulcomplex(c1,c2);
	getchar();
}