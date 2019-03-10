#include "QuickSort.h"
#include"Tool.h"
#include<stack>

//递归，基准为第一个数
void QuickSort(int* nums, int low, int high)
{
	if (low >= high) { return; }

	int key = nums[low], first = low, last = high;
	//把比key小的数放到左边，大的数放到右边
	while (first < last)
	{
		//先找大数
		while (first < last&&nums[last] >= key)
		{
			--last;
		}
		if (first < last)
		{
			nums[first++] = nums[last];
		}

		//再找小数
		while (first < last&&nums[first] <= key)
		{
			++first;
		}
		if (first < last)
		{
			nums[last--] = nums[first];
		}
	}
	nums[first] = key;
	QuickSort(nums, low, first - 1);//左侧递归
	QuickSort(nums, first + 1, high);//右侧递归
}

//模板实现，递归
template<typename T>
void QuickSortTemplate(T * nums, int low, int high)
{
	if (low >= high) { return; }

	T key = nums[low];
	int first = low, last = high;
	while (first < last)
	{
		while (first < last&&nums[last] >= key)
		{
			--last;
		}
		if (first < last) { nums[first++] = nums[last]; }

		while (first < last&&nums[first] <= key)
		{
			++first;
		}
		if (first < last) { nums[last--] = nums[first]; }
	}
	nums[first] = key;
	QuickSortTemplate(nums, low, first - 1);
	QuickSortTemplate(nums, first + 1, high);
}

//迭代，用栈
struct Range
{
	int start, end;
	Range(int start = 0, int end = 0) :start(start), end(end) {}
};
typedef Range range;

template<typename T>
void QuickSortTemplate1(T * nums, int n)
{
	if (n <= 0) { return; }

	std::stack<range> stack_range;
	stack_range.push(range(0, n - 1));
	while (!stack_range.empty())
	{
		range r = stack_range.top();
		stack_range.pop();
		if (r.start >= r.end) { continue; }
		T key = nums[r.start];
		int first = r.start, last = r.end;
		while (first < last)
		{
			while (first < last&&nums[last] >= key) { --last; }
			if (first < last) {
				nums[first++] = nums[last];
			}

			while (first < last&&nums[first] <= key) { ++first; }
			if (first < last) {
				nums[last--] = nums[first];
			}
		}
		nums[first] = key;
		stack_range.push(range(r.start, first - 1));
		stack_range.push(range(first + 1, r.end));
	}
}


void Test_QuickSort()
{
	int n = 8;
	int nums[] = { 2,5,2,4,6,4,1,3 };
	int nums1[] = { 2,5,2,4,6,4,1,3 };
	int nums2[] = { 2,5,2,4,6,4,1,3 };
	std::cout << "before sorting: ";
	PrintArrayPoint(nums, n);
	QuickSort(nums, 0, n - 1);
	std::cout << "after QuickSort: ";
	PrintArrayPoint(nums, n);

	std::cout << "before sorting: ";
	PrintArrayPoint(nums1, n);
	QuickSortTemplate(nums1, 0, n - 1);
	std::cout << "after QuickSortTemplate: ";
	PrintArrayPoint(nums1, n);

	std::cout << "before sorting: ";
	PrintArrayPoint(nums2, n);
	QuickSortTemplate1(nums2, n);
	std::cout << "after QuickSortTemplate1: ";
	PrintArrayPoint(nums2, n);
}