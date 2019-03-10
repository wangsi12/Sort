#include "MergeSort.h"
#include"Tool.h"
#include<stack>
#include<algorithm>
//�ݹ�
void MergeSortRecursive(int * nums, int* temp, int start, int end)
{
	if (start >= end) { return; }
	int length = end - start;
	int start1 = start, end1 = (length >> 1) + start;
	int start2 = end1 + 1, end2 = end;

	//�ֱ�����
	MergeSortRecursive(nums, temp, start1, end1);
	MergeSortRecursive(nums, temp, start2, end2);

	int k = start;
	//�ϲ�
	while (start1 <= end1 && start2 <= end2)
	{
		temp[k++] = nums[start1] < nums[start2] ? nums[start1++] : nums[start2++];
	}
	while (start1 <= end1)
	{
		temp[k++] = nums[start1++];
	}
	while (start2 <= end2)
	{
		temp[k++] = nums[start2++];
	}

	for (k = start; k < end; ++k)
	{
		nums[k] = temp[k];
	}
}
void MergeSort(int * nums, int n)
{
	int* temp = new int[n];
	MergeSortRecursive(nums, temp, 0, n - 1);
	delete[] temp;
}

//����
void MergeSort1(int * nums, int n)
{
	int* a = nums;
	int* b = new int[n];
	for (int i = 1; i < n; i *= 2)//ÿ�����еĳ���
	{
		for (int start = 0; start < n; start += 2 * i)//�ϲ����ڵ���������
		{
			int k = start;
			int start1 = start, end1 = std::min((start + i), n);
			int start2 = end1, end2 = std::min((start + i + i), n);
			while (start1 < end1&&start2 < end2)
			{
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			}
			while (start1 < end1)
			{
				b[k++] = a[start1++];
			}
			while (start2 < end2)
			{
				b[k++] = a[start2++];
			}
		}
		
		int* temp = a;
		a = b;
		b = temp;
	}

	//���յ�nums���ܺ�aָ��ͬһ������Ҳ���ܺ�bָ��ͬһ������
	//���յĽ��һ����aָ������飬���b==nums�Ļ���a��=nums��,Ҫ��a,b����
	if (a != nums)		
	{
		for (int i = 0; i < n; ++i)
		{
			b[i] = a[i];
		}
		b = a;
	}
	delete[] b; 
}


void Test_MergeSort()
{
	int n = 8;
	int nums[] = { 2,5,2,4,6,4,1,3 };
	int nums1[] = { 2,5,2,4,6,4,1,3 };
	std::cout << "before sorting: ";
	PrintArrayPoint(nums, n);
	MergeSort(nums, n);
	std::cout << "after MergeSort: ";
	PrintArrayPoint(nums, n);

	std::cout << "before sorting: ";
	PrintArrayPoint(nums1, n);
	MergeSort1(nums1, n);
	std::cout << "after MergeSort1: ";
	PrintArrayPoint(nums1, n);
}
