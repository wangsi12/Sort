#include"Tool.h"
//交换
void Swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

//打印数组
void PrintArrayPoint(int* nums, int n)
{
	for (int i = 0; i < n; ++i)
		std::cout << nums[i] << " ";
	std::cout << std::endl;
}

