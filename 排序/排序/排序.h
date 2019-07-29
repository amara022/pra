#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
//÷±Ω”≤Â»Î≈≈–Ú
void insertSort(int array[], int size){
	for (int i = 0; i < size; i++)
	{
		int k = array[i];
		int j;
		for (j = i - 1; j >= 0 && k < array[j]; j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = k;
	}
}

//œ£∂˚≈≈–Ú
void insertSortWithgap(int array[], int size, int gap){
	{
		for (int i = 0; i < size; i++)
		{
			int k = array[i];
			int j;
			for (j = i - gap; j >= 0 && k < array[j]; j-=gap)
			{
				array[j + gap] = array[j];
			}
			array[j + gap] = k;
		}
	}
}
void shellSort(int array[], int size){
	int gap = size;
	while (1){
		gap = gap / 2;
		insertSortWithgap(array, size, gap);
		if (gap == 1)
			break;
	}
}
//—°‘Ò≈≈–Ú
void selectSort(int array[], int size){
	for (int i = 0; i < size; i++)
	{
		int max = 0;
		for (int j = 0; j < size - i; j++)
		{
			if (array[j]>array[max])
				max = j;
		}
		swap(array + max, array + size - i - 1);
	}
}
//∂—≈≈–Ú
void heapajust(int arr[], int start, int end) { 
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) {  
		if (son + 1 <= end && arr[son] < arr[son + 1]) 
			son++;
		if (arr[dad] > arr[son]) 
			return;
		else {   
			swap(&arr[dad],&arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
void heapSort(int arr[], int len) {
	int i;
	for (i = len / 2 - 1; i >= 0; i--) {
		heapajust(arr, i, len - 1);

	}
	for (i = len - 1; i > 0; --i) {

		swap(arr+0, arr+i);
		heapajust(arr, 0, i - 1);
	}
}
//√∞≈›≈≈–Ú

void bubbleSort(int array[], int size){
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j]>array[j+1])
			swap(array+j, array+j+1);
		}
	}
}
//πÈ≤¢≈≈–Ú
void Merge(int *a, int begin1, int end1, int begin2, int end2, int *tmp)
{
	int index = begin1;
	int i = begin1, j = begin2;
	while (i <= end1&&j <= end2){
		if (a[i] <= a[j])
			tmp[index++] = a[i++];
		else
			tmp[index++] = a[j++];
	}
	while (i <= end1)
		tmp[index++] = a[i++];
	while (j <= end2)
		tmp[index++] = a[j++];
	memcpy(a + begin1, tmp + begin1, sizeof(int)*(end2 - begin1 + 1));
}

void MergeSort(int *a, int left, int right, int *tmp)
{
	if (left >= right)
		return;
	assert(a);
	int mid = left + ((right - left) >> 1);
	MergeSort(a, left, mid, tmp);
	MergeSort(a, mid + 1, right, tmp);
	Merge(a, left, mid, mid + 1, right, tmp);
}
int quickSort(int a[], int p, int q)
{
	int i, j;
	int max, n;
	n = q - p + 1;
	if (p >= q)
	{
		return 0;
	}
	else
	{
		max = a[p];
		j = p;
		for (i = p + 1; i <= q; i++)
		{
			if (max >= a[i])
			{
				n = a[i];
				a[i] = a[j + 1];
				a[j + 1] = n;
				n = a[j];
				a[j] = a[j + 1];
				a[j + 1] = n;
				j = j + 1;
			}
		}
		quickSort(a, p, j - 1);
		quickSort(a, j + 1, q);
	}
	return 0;
}
//º∆ ˝À„∑®
void countSort(int *arr, int size)
{
	int i;
	int minValue = arr[0];
	int maxValue = arr[0];
	int range = 0;
	int* tmp = 0;
	int count = 0;
	for (i = 0; i < size; i++)
	{
		if (arr[i] < minValue){
			minValue = arr[i];
		}
		if (arr[i] > maxValue){
			maxValue = arr[i];
		}
	}
	range = maxValue - minValue + 1;
	tmp = (int*)malloc(sizeof(arr[0])*size);
	if (tmp == NULL)
		return;
	memset(tmp, 0, sizeof(int)*range);
	for (i = 0; i < size; i++)
	{
		tmp[arr[i] - minValue]++;
	}
	for (i = 0; i<range; i++)
	{
		while (tmp[i]--)
		{
			arr[count++] = i + minValue;
		}
	}
	free(tmp);
}
void MyPrint(int array[],int size)
{
	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
}
void test()
{
	int arr[] = { 5, 3, 7, 1, 9, 8, 4, 6, 0, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	countSort(arr,size);
	MyPrint(arr, size);
	system("pause");
}