#include "InsertSort.h"
#include"Tool.h"
void InsertSort(int * nums, int n)
{
	for (int i = 1; i < n; ++i)
	{
		int temp = nums[i];//因为nums[i]很可能会换掉，所以一定要提前保存
		for (int j = i - 1; j >= 0; --j)
		{
			if (temp < nums[j])
			{
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
			else
			{
				break;
			}
		}
	}
}

void Test_InsertSort()
{
	int n = 8;
	int nums[] = { 2,5,2,4,6,4,1,3 };
	std::cout << "before sorting: ";
	PrintArrayPoint(nums, n);

	InsertSort(nums, n);
	std::cout << "after SelectionSort: ";
	PrintArrayPoint(nums, n);
}