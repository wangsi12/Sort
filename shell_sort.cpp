#include "shell_sort.h"
#include"Tool.h"
void ShellSort(int * nums, int n)
{
	int h = 1;
	while (h < n / 3) { h = h * 3 + 1; }
	while (h >= 1)
	{
		for (int i = h; i < n; ++i)
		{
			for (int j = i; j >= h; j -= h)
			{
				if (nums[j] < nums[j - h])
				{
					Swap(nums[j], nums[j - h]);
				}
			}
		}

		h = h / 3;
	}
	
}

void Test_ShellSort()
{
	int n = 8;
	int nums[] = { 2,5,2,4,6,4,1,3 };
	int nums1[] = { 2,5,2,4,6,4,1,3 };
	std::cout << "before sorting: ";
	PrintArrayPoint(nums, n);
	ShellSort(nums, n);
	std::cout << "after ShellSort: ";
	PrintArrayPoint(nums, n);
}
