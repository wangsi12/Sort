#include<iostream>
#include"BubbleSort.h"
#include"SelectionSort.h"
#include"InsertSort.h"
#include"QuickSort.h"
#include"HeapSort.h"
#include"MergeSort.h"
#include"shell_sort.h"
#include"CountSort.h"
#include"BucketSort.h"
using namespace std;

int main()
{
	test_BubbleSort();
	std::cout << std::endl;

	test_SelectionSort();
	std::cout << std::endl;

	Test_InsertSort();
	std::cout << std::endl;

	Test_QuickSort();
	std::cout << std::endl;

	Test_HeapSort();
	std::cout << std::endl;

	Test_MergeSort();
	std::cout << std::endl;

	Test_ShellSort();
	std::cout << std::endl;

	Test_CountSort();
	std::cout << std::endl;

	Test_BucketSort();
	std::cout << std::endl;
	
	getchar();
	return 0;
}