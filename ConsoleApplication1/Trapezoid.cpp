#include "Trapezoid.h"
#include<iostream>
#include<cmath>
using namespace std;

	Trapezoid::Trapezoid()
	{
		a_x = a_y = b_x = b_y = c_x = c_y = d_x = d_y = 0;
	}
	Trapezoid::Trapezoid(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y, double d_x, double d_y)
	{
		this->a_x = a_x;
		this->a_y = a_y;
		this->b_x = b_x;
		this->b_y = b_y;
		this->c_x = c_x;
		this->c_y = c_y;
		this->d_x = d_x;
		this->d_y = d_y;
	}
	double Trapezoid::getSideLenght(double x1, double x2, double y1, double y2)
	{
		return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	}
	double Trapezoid::getAB()
	{
		return getSideLenght(b_x, a_x, b_y, a_y);
	}
	double Trapezoid::getBC()
	{
		return getSideLenght(c_x, b_x, c_y, b_y);
	}
	double Trapezoid::getCD()
	{
		return getSideLenght(d_x, c_x, d_y, c_y);
	}
	double Trapezoid::getDA()
	{
		return getSideLenght(a_x, d_x, a_y, d_y);
	}
	double Trapezoid::getPerimetr()
	{
		return getAB() + getBC() + getCD() + getDA();
	}
	double Trapezoid::getAreaTrapezoid()
	{
		double a = getBC();
		double b = getDA();
		double c = getAB();
		double d = getCD();
		return 0.25 * ((b + a) / (b - a)) * sqrt((b + c + d - a) * (a - b + c - d) * (a - b - c + d));
	}
	bool Trapezoid::Equilatural()
	{
		return getAB() == getCD() ? true : false;
	}
	Trapezoid& Trapezoid::operator=(const Trapezoid& other)
	{
		this->a_x = other.a_x;
		this->a_y = other.a_y;
		this->b_x = other.b_x;
		this->b_y = other.b_y;
		this->c_x = other.c_x;
		this->c_y = other.c_y;
		this->d_x = other.d_x;
		this->d_y = other.d_y;
		return *this;
	}
	void Trapezoid::print()
	{
		cout << "\na_x: " << a_x << "  a_y: " << a_y;
		cout << "\nb_x: " << b_x << "  b_y: " << b_y;
		cout << "\nc_x: " << c_x << "  c_y: " << c_y;
		cout << "\nd_x: " << d_x << "  d_y: " << d_y;
		cout << "\nAB: " << getAB() << "\tBC: " << getBC() << "\tCD: " << getCD() << "\tDA: " << getDA();
	}