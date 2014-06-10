# Problem
```
题目:求 1+2+...+n,
要求不能使用乘除法、for、while、if、else、switch、case 等关键字以及条件判断语句 (A?B:C)
```

# 分析
```
(1+2+...+n)
=(n*(n+1))/2
=(n*n+n)/2

其中乘法和除法需要消除掉
n/2 --> n右移1位
n*n --> n个n相加 (关键问题)

不能用循环, 怎么求n*n
法1：递归
n*n = fun(n,n)
int fun(int n, int m)
{
	//if(m == 1)
	//		return n;
	(m==1)&&return 0;

	return n+fun(n, m-1)

}

但是if不让用啊！！！
别忘了，条件语句的短路规则short pass，可以模拟if，else

不过，使用递归容易栈溢出啊。


```


# 参考答案
```
ANSWER:
1+..+n=n*(n+1)/2=(n^2+n)/2
it is easy to get x/2, so the problem is to get n^2
though no if/else is allowed, we can easilly go around using short-pass.
using macro to make it fancier:

#define T(X, Y, i) (Y & (1<<i)) && X+=(Y<<i)
int foo(int n){
	int r=n;
	T(r, n, 0); T(r, n,1); T(r, n, 2); ... T(r, n, 31); // 但是int一定就是32位吗？
	return r >> 1;
}

上面的宏的解释：
例子：3 * 3
3的2进制 11
上面的宏是判断如果某一位为1，那么就加上该位的权
那么计算过程是： 3 + 2^0*3 + 2^1*3 = 9
```

