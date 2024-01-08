#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct ListNode {
     int val;
	 struct ListNode *next; };
//二维动态数组内存的开辟
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
	int a = 0, b = 0;
	int** arr = (int**)malloc(sizeof(int*) * numRows);
	*returnColumnSizes = malloc(sizeof(int) * numRows);
	for (a = 0; a < numRows; a++)
	{
		arr[a] = (int*)malloc(sizeof(int) * (a + 1));
		(*returnColumnSizes)[a] = a + 1;
		arr[0][0] = 1;
		for (b = 0; b < a + 1; b++)
		{
			if (b == 0)
				arr[a][b] = 1;
			else if (b < a && b != 0)
				arr[a][b] = arr[a - 1][b] + arr[a - 1][b - 1];
			else if (b == a)
				arr[a][b] = 1;
		}
	}
	*returnSize = numRows;
	return arr;
}
int main() {
	int arr[10] = { 1,2,4,232,45,22,32,3,5,3 };
	int a = b_search(arr, 10, 0, 9, 6);
	printf("%d", a);
	return 0;
}
//int compare(const void* e1,const void* e2)
//{
//	int* a = (int*)e1;
//	int* b = (int*)e2;
//	if (*a > *b)
//		return 1;
//	else if (*a < *b)
//		return -1;
//	return 0;
//}
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//	int a = m,b=0;
//	for (b = 0; b < n; b++)
//	{
//		nums1[a + b] = nums2[b];
//	}
//	qsort(nums1, m + n, sizeof(int), compare);
//}
//struct ListNode* delete(struct ListNode* list)
//{
//	struct ListNode* dl = list->next;
//	if (list->next->next)
//	{
//		list->next = list->next->next;
//	}
//	else
//		list->next = NULL;
//	free(dl);
//	return list;
//}
//struct ListNode* deleteDuplicates(struct ListNode* head) {
//	//struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* ret = head;
//	if (head == NULL)
//		return NULL;
//	while (head && head->next)
//	{
//		if (head->val == head->next->val)
//		{
//			head = delete(head);
//			continue;
//		}
//		head = head->next;
//	}
//	return ret;
//}
//int b_search(int* nums, int numsSize, int left, int right,int k)
//{
//	if (nums[left] == k)
//		return left;
//	else if (nums[right] == k)
//		return right;
//	while (left < right)
//	{
//		int mid = (left + right) / 2;
//		if (nums[mid] > k)
//			left = mid+1;
//		else if (nums[mid] < k)
//			right = mid;
//		else return mid;
//	}
//	return 0;
//}
//int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
//	int* arr = (int*)malloc(2 * sizeof(int));
//	int a = 0,b=0,c=0;
//	for (a = 0; a < numsSize; a++)
//	{
//		for (b = a + 1; b < numsSize; b++)
//		{
//			if (nums[a] + nums[b] == target)
//			{
//				arr[0] = a;
//				arr[1] = b;
//				returnSize = 2;
//				return arr;
//			}
//		}
//	}
//	return NULL;
//}
//int searchInsert(int* nums, int numsSize, int target) {
//	int a = 0, b = 0;
//	while (a < numsSize)
//	{
//		if (nums[a] == target)
//			return a;
//		else if (nums[a] > target)
//			return a;
//	}
//
//}
//int romanToInt(char* s) {
//	int a = 0, b = 0;
//	while (s[a])
//	{
//		if (s[a] == 'I')
//		{
//			if (s[a + 1] == 'V')
//			{
//				b += 4;
//				a++;
//			}
//			else if (s[a + 1] == 'X')
//			{
//				b += 9;
//				a++;
//			}
//			else
//				b += 1;
//		}
//		else if (s[a] == 'X')
//		{
//			if (s[a + 1] == 'L')
//			{
//				b += 40;
//				a++;
//			}
//			else if (s[a + 1] == 'C')
//			{
//				b += 90;
//				a++;
//			}
//			else
//				b += 10;
//		}
//		else if (s[a] == 'C')
//		{
//			if (s[a + 1] == 'D')
//			{
//				b += 400;
//				a++;
//			}
//			else if (s[a + 1] == 'M')
//			{
//				b += 900;
//				a++;
//			}
//			else
//				b += 100;
//		}
//		else if (s[a] == 'V')
//			b += 5;
//		else if (s[a] == 'L')
//			b += 50;
//		else if (s[a] == 'D')
//			b += 500;
//		else if (s[a] == 'M')
//			b += 1000;
//		a++;
//
//	}
//	return b;
//}
//int removeDuplicates(int* nums, int numsSize) {
//	int a = 0, b = 0,c=numsSize;
//	while (a < numsSize)
//	{
//		if (nums[b] != nums[a])
//		{
//			nums[b++] = nums[a];
//			c--;
//		}
//		a++;
//	}
//	return c;
//}
//typedef unsigned char byte;
//typedef unsigned short word;
	//byte b  = UINT_MAX;
	//word w = UINT_MAX;
	//unsigned int i = UINT_MAX;
	//unsigned long l  = UINT_MAX;
	//printf("Maxmum byte is %X , %u\n", b, b);
	//printf("Maxmum word is %X , %u\n", w, w);
	//printf("Maxmum int is %X , %u\n", i, i);
	//printf("Maxmum long is %X , %u\n", l, l);
