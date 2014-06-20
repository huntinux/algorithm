# Problem
```
题目:输入一个表示整数的字符串,把该字符串转换成整数并输出。
例如输入字符串"345",则输出整数 345。
```

# Analysis
```
整数有正负之分。
    第一个字符是 '-', 说明是负数
  	第一个字符是 '+'  或 数字 , 说明是正数

如果第一个字符 不是 '-' '+' '数字' ， 则该字符串不是一个合法的数字字符串


num = 0

判断字符串是否合法
	第一个字符是否是 - + 数字

if(str[0] == '-')
	factor = -1
	str++
else if (str[0] == '+')
	factor = 1
	str++
else if str[0] 是数字
	factor = 1
else
	perror str格式不是个数字

while(*str != '\0' && *str是数字)
	d = *str - '0' 
	num *= 10
	num += d	

return num * factor

```
