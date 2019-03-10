#include "BucketSort.h"
#include"Tool.h"
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(NULL) {}
};

void BucketSort(int * nums, int n)
{
	if (n <= 1) { return; }

	//先把所有的数据都分到各个桶中
	int bucket_num = 10;
	ListNode** bucket = new ListNode*[bucket_num] {};
	for (int i = 0; i < n; ++i)
	{
		int index = nums[i] % bucket_num;
		ListNode* index_bucket_head = bucket[index];

	}

	delete[] bucket;
}

void Test_BucketSort()
{
	int n = 8;
	int nums[] = { 2,5,2,4,6,4,1,3 };
	std::cout << "before sorting: ";
	PrintArrayPoint(nums, n);
	BucketSort(nums, n);
	std::cout << "after BucketSort: ";
	PrintArrayPoint(nums, n);
}
