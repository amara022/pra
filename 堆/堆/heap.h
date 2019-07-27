#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<string.h>



typedef int DataType;
typedef struct Heap
{
	DataType* _array;
	int _capacity;
	int _size;
}Heap;
void MyPrintf(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}
void InitHeap(Heap *hp, int *array, int size)
{
	assert(hp);
	hp->_size = size;
	hp->_capacity = 9;
	hp->_array = (DataType *)malloc(hp->_capacity*sizeof(DataType));
	if (hp->_array == NULL)
	{
		assert(0);
		return;
	}
	//��array��size*sizeof(HDataType)���ֽڿ�����hp->data
	memcpy(hp->_array, array, size*sizeof(DataType));
}

void swap(DataType *x, DataType *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
//���µ���
void AdjustDown(Heap *hp, int parent)
{
	//���i������Ϊ��2*i+1
	int child = (parent << 1) + 1;
	while (child < hp->_size)
	{
		//�ȱ�֤���Һ���,Ȼ���ȡ����ӵ���Сֵ
		if (child + 1 < hp->_size && hp->_array[child] > hp->_array[child + 1])
		{
			child = child + 1;
		}
		//����ӵ���Сֵ��˫�ױȽϣ���˫�״��������Һ��ӵ���Сֵ����
		if (hp->_array[parent] > hp->_array[child])
		{
			//����
			swap(&hp->_array[child], &hp->_array[parent]);
			parent = child;
			child = (parent << 1) + 1;
		}
		else
		{
			return;
		}
	}
}
//������
void CreatHeap(Heap *hp, int *array, int size)
{
	//�ӵ�һ����Ҷ�ӽ�㿪ʼ����
	//���i��˫��Ϊ�� i-1/2��
	int root = (size - 2) >> 1;
	for (root; root >= 0; root--)
	{
		//���µ���
		AdjustDown(hp, root);
	}
}

// ����в���ֵΪdata��Ԫ�� 
void CheakHeap(Heap* hp)
{
	int newcapacity = 0;
	DataType* new = NULL;
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		newcapacity = hp->_capacity * 2;
		new = (DataType*)realloc(hp->_array, newcapacity*sizeof(DataType));
		if (new == NULL)
		{
			assert(0);
			return;
		}
		hp->_capacity = newcapacity;
		hp->_array = new;
	}

}
void AdjustUp(Heap* hp, int index)
{
	while (index > 0)
	{
		if (index == 0)
			return;
		int parent = (index -1)/2;
		if (hp->_array[parent] > hp->_array[index])
			return;
		swap(&hp->_array[parent], &hp->_array[index]);
		index = parent;
	}
}
void InsertHeap(Heap* hp, DataType data)
{
	assert(hp);
	int root = 0;
	CheakHeap(hp);
	hp->_array[hp->_size++] = data;
	root = (hp->_size / 2) - 1;
	AdjustUp(hp, root);
}

// ɾ���Ѷ�Ԫ�� 
void EraseHeap(Heap* hp)
{
	assert(hp);
	swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp, 0);
}

// ��ȡ������ЧԪ�ظ��� 
int SizeHeap(Heap* hp)
{
	int count = 0;
	for (int i = 0; i < hp->_size; i++)
		count++;
	return count;
}

// �����Ƿ�Ϊ�� 
int EmptyHeap(Heap* hp)
{
	if (hp->_size == 0)
		return 0;
	else
		return 1;
}

// ��ȡ�Ѷ�Ԫ�� 
DataType TopHeap(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}

// ���ٶ� 
void DestroyHeap(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_capacity = 0;
	hp->_size = 0;
}

DataType TopK(Heap* hp,int k,int arr[])
{
	for (int i = 0; i < k; i++)
	{
		arr[i] = hp->_array[i];
	}
	CreatHeap(&hp,arr,k);
	for (int i = k; i < hp->_size; i++)
	{
		if (hp->_array[i]>hp->_array[k])
		{
			swap(hp->_array[i], hp->_array[k]);
			AdjustDown(&hp, k);
		}
	}

}