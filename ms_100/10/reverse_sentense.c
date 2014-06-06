#include <stdio.h>
#include <string.h>

char s[]="i am chj.";
//char s[]="i am chj.   hehe"
//char s[]="  i 	am chj.   hehe"

void swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


// 反转字符串
void
reverse_str(char *start, char *end)
{
	
	while(start < end){
		swap(start,end);
		start++;
		end--;
	}

}

// 判断ch是否为空白字符
int
is_blank(char ch)
{
	if(ch == ' ' || ch == '\t')
		return 1;

	return 0;
}

// 按照单词反转
void
reverse_word(char str[])
{
	char *p, *q;

	p = q = str;

	while(*q != '\0'){

		// 用p q框住一个word，然后用reverse_str处理
		while(!is_blank(*q) && *q != '\0'){
			q++;
		}
		q--;

		// 反转
		reverse_str(p,q);

		// q指向下一个非空白字符
		q++;	
		while(is_blank(*q) && *q != '\0'){
			q++;
		}
		p = q;
	}

}

	int 
main()
{
	int len = strlen(s);
	reverse_str(s, s+len-1);
	reverse_word(s);
	printf("%s\n", s);

	return 0;
} 
