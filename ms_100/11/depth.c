// 一些基础算法
// 求一个二叉树的高度
int
depth(node *root)
{
	int left, right, dep;

	//if(root->left==NULL && root->right == NULL) 
	if(root==NULL)
		return -1;
		//return 0;

	left  = depth(root->left);
	right = depth(root->right);

	dep = ((left > right) ? left : right) + 1;

	return dep;
}


// 左右子树高度之和
int
depth_lr_sum(node *root)
{
	int left, right;

	if(root==NULL)
		return -1;

	left  = depth(root->left) + 1;
	right = depth(root->right) + 1;

	return left > right ? left : right;	
	//return left + right;	
}

// 在上面的基础上,修改
// 得到我的解法
int
get_max(node *root, int &max_dep)
{
	int left, right;

	if(root==NULL)
		return -1;

	left  = depth(root->left, max_dep) + 1;
	right = depth(root->right, max_dep) + 1;

	cur_max_dep = left + right;

	if(cur_max_dep > max_dep)
		max_dep = cur_max_dep; // 更新max_dep

	return left > right ? left : right;	
}

int helper(node *root)
{
	int max = 0;
	get_max(root, max);
	return max;
}



/////////////////////////
// 参考答案
int maxDistance(Node * root) {
	int depth;
	return helper(root, depth);
}
int helper(Node * root, int &depth) { // 使用引用，带回值
	if (root == NULL) {
		depth = 0; return 0;
	}
	int ld, rd;
	int maxleft = helper(root->left, ld); // 求左边高度
	int maxright = helper(root->right, rd); // 求右边高度
	depth = max(ld, rd)+1; // 深度
	return max(maxleft, max(maxright, ld+rd)); // 
}





/// 令一个解法
// http://www.cppblog.com/flyinghearts/archive/2010/08/16/123543.html
// 和我的思路一样
int find(node * root, int &max_dep)
{
	int left, right, tmp_max_dep;

	if(root == NULL)
		return -1;

	left  = find(root->left, max_dep) + 1; // 返回值来自先面的return, 得到左子树的高度
	right = find(root->right, max_dep) + 1;

	tmp_max_dep = left + right; // 当前节点的左右子树之和

	if(max_dep < tmp_max_dep) // 如果找到更大的则，更新一下max_dep
		max_dep = tmp_max_dep;
	
	return left>right?left:right;
}

int help(node *root)
{
	int max = 0;
	find(root, max); // 引用，可以带回值
	return max;
}
