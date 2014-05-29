#include<stdio.h>


int max_sum(int arr[], int num)
{
	int max, pre_max;
	int i;

	max = pre_max = 0;
	for(i = 0; i < num; i++){
		if(arr[i] > 0){
			max += arr[i];
		}else{
			max = (max > pre_max) ? max : pre_max;
			pre_max = max;
		}	
	}

	return max;
}

int main()
{

	int arr[] = {1, -2, 3, 10, -4, 7, 2, -5 };

	printf("%d\n", max_sum(arr, sizeof(arr)/sizeof(int)));


	return 0;
}
