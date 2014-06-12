// 按照层次遍历树
// 借助队列 FIFO 的性质


void level_travel(tree *root)
{
	if(root == NULL)
		return ;

	q.inqueue(root);

	while(!q.empty()){

		node = q.dequeue();
		// access node
		if(node->left != NULL)
			q.inqueue(node->left);

		if(node->right != NULL)
			q.inqueue(node->right);
	}


}
