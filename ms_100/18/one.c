




//int find(int n, int m)
//{
//	int *arr = NULL, *p, *q;;
//	int i, len = n;
//	int cur_index, del_index;
//
//	// 分配数组，并初始化
//	arr = (int *)malloc(n * sizeof(int));
//	memset(arr, 0, n*sizeof(int));
//	for(i = 0, p = arr, q = arr + n; p < q; p++){
//		*p = i++;
//	}
//
//	//
//	cur_index = 0;
//	while(len>1){
//		del_index = cur_index + m - 1;
//		*(arr+del_index) = 
//
//
//	}
//
//
//
//
//}
//
//
//




//数学推倒：http://www.cnblogs.com/EricYang/archive/2009/09/04/1560478.html 
int joseph(int n, int m) {
	int fn=0;
	for (int i=2; i<=n; i++) {
		fn = (fn+m)%i;
	}
	return fn;
}
