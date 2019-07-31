#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Date{
	friend ostream& operator<<(ostream& _cout,const Date& d);
public:
	Date(int year = 1999, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		IsDate();
	}
	int GetDayOfMonth(int month)
	{
		int Day[] = {0 , 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (IsLeap(_year))
			Day[2]++;
		return Day[this->_month];
	}
	Date IsDate()
	{
		while (_day<=0)
		{
			_month--;
			_day = _day + GetDayOfMonth(_month);
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
		}
		while (_day > GetDayOfMonth(_month))
		{
			_day -= GetDayOfMonth(_month);
			_month++;
			if (_month > 12)
			{
				_month=1;
				_year += 1;
			}
		}
		return *this;
	}
	int IsLeap(int year)
	{
		if (_year % 4 == 0 && _year % 100 != 1 || _year % 400 == 0)
			return 1;
		return 0;
	}
	Date AfterNDay(int N)
	{
		Date* tmp = this + N;
		return *tmp;
	}
	int GetDays(Date* a)
	{
		int val = 0;
		for (int i = 0; i < a->_year; i++)
		{
			val += 365;
			if (IsLeap(i))
				val++;
		}
		for (int i = 0; i < a->_month; i++)
		{
			val += GetDayOfMonth(a->_month);
		}
		val += a->_day;
	}
	int GetDiff(Date* a, Date* b)
	{
		int x = GetDays(a);
		int y = GetDays(b);
		if (x>y)
			return x - y;
		return y - x;
	}
	Date operator++()
	{
		_day += 1;
		IsDate();
		return *this;
	}
	Date operator++(int)
	{
		Date* temp(this);
		temp->_day += 1;
		return *temp;
	}
	Date operator+(int n)
	{
		Date* tmp(this);
		tmp->_day=_day + n;
		IsDate();
		return *tmp;
	}
	Date operator-(int n)
	{
		Date* tmp(this);
		tmp->_day = _day - n;
		IsDate();
		return *tmp;
	}

private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout,const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

void test()
{
	Date a(2019, 7, 33);
	Date b(2019,12,15);
//	++a;
//	a++;
	cout << b << endl;
	cout<<b + 3<<endl;
	b.AfterNDay(3);
	cout << b << endl;
	cout << a << endl;
	cout << a - 33 << endl;	
}