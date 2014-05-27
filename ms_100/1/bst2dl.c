
struct BSTreeNode
{
	int m_nValue; // value of node
	BSTreeNode *m_pLeft; // left child of node
	BSTreeNode *m_pRight; // right child of node
};

/**
 * @param root :The root node of the tree
 * @return :The head node of the converted list.
 */
BSTreeNode * treeToLinkedList(BSTreeNode * root) {
	BSTreeNode * head, * tail;
	helper(head, tail, root);
	return head;
}

void helper(BSTreeNode *& head, BSTreeNode *& tail, BSTreeNode *root) {

	BSTreeNode *lt, *rh; // lt是左面双链表的tail; rh是右侧双链表的head

	if (root == NULL) {  
		head = NULL, tail = NULL;
		return;
	}

	helper(head, lt, root->m_pLeft); //求得左子树的head和tail
	helper(rh, tail, root->m_pRight); // 求得右子树的head和tail

	if (lt!=NULL) { 
		lt->m_pRight = root;	// 子树的右侧指针(next)指向root
		root->m_pLeft = lt;		// root左侧指针(prev)指向左子树的tail 
	} else {// 如果左侧链表的tail为NULL,说明左子树为空，则head就是当前节点root
		head = root;
	}
	if (rh!=NULL) {
		root->m_pRight=rh; // root右侧指针(next)指向右子树的head
		rh->m_pLeft = root; // 右子树的左侧指针(prev)指向root
	} else {// 如果右侧链表的head为NULL,说明右子树为空，则tail就是当前节点root
		tail = root;
	}
}
// 引用：其实就是变量的别名，操作引用和操作原变量一样。
// 注意这里对指针的引用的作用。

// 总结：
// 1. 关于树的问题要多联想递归
// 2. 指针的引用， 是为了更改指针的内容(指针的指向), 而不是为了改变它指向的东西的内容。
// 3. 树和链表的题目，画画图会清晰一点。
