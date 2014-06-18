# Problem
```
题目:n 个数字(0,1,...,n-1)形成一个圆圈,从数字 0 开始,
每次从这个圆圈中删除第 m 个数字(第一个为当前数字本身,第二个为当前数字的下一个数字)
当一个数字删除后,从被删除数字的下一个继续删除第 m 个数字。
求出在这个圆圈中剩下的最后一个数字。
```


# 分析
```
第一想法是一个while循环。终止条件是只剩一个数字。
伪码表示：

cur_index = 0 
while num_count > 1
	delete the num whith index: del_index = cur_index + m - 1	
	cur_index = del_index + 1


但是，我还是太年轻了。。。
其实可以通过数学推倒出规律的。
数学推倒：http://www.cnblogs.com/EricYang/archive/2009/09/04/1560478.html 

```

# 动态规划
```
n 个数字(0,1,...,n-1)形成一个圆圈,从数字 0 开始
```

# 什么是动态规划？
http://www.cnblogs.com/kkgreen/archive/2011/06/26/2090702.html

# 总结
将一个大问题，转换成一个较小的问题。
