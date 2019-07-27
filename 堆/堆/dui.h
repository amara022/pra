#include<stdio.h>
#include<stdlib.h>


/*void MyPrintf(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

void heapify(int arr[], int size,int index)
{
	while (1)
	{
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		if (left >= size)
		{
			return;
		}
		int min = left;
		if (right < size && arr + right < arr + left)
			min = right;
		if (arr[min] >= arr[index])
				return;

		int tmp = arr[min];
		arr[min] = arr[index];
		arr[index] = tmp;
		index = min;
		}
	}
void creatHeap(int a[], int size) {
	for (int i = (size - 2) / 2; i >= 0; i--) 
	{
		heapify(a, size, i);
	}
}
typedef struct Heap {
	int arr[100];
	int size;
}	Heap;
void heapInit(Heap *heap,int arr[],int size)
{
	
	for (int i = 0; i < size; i++)
	{
		heap->arr[i] = arr[i];
	}
	heap->size = size;
	creatHeap(heap->arr, heap->size);
}
*/
// ʱ�临�Ӷ� O(log(n))
void heapify(int a[], int size, int index) {
	// ��ȷ�� index �ǲ���Ҷ�ӽ��
	// ���ж� index ��û�к���
	// index ��û������
	// index �����±��Ƿ�Խ��
	if (2 * index + 1 >= size) {
		// ��Ҷ�ӣ��Ѿ�����ѵ����ʣ����Ե�������
		return;
	}

	// �����Һ����н�С���ӵ��±�
	// �ȼ����С�ĺ���������
	// �Һ��Ӵ��ڲ����Һ��ӵ�ֵ С�� ���ӵ�ֵ
	int min = 2 * index + 1;
	if (2 * index + 2 < size && a[2 * index + 2] < a[2 * index + 1]) {
		min = 2 * index + 2;
	}

	// �Ƚ���С�ĺ��Ӻ� index ��ֵ
	if (a[index] <= a[min]) {
		// ����ֵ����С�ĺ��ӵ�ֵ��С���Ѿ�����ѵ�����
		// ���Ե�������
		return;
	}

	// ������С���Ӻ͸���ֵ
	int t = a[min];
	a[min] = a[index];
	a[index] = t;

	// �������� min ��λ��
	heapify(a, size, min);
}

// ʱ�临�Ӷ� O(n * log(n))
void createHeap(int a[], int size) {
	for (int i=(size - 1 - 1) / 2; i >= 0; i--) {
		heapify(a, size, i);
	}
}

typedef struct Heap {
	int array[100];
	int size;
}	Heap;

void HeapInit(Heap *heap, int a[], int size) {
	for (int i = 0; i < size; i++) {
		heap->array[i] = a[i];
	}
	heap->size = size;

	createHeap(heap->array, heap->size);
}

// ʱ�临�Ӷ� O(log(n))
void adjustUp(int a[], int index) {
	while (index > 0) {
		if (index == 0) {
			return;
		}

		int parent = (index - 1) / 2;
		if (a[parent] <= a[index]) {
			return;
		}

		int t = a[parent];
		a[parent] = a[index];
		a[index] = t;

		index = parent;
	}
}

void HeapPush(Heap *heap, int val) {
	heap->array[heap->size++] = val;
	adjustUp(heap->array, heap->size - 1);
}

void HeapPop(Heap *heap) {
	assert(heap->size > 0);
	heap->array[0] = heap->array[heap->size - 1];
	heap->size--;

	heapify(heap->array, heap->size, 0);
}

int HeapTop(Heap *heap) {
	assert(heap->size > 0);

	return heap->array[0];
}
void test()
{
	int arr[] = { 8,9,6,5,3,4 };
	Heap *h = NULL;
	heapInit(h,arr, sizeof(arr) / sizeof(arr[0]));
	MyPrintf(arr, sizeof(arr) / sizeof(arr[0]));
	system("pause");
}