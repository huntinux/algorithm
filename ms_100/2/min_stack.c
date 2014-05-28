#include <stdio.h>
#include <stdlib.h>

struct node{
	int value; // 存储当前节点的值
	int min; // 存放当前栈中的最小值
};

struct stack{
	struct node *nodes; // 栈
	int size; // 栈最大大小
	int top; // 栈顶位置
};


struct stack 
stack_init(int max_size)
{
	struct stack s;

	s.nodes = (struct node*)calloc(max_size, sizeof(struct node));
	s.size = max_size;
	s.top = 0;

	return s;
}

void 
push(struct stack *s, int value)
{
	struct node *n;

	if(s->top >= s->size){
		fprintf(stderr, "stack full");
		exit(EXIT_FAILURE);
	}

	n = &(s->nodes[s->top]);
	n->value = value;

	// 确定n->min的值
	if(s->top == 0){ // 如果栈是空的，则最小值就是value
		n->min = value;	
	}else{ //否则先选栈顶的min
		n->min = s->nodes[s->top-1].min;
	}

	if(value < s->nodes[s->top-1].min){ // 栈不为空，则与栈顶元素的min比较，取较小的
		n->min = value;
	}	

	s->top++;
}

int 
pop(struct stack *s)
{
	int ret;

	if(s->top == 0){
		fprintf(stderr, "stack empty\n");
		exit(EXIT_FAILURE);
	}

	ret = s->nodes[s->top-1].value;
	s->top--;

	return ret;
}

int 
min(struct stack s)
{
	if(s.top == 0){
		fprintf(stderr, "stack empty\n");
		exit(EXIT_FAILURE);
	}

	return s.nodes[s.top-1].min;
}


int main()
{
	struct stack s;

	s = stack_init(10);
	push(&s, 2);
	push(&s, 3);
	push(&s, 1);

	printf("min: %d\n", min(s));
	printf("pop: %d\n", pop(&s));
	printf("min: %d\n", min(s));
	printf("pop: %d\n", pop(&s));
	printf("min: %d\n", min(s));
	printf("pop: %d\n", pop(&s));
	printf("min: %d\n", min(s));

}
