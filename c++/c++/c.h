#include<iostream>
using namespace std;
#include<string.h>
#include<assert.h>
#include<malloc.h>
//c++入门
#if 0
namespace N1
{
	int a = 10;
	int b = 5;
	namespace N2
	{
		int a = 20;
	}
}
namespace N1
{
	int c = 50;
}

void test()
{
	//第一种
	//cout << N1::a << " " <<N1::b<<" "<< N1::N2::a << endl;
	//第二种
	//using N1::a; 
	//using N1::b;
	//	cout << a <<" "<<b<< endl;
	//第三种
		using namespace N1;
		cout << a << " " << N2::a << " " << b << endl;
}
#endif

#if 0
void testFunc(int a , int b ,int c = 5)
{
	cout << a <<" "<<b<<" "<<c<< endl;
}
void test()
{
//	testFunc();
//	testFunc(1);
	testFunc(1, 2);
	testFunc(1, 2, 3);
}
#endif

#if 0
int Add(int a, int b)
{
	cout<<a + b<<endl;
	return a + b;
}
int Add(int a, int b, int c)
{
	cout << a + b + c << endl;
	return a + b + c;
}
double Add(int a, double b)
{
	cout<<a + b<<endl;
	return a + b;
}
double Add(double a, int b)
{
	cout << a + b << endl;
	return a + b;
}
double Add(double a, double b)
{
	cout<<a + b<<endl;
	return a + b;
}

void test()
{
	Add(1, 2, 3);
	Add(1, 3);
	Add(1.0, 3.2);
	Add(1, 2.3);
	Add(2.5, 1);
}
#endif

#if 0
void swap1(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void swap2(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
int da = 0;
inline int Add(int a, int b)
{
	da = a + b;
	return da;
}
void test()
{
	int a = 10;
	int b = 20;
	const int& rb = b;
	const int c = 30;
	const int& rc = c;
	swap1(&a, &b);
	swap2(a, b);
	cout<<Add(a, b)<<endl;
	cout << Add(a, c) << endl;
	int& ra = a;
	int& ra2 = a;

//	int& ra = b;//“ra”: 重定义；多次初始化
	cout << ra << " " << ra2 <<" "<<rb<<" "<< endl;
}
#endif
#if 0
void test()
{
	auto a = 10, b = 20, d = 30, e = 60;
	auto c = 'c';
	auto pa1 = &a;
	auto* pa2 =&a;
	cout << typeid(a).name() << endl;
	cout << typeid(c).name() << endl;
	auto& pa3 = a;
	cout << typeid(pa1).name() << endl;
	cout << typeid(pa2).name() << endl;
	cout << typeid(pa3).name() << endl;
}
#endif
#if 0
void test()
{
	int *p = nullptr;//空指针 NULL:#define NULL 0
	int array[] = { 1, 2, 3, 6, 9, 5, 4 };
	for (auto& e : array)
		e *= 2;
	for (auto e : array)
		cout << e << " ";
}
#endif

#if 0
class Preson
{
public:
	void showPreson();
	void setPreson(char* name,char* gander,int age);
public:
	char* _name;
	char* _gander;
	int _age;
};
void Preson::showPreson()
{
	cout << _name << " " << _gander << " " << _age << endl;
}
void Preson::setPreson(char* name,char* gander,int age)
{
	_name = name;
	_gander = gander;
	_age = age;
}
void test()
{
	Preson a;
	a.setPreson("张三", "男", 13);
	a.showPreson();

	cout << "类的大小为"<< sizeof(a) << endl;
}
#endif

#if 0
class Date
{
public:	

	Date(int year, int month, int date);
	void DateInfo();
private:
	int _year;
	int _month;
	int _date;
};
Date::Date(int year=1990,int month=2,int date=15)
{
	_year = year;
	_month = month;
	_date = date;
}
void Date::DateInfo()
{
	cout << _year << " " << _month << " " << _date << endl;
}

void test()
{
	Date t;
	Date y(2005, 12, 15);
	y.DateInfo();
	t.DateInfo();
}
#endif

#if 0
typedef int DateType;
class SeqLIist
{
public:
	SeqLIist(int capicity = 10)
	{
		_Date = (DateType*)malloc(sizeof(_Date)*_capicity);
		int size = 0;
		_capicity = capicity;
	}
	~SeqLIist()
	{
		if (_Date)
		{
			free(_Date);
			_Date = nullter;
			_capicity = 0;
			_size = 0;
		}
	}
private:
	int* _Date;
	size_t _capicity;
	size_t _size;
};
void test()
{
	SeqLIist q(30);
}
#endif

#if 0
class String
{
public:
	String(char* str)
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String"<<endl;
		free(_str);
	}
private:
	char* _str;
};
class Preon
{
public:
private:
};
void test()
{
	String t("hello world");
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1999, int month = 11, int day = 20)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << _year << " " << _month << " " << _day << endl;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << _year << " " << _month << " " << _day << endl;
	}
	bool operator==(const Date& d)
	{
		return this->_day == d._day && this->_month == d._month && this->_year == d._year;
	}
	Date operator++()
	{
		this->_day += 1;
		return *this;
	}
	Date operator++(int)
	{
		Date temp(*this);
		temp._day += 1;
		return temp;
	}
private:
	int _year;
	int _month;
	int _day;
};

void test()
{
	Date a(2000, 13, 35);
	Date b(a);
	++a;
	a++;
	
}

#endif

#if 0
class Date
{
public:
	Date(int year = 1999, int month = 11, int day = 20)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	void printDate()const
	{
		_day = 30;
		cout << _year << " " << _month << " " << _day << endl;
	}
//	void printfDate()
//	{
//		_day = 30;
//		cout << _year << " " << _month << " " << _day << endl;
//	}
private:
	int _year;
	int _month;
	mutable int _day;
};
void test(){
	Date a;
	a.printDate();
}
#endif

#if 0
class Date
{
public:
	Date(int year = 1999, int month = 11, int day = 20)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}
private:
	int _year;
	int _month;
	mutable int _day;
};
void test(){
	Date a;
	cout << &a << endl;
}
#endif
#if 0
class Date
{
public:
	explicit Date(int year=1999,int month=12,int day=12)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << _year << "-" << _month << "-" << _day;
	}
private:
	int _year;
	int _month;
	int _day;
};
void test()
{
	Date a;
}
#endif

#if 0
class Date
{
public:
	explicit Date(int year = 1999, int month = 12, int day = 12)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << _year << "-" << _month << "-" << _day;
	}
	// 非静态成员变量，可以在成员声明时给缺省值。
private:
	int _year;
	int _month;
	int _day;
	static int n;
};
int Date::n = 2;
void test()
{
	Date a;
}
#endif

#if 0
class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	explicit Date(int year = 1999, int month = 12, int day = 12)
		:_year(year)
		, _month(month)
		, _day(day)
	{};
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

void test()
{
	Date a;
	cout << a << endl;
}
#endif

#if 0
class Date;
class Time
{
	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
public:
	Time(int hour = 15, int minute = 43, int second = 30)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{};
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
		cout << _year << "-" << _month << "-" << _day << endl;
		cout << _t._hour << "-" << _t._minute << "-" << _t._second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
void test()
{
	Date d;
}
#endif

class A
{
private:
	static int k;
	int h;
public:
	class B
	{
	public:
		void find(const A& a)
		{
			cout << k << endl;
			cout << a.h << endl;
		}
	};
};
int A::k = 1;
void test()
{
	A::B b;
	b.find(A());
}