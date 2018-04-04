/*A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. 
For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (< 105) and D (1 < D <= 10), you are supposed to tell if N is a reversible prime with radix D.

Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

Output Specification:
For each test case, print in one line "Yes" if N is a reversible prime with radix D, or "No" if not.

Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
翻译：任何数字系统的可逆素数都是一个素数。举例来说，十进制数字73是一个可逆素数，因为37也是一个素数。
现在给定你两个大于零的数字，N和D，你被要求去说出来如果N是一个可逆素数在d进制中
输入实例 输入文件包含许多个测试实例。每一个实例占一行，N和D。输入以一个小于零的N结束
输出实例 对于每一个测试实例，输出yes或者no 
*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100010;

bool isPrime(int a){
	if (a == 0 || a == 1) return false;
	if (a == 2) return true;
	for (int i = 2;i <= sqrt(a);i++){
		if (a % i == 0) return false;
	}
	return true;
} 

int change_10(char s[],int d){  //将任意进制的字符数字转换为十进制 
	int len = strlen(s);
	int num = 0;
	for (int i = len - 1;i >= 0;i--){
		num += pow(d,len - i - 1) * (s[i] - '0');
	} 
	return num;
}

int change_10(vector<char> s,int d){  //将任意进制的字符数字转换为十进制  重载 
	int num = 0;
	int len = s.size();
	for (int i = len - 1;i >= 0;i--){
		num += pow(d,len - i - 1) * (s[i] - '0');
	} 
	return num;
}

vector<char> change_S(char S[],int d){  //将十进制转换为任意数字 
	int num = change_10(S,10);
	vector<char> s;
	char c;
	for (int i = 0;;i++){
		c = num % d;
		s.push_back(c);
		num = num / d;
		if (num == 0) break;
	}
//	reverse(s.begin(),s.end());
	return s;
} 

void print(vector<char> s){
	for (int i = 0;i != s.size();i++){
		printf("%d",s[i]);
	}
}

int main(){
	int D;
	char s[maxn];
	while(1){
		scanf("%s %d",s,&D);
		if (s[0] == '-') return 0;
		int len = strlen(s);   //现在简化一下程序，把num1整体提前 ,然后整体加上循环
		int num1 = change_10(s,10);
		if (isPrime(num1) == false) {
			printf("No\n");
		}else {
			if (D == 10){
				reverse(s,s + len);
				int num2 = change_10(s,D);
				if (isPrime(num2) == true) printf("Yes\n");
				else printf("No\n");
			}else {  //如果D不是10，先看这个数字是不是素数，如果不是则直接输出no，如果是素数，就转换为D进制，翻转，再转换为10进制，看是否是素数，如果是输出yes 
				int num1 = change_10(s,D);
				if (isPrime(num1) == false) printf("No\n"); 
				else {
					vector<char> S = change_S(s,D);
					int num2 = change_10(S,10);
					if (isPrime(num2) == true) 	printf("Yes\n");
					else printf("No\n");
				}
			}	
		}
	}
	return 0;
} 

