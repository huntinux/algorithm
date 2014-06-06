#include <stdio.h>

int arr[] = {5,7,6,9,11,10,8};
//int arr[] = {7,4,6,6};
//int arr[] = {7,4,6,5};

int
helper(int arr[], int begin_index, int end_index, int root)
{
	int bigger_index, i;

	if(begin_index >= end_index)
		return 1;

	bigger_index = begin_index;

	// 找到第一个大于root的数
	while(arr[bigger_index] < root && bigger_index < end_index)
		bigger_index++;

	//if(bigger_index == end_index) // 没找到比root大的
	//	return 1;

	// 检查从bigger_index 到 end_index有没有比root小的数字
	for(i = bigger_index; i < end_index; i++){
		if(arr[i] < root)
			return 0;
	}

	// 判断左边
	if (helper(arr, 0, bigger_index - 1, arr[bigger_index]) == 0 )
		return 0;

	// 判断右边
	if (helper(arr, bigger_index + 1, end_index, arr[end_index]) == 0 )
		return 0;

	return 1;
}


int 
test(int arr[], int n)
{
	return helper(arr, 0, n-2, arr[n-1]);
}


int main()
{
	printf("%d\n",test(arr, sizeof(arr)/sizeof(int)));
}

