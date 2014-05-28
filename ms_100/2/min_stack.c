
struct node{
	int value;
	int min;
}

struct stack{
	struct node *nodes;
	int size;
	int top;
}


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

	if(s->top >= s->max_size){
		fprintf(stderr, "stack full");
		exit(EXIT_FAILURE);
	}

	n = s->nodes[s.top];
	n->value = value;

	if(s->top == 0){ // 如果栈是空的，则最小值就是value
		n->min = value;	
	}else if(value > s->nodes[s.top-1]->min){ // 栈不为空，则与栈顶元素的min比较，取较小的
		n->min = s->nodes[top-1]->min
	}

	s->top++;
}

int pop(struct stack *s)
{
	if(s->top == 0){
		fprintf(stderr, "stack empty");
		exit(EXIT_FAILURE);
	}
	return s->nodes[s->top-1]->value;
}

int min(struct stack *s)
{
	return s->nodes[s->top-1]->min;
}

