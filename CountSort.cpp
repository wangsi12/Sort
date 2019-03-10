#include "CountSort.h"
#include"Tool.h"
void CountSort(int * nums, int n)
{
	if (n <= 0) { return; }
	int max = nums[0];//��������
	for (int i = 1; i < n; ++i)
	{
		if (nums[i] > max) { max = nums[i]; }
	}

	int* count = new int[max + 1]{};//ȫ����ʼ��Ϊ0����СΪmax+1(��Ĭ������£�new�ǲ���Է����int���г�ʼ����)
	for (int i = 0; i < n; ++i)
	{
		++count[nums[i]];
	}

	//����ļ�ֵ��λ����ǰ������еĺ�
	for (int i = 1; i < max + 1; ++i)
	{
		count[i] += count[i - 1];
	}

	int* res = new int[n] {};
	//������ʵĵط�
	for (int i = n - 1; i >= 0; --i)
	{
		res[--count[nums[i]]] = nums[i];//--count[nums[i]]�� nums[i]�����һ��λ��
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
