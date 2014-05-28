题目：
```
定义栈的数据结构,要求添加一个 min 函数,能够得到栈的最小元素。
要求函数 min、push 以及 pop 的时间复杂度都是 O(1)
```


分析
========
```
给每个节点增加一个域min，它的值是它下面的节点中最小的value

struct node{
	int value;
	int min;
}

struct node stack[maxSize];

栈的样子： node3是栈顶部 

node3 
	value=1 
	min=1
node2
	value=3
	min=2
node1
	value=2
	min=2

所以要着最小值，则直接输出栈顶的min域即可。
```
