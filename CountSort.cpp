#include "CountSort.h"
#include"Tool.h"
void CountSort(int * nums, int n)
{
	if (n <= 0) { return; }
	int max = nums[0];//最大的数字
	for (int i = 1; i < n; ++i)
	{
		if (nums[i] > max) { max = nums[i]; }
	}

	int* count = new int[max + 1]{};//全部初始化为0，大小为max+1(在默认情况下，new是不会对分配的int进行初始化的)
	for (int i = 0; i < n; ++i)
	{
		++count[nums[i]];
	}

	//后面的键值的位置是前面的所有的和
	for (int i = 1; i < max + 1; ++i)
	{
		count[i] += count[i - 1];
	}

	int* res = new int[n] {};
	//放入合适的地方
	for (int i = n - 1; i >= 0; --i)
	{
		res[--count[nums[i]]] = nums[i];//--count[nums[i]]是 nums[i]的最后一个位置
	}
	for (int i = 0; i < n; ++i)
	{
		nums[i] = res[i];
	}
	delete[] count;
	delete[] res;
}

void Test_CountSort()
{
	int n = 8;
	int nums[] = { 2,5,2,4,6,4,1,3 };
	std::cout << "before sorting: ";
	PrintArrayPoint(nums, n);
	CountSort(nums, n);
	std::cout << "after CountSort: ";
	PrintArrayPoint(nums, n);
}
