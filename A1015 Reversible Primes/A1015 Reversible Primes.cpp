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
using namespace std;
bool isprime(int n) {
	if(n <= 1) return false;
	int sqr = int(sqrt(n * 1.0));
	for(int i = 2; i <= sqr; i++) {
		if(n % i == 0)
			return false;
	}
	return true;
}
int main() {
	int n, d;
	while(scanf("%d", &n) != EOF) {
		if(n < 0) break;
		scanf("%d", &d);
		if(isprime(n) == false) {
			printf("No\n");
			continue;
		}
		int len = 0;
		int arr[100];
		do{
			arr[len++] = n % d;
			n = n / d;
		}while(n != 0);
		for(int i = 0; i < len; i++) {
			n = n * d + arr[i];
		}
		if(isprime(n) == false) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
	return 0;
}
