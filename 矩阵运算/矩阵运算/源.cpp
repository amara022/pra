#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <string.h>

using namespace std;


template<class T>
class linearList
{
public:
	virtual ~linearList() { };
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T& get(int theIndex) const = 0;
	//	virtual int indexOf(const T& theElement) const = 0;
	virtual void erase(int theIndex) = 0;
	virtual void insert(int theIndex, const T& theElement) = 0;
	//	virtual void output(ostream& out) const = 0;
};

template<class T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
	//if (newLength < 0)
	//	throw illegalParameterValue("new length must be >= 0");

	T* temp = new T[newLength];
	int number = min(oldLength, newLength);
	copy(a, a + number, temp);
	delete[] a;
	a = temp;
}

template<class T>
class arrayList : public linearList<T>
{
public:
	arrayList<T>& operator = (const arrayList<T>&);

	arrayList(int initialCapacity = 10);
	arrayList(const arrayList<T>&);
	~arrayList() { delete[] element; }

	bool empty() const { return listSize == 0; }
	int size() const { return listSize; }
	T& get(int theIndex) const;
	void set(int index, const T&);
	//	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);
	//	void output(ostream& out) const;
	//	int capacity() const { return arrayLength; }
	void clear();
	void reSet(int newLength);
	class iterator;
	iterator begin() const { return iterator(element); }
	iterator end() const { return iterator(element + listSize); }

protected:
	//	void checkIndex(int theIndex) const;
	T* element;
	int arrayLength;
	int listSize;
	int initialCapacity;
};

template<class T>
arrayList<T>& arrayList<T>::operator = (const arrayList<T>& rhs)
{
	if (this != &rhs) {
		arrayLength = rhs.arrayLength;
		listSize = rhs.listSize;
		initialCapacity = rhs.initialCapacity;
		delete[] element;
		element = new T[arrayLength];
		copy(rhs.element, rhs.element + listSize, element);
	}

	return *this;
}


template<class T>
arrayList<T>::arrayList(int initialCapacity)
: arrayLength(initialCapacity), listSize(0), initialCapacity(initialCapacity)
{
	//if (initialCapacity < 1) {
	//	ostringstream s;
	//	s << "initial capacity = " << initialCapacity << "Must be > 1";
	//	throw illegalParameterValue(s.str());
	//}

	element = new T[initialCapacity];
}

//template<class T>
//void arrayList<T>::checkIndex(int theIndex) const
//{
//	if (theIndex < 0 || theIndex >= listSize) {
//		ostringstream s;
//		s << "index = " << theIndex << " size = " << listSize;
//		throw illegalIndex(s.str());
//	}
//}

template<class T>
T& arrayList<T>::get(int theIndex) const
{
	//checkIndex(theIndex);

	return element[theIndex];
}

template<class T>
void arrayList<T>::set(int index, const T& theValue)
{
	//checkIndex(index);

	element[index] = theValue;
}
//
//template<class T>
//int arrayList<T>::indexOf(const T& theElement) const
//{
//	int theIndex = static_cast<int>(find(element, element + listSize, theElement) - element);
//
//	if (theIndex == listSize)
//		return -1;
//	else return theIndex;
//}
//


template<class T>
void arrayList<T>::erase(int theIndex)
{
	//checkIndex(theIndex);

	copy(element + theIndex + 1, element + listSize, element + theIndex);

	element[listSize--].~T();

	if (listSize < arrayLength / 4) {
		int number = max(initialCapacity, arrayLength / 2);
		changeLength1D(element, arrayLength, number);
		arrayLength = number;
	}
}

template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
	//if (theIndex < 0 || theIndex > listSize) {
	//	ostringstream s;
	//	s << "index = " << theIndex << " size = " << listSize;
	//	throw illegalIndex(s.str());
	//}

	if (listSize == arrayLength) {
		changeLength1D(element, arrayLength, arrayLength * 2);
		arrayLength *= 2;
	}

	copy_backward(element + theIndex, element + listSize, element + listSize + 1);

	element[theIndex] = theElement;
	listSize++;
}
//
//template<class T>
//void arrayList<T>::output(ostream& out) const
//{
//	copy(element, element + listSize, ostream_iterator<T>(out, " "));
//}

template<class T>
void arrayList<T>::clear()
{
	delete[] element;

	element = new T[initialCapacity];
	arrayLength = initialCapacity;
	listSize = 0;
}

template<class T>
void arrayList<T>::reSet(int newLength)
{
	if (newLength > arrayLength)
	{
		changeLength1D(element, arrayLength, newLength);
		arrayLength = newLength;
	}
	listSize = newLength;
}

template<class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
{
	x.outPut(out);
	return out;
}



template<class T>
class arrayList<T>::iterator
{

public:
	typedef bidirectional_iterator_tag iterator_category;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;

	int operator-(const iterator rhs) {
		return position - rhs.position;
	}
	iterator(T* thePosition = nullptr) { position = thePosition; }

	T& operator*() const { return *position; }
	T* operator->() const { return &*position; }

