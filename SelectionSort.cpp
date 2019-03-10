#include"Tool.h"
#include"SelectionSort.h"
void SelectionSort(int* nums, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (nums[j] < nums[min])
			{
				min = j;
			}
		}
		if (i != min)
			Swap(nums[i], nums[min]);
	}
}

template<typename T>
void SelectionSortTemplate(T* nums, int n)
{
	for (int i = 0; i < n; ++i)
	{
		T min = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (nums[j] < nums[min])
				min = j;
		}
		if (min != i)
			Swap(nums[min], nums[i]);
	}
}

void test_SelectionSort()
{
	int n = 8;
	int nums[] = { 2,5,2,4,6,4,1,3 };
	int nums1[] = { 2,5,2,4,6,4,1,3 };
	std::cout << "before sorting: ";
	PrintArrayPoint(nums, n);

	SelectionSort(nums, n);
	std::cout << "after SelectionSort: ";
	PrintArrayPoint(nums, n);

	SelectionSortTemplate(nums1, n);
	std::cout << "after SelectionSortTemplate: ";
	PrintArrayPoint(nums1, n);
}

