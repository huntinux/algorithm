我的思考
========
```
假设节点A有两个指针域
lchild 
rchild
因为要改成双链表所以有如下约定
lchild: prev
rchild: next

那么对于任意一个节点A，指针修改规则是：
lchild: 如果左子树不为空，指向左子树中最大的一个节点; 如果左子树为空，则指向NULL
rchild: 如果右子树不为空，指向右子树中最小的一个节点; 如果右子树为空，则指向NULL


怎么找左子树最大的节点呢？
左子树最右边的节点就是

p = A; // A是当前节点
while(p->rchild)
	p = p->rchild;
// 这里p就指向A的左子树中的最大节点

同理可以找到右子树最小节点。


怎么完成所有节点指针的修改？
很自然想到递归。关于树的问题，貌似递归很管用。
对A进行修改指针的操作，然后对左右子树执行相同的过程。
```

参考答案
========
```
参考答案更加简洁。
对于一个节点A，让A.prev指向左树的tail; A.next指向右子树的head。
这样不必每次都循环查找左子树的最大节点和右子树的最小节点。
因为在改变A的指针域之前，左右子树已经确定了tail和head。
```




