#include<stdio.h>
#include <stdlib.h>

// 将相邻的正数和负数合并成一个数
void merge(int arr[], int num)
{
	int i, n, m, m_index;
	int begin;

	if(num <= 1)
		return ;

	begin = 1;
	i = 0;
	while(i < num - 1){
		if(begin){ // 只在一段开始的时候执行
			m = arr[i]; // 开始元素
			m_index = i; // 开始元素下标
			begin = 0; // 清空开始标志
		}
		
		i++; // 移动到下一个元素
		n = arr[i];
		if(m * n > 0){ // m和n同号 , 如果有0怎么办?? 同样可以处理！！
			m += n;	 // 合并
			arr[i] = 0; // 先不将后面的元素移动到前面，先把被合并的变成0，因为加上0没有影响，所以可以不移动。
		}else{
			begin = 1;	// 设置开始标志
			arr[m_index] = m; // 将最大值写到数组中
		}
	}

}

// arr : 正负相间的数组
// return :最大的子序列之和
int max_sum(int arr[], int num)
{
	int max, pre_max, begin, i;
	int m, n;

	begin = 1;
	//for(i = 0; i < num; i++){
	i = 0;
	while(i < num){
		if(arr[i] == 0) // 0直接忽略就好
			continue;
		if(i == 0 && arr[0] < 0){ // 第一个是负数，直接忽略
			continue;
		}

		if(begin){
			m = arr[i];
			max = m;
			begin = 0;
		}

		i++;
		if(m + n > 0){
			m = m + n;
		}else{
			i++;
			begin = 1;
			pre_max = (max > m)? max: m;
		}
	}

	return max;
}


// 贪心算法
int maxSubarray(int a[], int size) {
	if (size<=0) {
		perror("error array size");
		exit(EXIT_FAILURE);
	}

	int sum = 0;
	//int max = - (1 << 31); // 先设置成最小的int
	int max = - (1 << (sizeof(int)*8-1)); // 先设置成最小的int
	int cur = 0;
	while (cur < size) {
		sum += a[cur++];
		if (sum > max) {
			max = sum;
		} else if (sum < 0) {
			sum = 0;
		}
	}
	return max;
}

void print_arr(int arr[], int num)
{
	int i; 

	for(i = 0; i < num; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{

	int arr[] = {1, -2, 3, 10, -4, 7, 2, -5 };
	int num = sizeof(arr)/sizeof(int);

	//merge(arr, num);
	//print_arr(arr, num);
	//printf("%d\n", max_sum(arr, sizeof(arr)/sizeof(int)));
	printf("%d\n", maxSubarray(arr, sizeof(arr)/sizeof(int)));


	return 0;
}
