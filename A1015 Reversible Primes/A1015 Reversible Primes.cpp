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
���룺�κ�����ϵͳ�Ŀ�����������һ��������������˵��ʮ��������73��һ��������������Ϊ37Ҳ��һ��������
���ڸ�������������������֣�N��D���㱻Ҫ��ȥ˵�������N��һ������������d������
����ʵ�� �����ļ�������������ʵ����ÿһ��ʵ��ռһ�У�N��D��������һ��С�����N����
���ʵ�� ����ÿһ������ʵ�������yes����no 
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

int change_10(char s[],int d){  //��������Ƶ��ַ�����ת��Ϊʮ���� 
	int len = strlen(s);
	int num = 0;
	for (int i = len - 1;i >= 0;i--){
		num += pow(d,len - i - 1) * (s[i] - '0');
	} 
	return num;
}

int change_10(vector<char> s,int d){  //��������Ƶ��ַ�����ת��Ϊʮ����  ���� 
	int num = 0;
	int len = s.size();
	for (int i = len - 1;i >= 0;i--){
		num += pow(d,len - i - 1) * (s[i] - '0');
	} 
	return num;
}

vector<char> change_S(char S[],int d){  //��ʮ����ת��Ϊ�������� 
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
		int len = strlen(s);   //���ڼ�һ�³��򣬰�num1������ǰ ,Ȼ���������ѭ��
		int num1 = change_10(s,10);
		if (isPrime(num1) == false) {
			printf("No\n");
		}else {
			if (D == 10){
				reverse(s,s + len);
				int num2 = change_10(s,D);
				if (isPrime(num2) == true) printf("Yes\n");
				else printf("No\n");
			}else {  //���D����10���ȿ���������ǲ������������������ֱ�����no���������������ת��ΪD���ƣ���ת����ת��Ϊ10���ƣ����Ƿ�����������������yes 
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