	iterator& operator++() {
		++position;			return *this;
	}
	iterator operator++(int) {
		iterator old = *this;
		++position;
		return old;
	}

	iterator operator--() {
		--position;
		return *this;
	}
	iterator operator--(int) {
		iterator old = *this;
		--position;
		return old;
	}


	bool operator==(const iterator rhs) const {
		return position == rhs.position;
	}
	bool operator!=(const iterator rhs) const {
		return !(*this == rhs);
	}
protected:
	T* position;
};


template<class T>
struct matrixTerm {
	matrixTerm() = default;
	matrixTerm(int row, int col, const T& value)
		:row(row), col(col), value(value) { }
	int row;
	int col;
	T value;
};


template<class T>
bool operator == (const matrixTerm<T>& lhs, const matrixTerm<T>& rhs)
{
	return (lhs.row == rhs.row) && (lhs.col == rhs.col) && (lhs.value == rhs.value);
}



template<class T>
ostream& operator << (ostream& out, const matrixTerm<T>& m)
{
	out << "(" << m.row << ", " << m.col << "):" << m.value << " ";
	return out;
}

template<class T>
class sparseMatrix;

//template<class T>
//ostream& operator << (ostream& out, const sparseMatrix<T>& x)
//{
//	out << "rows = " << x.row << " columns = " << x.col << endl;
//
//	for (auto iter = x.terms.begin(); iter != x.terms.end(); iter++)
//		cout << "(" << (*iter).row << ", " << (*iter).col << ") = " << (*iter).value << endl;
//	return out;
//}

template<class T>
istream& operator >> (istream& in, sparseMatrix<T>& x)
{
	//	cout << "Enter number of rows, columns and #terms" << endl;

	int numberOfTerms = 0;

	in >> x.rows >> x.cols;

	matrixTerm<T>* temp = new matrixTerm<T>[x.rows * x.cols];

	for (int i = 1; i <= x.rows; i++)
	for (int j = 1; j <= x.cols; j++) {
		T t;
		in >> t;
		if (t != 0)
			temp[numberOfTerms++] = matrixTerm<T>(i, j, t);
	}

	x.terms.reSet(numberOfTerms);

	for (int i = 0; i < numberOfTerms; i++) {
		//		cout << "Enter row, column and value of term" << endl;
		//		in >> mTerm.row >> mTerm.col >> mTerm.value;

		x.terms.set(i, temp[i]);
	}
	delete[] temp;
	return in;
}

template<class T>
class sparseMatrix {

	//friend ostream& operator << <T>(ostream&, const sparseMatrix<T>&);
	friend istream& operator >> <T>(istream&, sparseMatrix<T>&);

public:
	sparseMatrix() = default;
	sparseMatrix(int rows, int cols) : rows(rows), cols(cols) { }
	sparseMatrix<T>& operator = (const sparseMatrix<T>& rhs);

	void transpose(sparseMatrix<T>& b);
	void add(sparseMatrix<T>& b);
	T get(int, int) const;
	void set(int, int, const T&);
	void output(ostream&) const;
	void reSet(istream&);
	void multiply(sparseMatrix<T>& b);
private:
	int rows;
	int cols;
	arrayList<matrixTerm<T>> terms;
};

template<class T>
sparseMatrix<T>& sparseMatrix<T>::operator = (const sparseMatrix<T>& rhs)
{
	if (this != &rhs)
	{
		rows = rhs.rows;
		cols = rhs.cols;
		terms = rhs.terms;
	}
	return *this;
}

template<class T>
void sparseMatrix<T>::transpose(sparseMatrix<T>& b)
{
	b.rows = rows;
	b.cols = cols;
	b.terms.reSet(terms.size());

	int* colSize = new int[cols + 1];
	int* rowNext = new int[cols + 1];

	memset(colSize, 0, cols + 1);
	memset(rowNext, 0, cols + 1);

	for (typename arrayList<T>::iterator i = terms.begin(); i != terms.end(); i++)
		colSize[(*i).col]++;

	for (int i = 1; i < b.rows; i++)
		rowNext[i] = colSize[i - 1] + rowNext[i - 1];

	matrixTerm<T> mTerm;
	for (typename arrayList<T>::iterator i = terms.begin(); i != terms.end(); i++) {
		mTerm.row = (*i).col;
		mTerm.col = (*i).row;
		mTerm.value = (*i).value;

		int j = rowNext[(*i).col]++;
		b.terms.set(j, mTerm);
	}

}

