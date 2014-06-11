
// 递归，类似先序遍历
void mirror(tree *root)
{
	if(root == NULL)
		return;

	// mirror left and right
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	// mirrot left and right
	mirror(root->left);
	mirror(root->right);
}

// 循环
void mirr(tree *root)
{
	stack s;

	if(root == NULL)
		return ;

	s.push(root);

	while(!s.empty()){

		// mirror
		tmp = root->left;
		root->left = root->right;
		root->right = tmp;

		if(root->right)
			push(root->right);
		if(root->left)
			push(root->left);
	}

}



/////////////////////////参考代码
//

void swap(Node ** l, Node ** r) { // 注意这里对指针的交换
	Node * p = *l;
	*l = *r;
	*r = p;
}
void mirror(Node * root) {
	if (root == NULL) return;
	swap(&(root->left), &(root->right));
	mirror(root->left);
	mirror(root->right);
}
void mirrorIteratively(Node * root) {
	if (root == NULL) return;
	stack<Node*> buf;
	buf.push(root);
	while (!stack.empty()) {
		Node * n = stack.pop();
		swap(&(root->left), &(root->right));
		if (root->left != NULL) buf.push(root->left);
		if (root->right != NULL) buf.push(root->right);
	}
}


