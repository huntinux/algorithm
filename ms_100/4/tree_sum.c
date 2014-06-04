struct BinaryTreeNode // a node in the binary tree
{
	int m_nValue; // value of node
	BinaryTreeNode *m_pLeft; // left child of node
	BinaryTreeNode *m_pRight; // right child of node
};

// 树的最大深度
#define MAX_DEPTH 128
int path[MAX_DEPTH];

// 打印路径
void
print(int path[], int top)
{
	while(top>=0){
		printf("%d ", path[top--]);
	}
}

// 求满足的路径
void
print_path(struct BinaryTreeNode *root, int sum, int path[], int top)
{
	path[top++] = root->m_nValue; // 当前节点值入栈，这里用一个数组模拟栈
	sum -= root->m_nValue; // sum减去当前节点的值

	if(root->m_pLeft == NULL && root->m_pRight == NULL){ // 叶子节点，判断磁条路径‘和’是否满足
		if(sum == 0){ // 满足，则打印出来
			print(path, top);
		}
	}else{
		print_path(root->m_pLeft , sum, path, top); // 遍历左子树
		print_path(root->m_pRight, sum, path, top); // 遍历右子树
	}

	top--; // 本条路径检测完后，退栈
	sum += root->m_nValue; // 恢复sum
}

/*
 * 发现print_path和遍历树的算法很像，只是加上了一些额外的”控制“
 * 所以可以把遍历树的代码作为框架，然后在框架上做修改。
 *
 *
 */
