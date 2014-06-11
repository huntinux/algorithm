

// 返回倒数第k个节点
node * find(node * list, int k)
{
	node *p, *q;

	p = q = list;

	for(; k > 0; k--){
		if(p->next!=NULL)
			p = p->next;
		else
			return NULL;
	}

	while(p->next!=NULL){
		p = p->next;
		q = q->next;
	}

	return q;
}
