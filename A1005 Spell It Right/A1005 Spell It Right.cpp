/*Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, 
but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five

翻译： 给定一个非负数N，你的任务是计算N的每一位之和，并且用英文输出每一位的和
输入实例：每一个输入文件包含一个测试实例，每一个实例包括一个N
输出实例：对于每一个实例，在一行里用英文输出位数之和，每个单词之间用空格分割，最后一个单词后面没有空格 
*/
#include <cstdio>
#include <stack>
using namespace std;
int main(){
	char s[101];
	char c[10][6] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	gets(s);
	int sum = 0;
	for (int i = 0;s[i] != '\0';i++){
		sum += s[i] - '0';
	}
	//printf("%d\n",sum);
	int n;
	stack<int> spell;
	while(sum != 0){
		n = sum % 10;
		spell.push(n);
		//printf("%d\n",spell.top());
		sum = sum / 10;
	}
	while (spell.empty() != true){
		printf("%s",c[spell.top()]);
		spell.pop();
		if (spell.empty() != true) printf(" ");
	}
}