template<class T>
void sparseMatrix<T>::add(sparseMatrix<T>& b)
{
	if (rows != b.rows || cols != b.cols)
	{
		cout << -1 << endl;
		*this = b;
		return;
	}
	sparseMatrix<T> c(rows, cols);

	int sizeC = 0;

	typename arrayList<matrixTerm<T>>::iterator it = terms.begin();
	typename arrayList<matrixTerm<T>>::iterator ib = b.terms.begin();
	typename arrayList<matrixTerm<T>>::iterator itEnd = terms.end();
	typename arrayList<matrixTerm<T>>::iterator ibEnd = b.terms.end();

	while (it != itEnd && ib != ibEnd) {
		int tIndex = ((*it).row - 1) * cols + (*it).col;
		int bIndex = ((*ib).row - 1) * cols + (*ib).col;

		if (tIndex < bIndex)
			c.terms.insert(sizeC++, *it++);

		else {
			if (tIndex == bIndex) {
				T theResult = (*it).value + (*ib).value;
				if (theResult != 0) {
					matrixTerm<T> mTerm((*it).row, (*it).col, theResult);
					c.terms.insert(sizeC++, mTerm);
				}
				it++;
				ib++;
			}

			else
				c.terms.insert(sizeC++, *ib++);
		}

	}

	for (; it != itEnd; it++)
		c.terms.insert(sizeC++, *it++);

	for (; ib != ibEnd; ib++)
		c.terms.insert(sizeC++, *ib++);

	*this = c;
	return;
}

template<class T>
T sparseMatrix<T>::get(int theRow, int theCol) const
{
	auto curMTerm = terms.begin();
	while (curMTerm != terms.end() && !((*curMTerm).row == theRow && (*curMTerm).col == theCol))
		++curMTerm;

	if (curMTerm == terms.end()) {
		//		cout << "sparseMatrix get Î´ÕÒµ½" << endl;
		return 0;
	}

	return (*curMTerm).value;
}

template<class T>
void sparseMatrix<T>::set(int theRow, int theCol, const T& theValue)
{
	int i = 0;
	int theSize = terms.size();
	for (; i < theSize; i++) {
		auto e = terms.get(i);
		if (e.row == theRow && e.col == theCol)
		{
			terms.set(i, matrixTerm<T>(theRow, theCol, theValue));
			return;
		}
		else if (e.row >= theRow && e.col >= theCol)
		{
			terms.insert(i, matrixTerm<T>(theRow, theCol, theValue));
			return;
		}
	}
	if (i == terms.size())
		terms.insert(terms.size(), matrixTerm<T>(theRow, theCol, theValue));

}
template<class T>
void sparseMatrix<T>::output(ostream& out) const
{
	int lastRow = 1;
	int lastCol = 0;
	int currentCol = 0;
	cout << rows << " " << cols << endl;
	for (auto c : terms) {
		int zeroRows = (c.row - lastRow - 1) >= 0 ? c.row - lastRow - 1 : 0;
		int zeroCols = (c.col > lastCol) ? (c.col - lastCol - 1) : (cols - lastCol + c.col - 1);
		int numOfZero = zeroRows * cols + zeroCols;
		for (int i = 0; i < numOfZero; i++) {
			out << 0 << " ";
			if (++currentCol == cols)
			{
				out << endl;
				currentCol = 0;
			}
		}
		out << c.value << " ";
		if (++currentCol == cols)
		{
			out << endl;
			currentCol = 0;
		}

		lastRow = c.row;
		lastCol = c.col;
	}
}

template<class T>
void sparseMatrix<T>::reSet(istream& in)
{
	in >> *this;
}

template<class T>
void sparseMatrix<T>::multiply(sparseMatrix<T>& b)
{
	if (cols != b.rows) {
		*this = b;
		cout << -1 << endl;
		return;
	}

	sparseMatrix<T> c(this->rows, b.cols);
	for (auto iterA = terms.begin(); iterA != terms.end(); iterA++)
	for (auto iterB = b.terms.begin(); iterB != b.terms.end(); iterB++) {
		int theRow = (*iterA).row;
		int col1 = (*iterA).col;
		int row1 = (*iterB).row;
		int theCol = (*iterB).col;
		//int x1 = c.get(theRow, theCol);
		//int x2 = x1 + (*iterA).value * (*iterB).value;
		if (col1 == row1)
			c.set(theRow, theCol, c.get(theRow, theCol) + (*iterA).value * (*iterB).value);
	}

	for (auto iter = c.terms.begin(); iter != c.terms.end(); iter++)
	if ((*iter).value == 0)
		c.terms.erase(iter - c.terms.begin());

	*this = c;

	return;
}

template<class T>
class Solution : protected sparseMatrix<T>
{
public:
	void operation(int);
private:
	void reSet();
	void multiply();
	void add();
	void output();
};

template<class T>
void Solution<T>::operation(int x)
{
	switch (x) {
	case 1: reSet(); break;
	case 2: multiply(); break;
	case 3: add(); break;
	case 4: output(); break;
	}
}

template<class T>
void Solution<T>::reSet()
{
	sparseMatrix<T>::reSet(cin);
}

template<class T>
void Solution<T>::multiply()
{
	sparseMatrix<T> b;
	cin >> b;
	sparseMatrix<T>::multiply(b);
}

template<class T>
void Solution<T>::add()
{
	sparseMatrix<T> b;
	cin >> b;
	sparseMatrix<T>::add(b);
}

template<class T>
void Solution<T>::output()
{
	sparseMatrix<T>::output(cout);
}

int main()
{
	Solution<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
	{
		int x;
		cin >> x;
		s.operation(x);
	}

}