# 问题
翻转句子中单词的顺序。
题目:输入一个英文句子,翻转句子中单词的顺序,但单词内字符的顺序不变。
句子中单词以空格符隔开。为简单起见,标点符号和普通字母一样处理。
例如输入“I am a student.”
,则输出“student. a am I”


# 分析

* 法1
先将整个字符串逆置，然后在以单词为单位逆置

* 法2
利用栈
从字符串尾部开始，碰到空格之前，将所有字符入栈
碰到空格时候，将栈中元素，依次弹出，空格按照原样输出



# 总结
和逆序有关的，可能需要几趟逆序。
逆序的东西可以借助栈。
