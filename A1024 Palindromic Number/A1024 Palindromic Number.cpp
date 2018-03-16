/*A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. 
For example, 1234321 is a palindromic number. All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, 
the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number,
 this is repeated until it gives a palindromic number. For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, 
 and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

Input Specification:

Each input file contains one test case. Each case consists of two positive numbers N and K, 
where N (<= 1010) is the initial numer and K (<= 100) is the maximum number of steps. The numbers are separated by a space.

Output Specification:

For each test case, output two numbers, one in each line. The first number is the paired palindromic number of N, 
and the second number is the number of steps taken to find the palindromic number. If the palindromic number is not found after K steps, 
just output the number obtained at the Kth step and K instead.
翻译：一个从前开始写与从后开始写都一样的数字叫做回文数字。比如1234321是一个回文数字。所有的单个数字都是回文数字。
没有回文数字与回文的配对经由一系列的操作。首先，非回文数字被翻转，并且结果被加到原来的数字上。如果结果不是一个回文数字，重复上述操作，直到获得一个回文数字。比如，
如果从67开始，我们可以在两步内得到一个回文数字
给定任何一个大于零的数字N，你被要求去寻找几步能得到回文数字
输入示例：每一个输入文件一个例子，给两个大于零的数字N和K，N<= 10^10，K<=100。数字之间以空格分割
输入示例：对每一个例子，输出两个数字，在不同一行里，第一个数字是N的回文数字，第二个数字是经过多少步原来数字成为了回文数字。如果在K的范围内没有找到回文数字，
那么只要输出数字第K次的数字（包括第K次）。 
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct bign{
	int d[1001];
	int len;
	bign(){
		memset(d,0,sizeof(d));
		len = 0;
	}
};
bign change(char str[]){
	bign a;
	a.len = strlen(str);
	for (int i = a.len - 1;i >= 0;i--){
		a.d[a.len - 1 - i] = str[i] - '0';
	}
	return a;
}

bign add(bign a,bign b){
	bign c;
	int carry = 0;
	for (int i = 0;i < a.len || i < b.len;i++){
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if (carry != 0){
		c.d[c.len++] = carry;	
	}
	return c;
}

bool Pal(bign a){
	for (int i = 0;i <= a.len / 2;i++){
		if (a.d[i] != a.d[a.len - 1 - i]){
			return false;
		}
	}
	return true;
}

void print(bign a){
	for (int i = a.len - 1;i >= 0;i--){
		printf("%d",a.d[i]);
	}
	printf("\n");
}

int main(){
	char str[1001];
	int K;
	scanf("%s%d",str,&K);
	bign a = change(str);
	if (Pal(a) == true) {
		print(a);
		printf("\n0");
		return 0;
	}
	int count = 0;
	for (int i = 0; i < K;i++){
		bign b = a;
		reverse(b.d, b.d + b.len);
		a = add(a,b);
		count++;
		if (Pal(a) == true) break;
	}
	print(a);
	printf("%d",count);
	return 0;
}

