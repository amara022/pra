#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>

/*
1.
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����
ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ��������
�ж��������Ƿ��и�����
2.
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1��
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int rowCount = array.size();
		int colCount = array[0].size();
		int i, j;
		for (i = rowCount - 1, j = 0; i >= 0 && j<colCount;)
		{
			if (target == array[i][j])
				return true;
			if (target < array[i][j])
			{
				i--;
				continue;
			}
			if (target > array[i][j])
			{
				j++;
				continue;
			}
		}
		return false;
	}
	int minNumberInRotateArray(vector<int> rotateArray) {
		int n = rotateArray.size();
		if (0 == n)
			return 0;
		for (int i = 0; i < n; i++)
		{
			if (rotateArray[i]>rotateArray[i + 1])
				return rotateArray[i + 1];
		}
		return rotateArray[0];
	}
};

void test()
{
	vector<int> v{ 1, 2, 3, 4, 5 };
	for (auto e : v)
		cout << e << " ";
	cout << endl;
}

int main()
{
	test();
	return 0;
}