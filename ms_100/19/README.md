# Problem
```
题目:定义 Fibonacci 数列如下:
	/ 0 n=0
f(n)= 1 n=1
	\ f(n-1)+f(n-2) n=2
输入 n,用最快的方法求该数列的第 n 项。
```

# Analysis
```
第1项：	0
2 		1
3 		1
4 		2
5 		3
6 		5
...

已知f(0) = 0, f(1) = 1, 求第n项目，即求 f(n-1)
又有 f(n-1)+f(n-2) (n>=2)

可以从第1项开始，利用公式求的第n项

tmp = 0
a = 0
b = 1
result = 0
index = 1
while index <= n - 2
	tmp = b
	b = a + b	
	a = tmp

	index ++

result = b
```

# Other method
```
好吧，看了这个解法，数学知识又增加了
参考： http://xingyunbaijunwei.blog.163.com/blog/static/7653806720123168573103/
|f(n) 	f(n-1)|		|1 	1| ^ (n-1)
| 			  |	=	|	 | 
|f(n-1)	f(n-2)|		|1 	0|

两边都是矩阵
f(n) 就是右边表达式第一行第一列的元素值


```


