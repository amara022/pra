#include"heap.h"
#include<stdlib.h>
void test()
{
	int arr[] = { 12, 36, 52, 61, 32, 85, 54, 16, 92 };
	Heap hp;
	InitHeap(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	TopK(&hp, 3,arr);
	MyPrintf(&hp);
	CreatHeap(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	MyPrintf(&hp);
// ����в���ֵΪdata��Ԫ�� 

	InsertHeap(&hp, 9);
	MyPrintf(&hp);
	// ɾ���Ѷ�Ԫ�� 
	EraseHeap(&hp);
	MyPrintf(&hp);
	// ��ȡ������ЧԪ�ظ��� 
	int c = SizeHeap(&hp);
	printf("%����Ϊ%d ", c);
	// �����Ƿ�Ϊ�� 
	EmptyHeap(&hp);

	// ��ȡ�Ѷ�Ԫ�� 
	TopHeap(&hp);


}
int main()
{
	test();
	system("pause");
}