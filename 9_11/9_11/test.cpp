#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<vector>

/*
1.
在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数
2.
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
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