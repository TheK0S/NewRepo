#pragma once
#include<iostream>
using namespace std;
class Money
{
	long grn;
	unsigned char kop;
public:
	Money();
	Money(long grn, unsigned char kop);
	long getGRN();
	unsigned char getKOP();
	Money operator+(const Money& second);
	Money operator-(const Money& second);
	Money operator*(const Money& second);
	Money operator/(const Money& second);
	bool operator>(const Money& second);
	bool operator<(const Money& second);
	friend ostream& operator<< (ostream& out, const Money& second);
	void print();
};

