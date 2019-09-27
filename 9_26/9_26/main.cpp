#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Data
{
public:
	Data(int year=1999, int month=1, int day=1)
			:_year(year)
			, _month(month)
			, _day(day)
	{
	}
	bool Data::operator==(const Data& d)
	{
		if (d._month == _month&&d._year == _year&&d._day == _day)
			return 1;
		return 0;
	}
private:
	int _year;
	int _month;
	int _day;
};

Data& Data::operator=(const Data& d)
{
	if (this == &d)
		return *this;
	//此处不需要释放空间，申请空间。若其他类需要注意
	this->_day = d._day;
	this->_month = d._month;
	this->_year = d._year;
	return *this;
}
int main()
{
	Data a;
	Data d(1999, 12, 12);
	Data c(2019, 9, 23);
	d = c;//返回this指针，连续赋值
	return 0;
}