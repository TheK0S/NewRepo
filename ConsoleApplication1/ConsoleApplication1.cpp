#include <iostream>
#include <cmath>
#include <vector>
#include"Trapezoid.h"
#include"Money.h"
#include<time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int size;
	cout << "Enter the number of trapezoid\n";
	cin >> size;
	Trapezoid* arr = new Trapezoid[size];
	double a_x, a_y, b_x, b_y, c_x, c_y, d_x, d_y;
	for (int i = 0; i < size; i++)
	{
		a_x = rand() % 10;
		a_y = rand() % 10;
		b_x = (rand() % 10) + a_x;
		b_y = (rand() % 10) + a_y;
		c_x = (rand() % 10) + b_x;
		c_y = b_y;
		d_x = (rand() % 10) + c_x;
		d_y = a_y;
		arr[i] = Trapezoid(a_x, a_y, b_x, b_y, c_x, c_y, d_x, d_y);
	}
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i].getAreaTrapezoid();
	}
	double average = sum / size;
	cout << "Average area: " << average;
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].getAreaTrapezoid() > average)
		{
			counter++;
			arr[i].print();
			cout << "\nArea: " << arr[i].getAreaTrapezoid() << "\n";
		}
	}
	cout << "\n" << counter << " trapezoids has area biggest average\n\n";
	delete[] arr;



	//--------------------------------------------------------------------


	Money mon1(167, 55);
	Money mon2(25, 95);
	cout << mon1 << " + " << mon2 << " = " << mon1 + mon2;
	cout << endl << mon1 << " - " << mon2 << " = " << mon1 - mon2;
	cout << endl << mon1 << " * " << mon2 << " = " << mon1 * mon2;
	cout << endl << mon1 << " / " << mon2 << " = " << mon1 / mon2;
	cout << "\n" << (mon1 > mon2);
	cout << "\n" << (mon1 < mon2);
	return 0;
}