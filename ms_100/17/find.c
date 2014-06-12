#include <stdio.h>
#include <string.h>

struct node{
	int count;
	int index; // 字符在str中的下标
};


char find(const char* str)
{
	struct node nodes[256];
	int index, i, min_index;
	char ch;
	const char *str_begin  = str;

	if(*str == '\0')
		return '\0';

	memset(nodes, 0, 256 * sizeof(struct node)); // 清0

	index = 0;
	while((ch = *str) != '\0'){

		nodes[ch].count++;
		nodes[ch].index = index; // 如果字符出现两次，那么index是最大的index；这是无所谓的，因为出现两次的，不符合条件

		str++;
		index++;
	}

	// 找到出现一次，且index最小的（也就是最靠前的）
	min_index = 256;
	for(i = 0; i < 256; i++){
		if(nodes[i].count == 1 && nodes[i].index < min_index)	
			min_index = nodes[i].index;
	}
	
	return str_begin[min_index];
}

int main()
{
	printf("%c\n", find("acabdeff"));
	printf("%c\n", find("abacdeff"));

	return 0;
}
