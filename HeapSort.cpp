#include "HeapSort.h"
#include"Tool.h"

//���ѣ������ļ�ֵ�����жѽ���ֵ������ߣ���ÿ������ֵ�����亢�ӵ�ֵ��
//��С�ѣ������ļ�ֵ�����жѽ���ֵ����С�ߣ���ÿ������ֵ�����亢�ӵ�ֵС
void MaxHeap(int* nums, int start, int end)
{
	int dad = start;
	int son = dad * 2 + 1;
	while (son < end)
	{
		//�ҵ������ӽڵ��бȽϴ��
		if (son < end - 1 && nums[son] < nums[son + 1])
		{
			++son;
		}

		//����ӽڵ��д�ıȸ��ڵ㻹�󣬾���Ҫ������Ȼ������С����һֱ�³�
		if (nums[son] > nums[dad])
		{
			Swap(nums[dad], nums[son]);
			dad = son;
			son = dad * 2 + 1;
		}
		else
		{//��ʾ�����Ѿ��������
			return;
		}
	}
}

// �����򣺣����ѣ������������ӶѶ��Ѹ�ж��������������֮ǰ���ٻָ���
void HeapSort(int * nums, int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		MaxHeap(nums, i, n - 1);
	}

	for (int i = n - 1; i > 0; --i)
	{
		Swap(nums[i], nums[0]);
		MaxHeap(nums, 0, i - 1);
	}
}

void Test_HeapSort()
{
	int n = 8;
	int nums[] = { 2,5,2,4,6,4,1,3 };
	std::cout << "before sorting: ";
	PrintArrayPoint(nums, n);
	HeapSort(nums, n);
	std::cout << "after HeapSort: ";
	PrintArrayPoint(nums, n);
}
