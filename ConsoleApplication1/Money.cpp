#include "Money.h"
#include<iostream>


using namespace std;
Money::Money() : grn(0), kop(0x00) {}
Money::Money(long grn, unsigned char kop)
{
	this->grn = grn;
	while (kop > 99)
	{
		kop -= 100;
		this->grn++;
	}
	this->kop = kop;
}
long Money::getGRN() { return grn; }
unsigned char Money::getKOP() { return kop; }
Money Money::operator+(const Money& second)
{
	long res_grn = this->grn + second.grn;
	unsigned char res_kop = this->kop + second.kop;
	if (res_kop > 99)
	{
		res_grn++;
		res_kop -= 100;
	}
	Money temp(res_grn, res_kop);
	return temp;
}
Money Money::operator-(const Money& second)
{
	long res_grn = this->grn - second.grn;
	unsigned char res_kop = 0;
	if (this->kop < second.kop)
	{
		res_grn--;
		res_kop = this->kop + 100 - second.kop;
	}
	else
	{
		res_kop = this->kop - second.kop;
	}
	Money temp(res_grn, res_kop);
	return temp;
}
Money Money::operator*(const Money& second)
{
	double mult_1 = (double)this->grn + ((double)this->kop / 100);
	double mult_2 = (double)second.grn + ((double)second.kop / 100);
	mult_1 *= mult_2;
	long res_grn = (long)mult_1;
	unsigned char res_kop = (int)mult_1 % 1000;
	Money temp(res_grn, res_kop);
	return temp;
}
Money Money::operator/(const Money& second)
{
	double dev_1 = (double)this->grn + ((double)this->kop / 100);
	double dev_2 = (double)second.grn + ((double)second.kop / 100);
	dev_1 /= dev_2;
	long res_grn = (long)dev_1;
	int res = dev_1 * 100;
	unsigned char res_kop = res % 100;
	Money temp(res_grn, res_kop);
	return temp;
}
bool Money::operator>(const Money& second)
{
	if (this->grn < second.grn)
	{
		return 0;
	}
	else if (this->grn > second.grn)
	{
		return 1;
	}
	else if (this->kop > second.kop)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
bool Money::operator<(const Money& second)
{
	if (this->grn > second.grn)
	{
		return 0;
	}
	else if (this->grn < second.grn)
	{
		return 1;
	}
	else if (this->kop < second.kop)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Money::print()
{
	cout << "\n" << grn << "," << (int)kop;
}

ostream& operator<<(ostream& out, const Money& second)
{
	out << second.grn << "," << (int)second.kop;
	return out;
}
