#pragma once
class Trapezoid
{
	double a_x;
	double a_y;
	double b_x;
	double b_y;
	double c_x;
	double c_y;
	double d_x;
	double d_y;
public:
	Trapezoid();
	Trapezoid(double a_x, double a_y, double b_x, double b_y, double c_x, double c_y, double d_x, double d_y);
	double getSideLenght(double x1, double x2, double y1, double y2);
	double getAB();
	double getBC();
	double getCD();
	double getDA();
	double getPerimetr();
	double getAreaTrapezoid();
	bool Equilatural();
	Trapezoid& operator=(const Trapezoid& other);
	void print();
};

