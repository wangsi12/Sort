#include"Tool.h"
#include"BubbleSort.h"
//冒泡排序
void BubbleSort(int* nums, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (nums[j] > nums[j + 1])
			{
				Swap(nums[j], nums[j + 1]);
			}
		}
	}
}

//模板实现冒泡排序
template<typename T>
void BubbleSortTemplate(T* nums, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (nums[j] > nums[j + 1])
			{
				Swap(nums[j], nums[j + 1]);
			}
		}
	}
}

//改进版冒泡排序，在每次检查是否有序，如果有序，则不再判断
void BubbleSortNew(int* nums, int n)
{
	bool is_orderly = false;
	for (int i = 0; i < n - 1 && is_orderly == false; ++i)
	{
		is_orderly = true;
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (nums[j] > nums[j + 1])
			{
				is_orderly = false;
				Swap(nums[j], nums[j + 1]);
			}

		}
	}
}

void test_BubbleSort()
{
	int n = 8;
	int nums[] = { 2,5,2,4,6,4,1,3 };
	int nums1[] = { 2,5,2,4,6,4,1,3 };
	int nums2[] = { 2,5,2,4,6,4,1,3 };
	std::cout << "before sorting: ";
	PrintArrayPoint(nums, n);

	BubbleSort(nums, n);
	std::cout << "after BubbleSort: ";
	PrintArrayPoint(nums, n);

	BubbleSortTemplate(nums1, n);
	std::cout << "after BubbleSortTemplate: ";
	PrintArrayPoint(nums1, n);

	BubbleSortNew(nums2, n);
	std::cout << "after BubbleSortNew: ";
	PrintArrayPoint(nums2, n);
}

