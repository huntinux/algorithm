#include <stdio.h>

// 判断数组a中是否存在两个数的和等于dest
// a : 升序数组
// len ： 数组长
// dest：要查找的和
void find(int a[], int len, int dest)
{
	int *p, *q;
	int sum;

	p = a;
	q = a + len - 1;

	sum = *p + *q;
	while(sum != dest && p < q){
		if(sum > dest){
			q--;
		}else{
			p++;
		}
		sum = *p + *q;
	}

	if(sum == dest) // 因为上面while循环的推出原因有两个：1.sum ==dest 2. p >= q. 所以这里要判断！！
		printf("%d %d", *p, *q);

}

int a[] = {1, 3, 4, 7, 8, 11, 15};

int main()
{
	//find(a, sizeof(a)/sizeof(int), 115);
	find(a, sizeof(a)/sizeof(int), 15);

	return 0;
}
