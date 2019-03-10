#include "HeapSort.h"
#include"Tool.h"

//最大堆：根结点的键值是所有堆结点键值中最大者，且每个结点的值都比其孩子的值大
//最小堆：根结点的键值是所有堆结点键值中最小者，且每个结点的值都比其孩子的值小
void MaxHeap(int* nums, int start, int end)
{
	int dad = start;
	int son = dad * 2 + 1;
	while (son < end)
	{
		//找到两个子节点中比较大的
		if (son < end - 1 && nums[son] < nums[son + 1])
		{
			++son;
		}

		//如果子节点中大的比根节点还大，就需要交换，然后把这个小的数一直下沉
		if (nums[son] > nums[dad])
		{
			Swap(nums[dad], nums[son]);
			dad = son;
			son = dad * 2 + 1;
		}
		else
		{//表示子树已经调整完毕
			return;
		}
	}
}

// 堆排序：（最大堆，有序区）。从堆顶把根卸出来放在有序区之前，再恢复堆
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
