#ifndef REVERSE_SENTENCE_H
#define REVERSE_SENTENCE_H

/*
翻转句子中单词的顺序。
题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
句子中单词以空格符隔开。为简单起见，标点符号和普通字母一样处理。
例如输入“I am a student.”，则输出“student. a am I”

*/
void reverse(char s[],int n)
{
	char tmp;
	for(char* p1=s,*p2=s+n-1;p1<p2;++p1,--p2)
	{
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}
}

void reverse_sentence(char s[],int n)
{
	//1.reverse the whole string
	//  eg:jdp is a boy --> yob a si pdj
	//2.reverse each word
	//  eg:yob a si pdj --> boy a is jdp
	reverse(s,n);
	int p1=0;
	int p2=0;
	while(p2<n)
	{
		p1 = p2;
		while(p2<n && s[p2]!= ' ') ++p2;
		reverse(s+p1,p2-p1);
		++p2;
	}
}

#endif