/*Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, 
which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. 
Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits,
 you are to tell if the resulting number consists of only a permutation of the digits in the original number.

Input Specification:
Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:
For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation
 of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798
���룺ע������123456789��һ����λ����ǡ��������1-9��ɣ�û���ظ��� ������ֵ�2����246913578��ͬ��Ҳ��9�����ظ�������ɣ� �ٴμӱ�������֣������ᷢ��ʲô��
�����㱻Ҫ��ȥ����Ƿ��кܶ��������������ʡ�����У��ӱ�һ�����������֡���Ӧ�ø������ǣ�����������ֻ��ԭʼ���ֵ�λ��������
����ʾ����ÿ�������ļ�����һ�����ӣ�ÿһ�����Ӱ���һ��������20λ������
���ʾ������ÿһ������ʾ���������ڵ�һ�����yes������ӱ����������Ժ�ֻ��ԭ�����ֵ����н��� ������no��Ȼ������һ�У�����ӱ�������֡� 
*/
#include <cstdio>
#include <cstring>
const int maxn = 10;
struct bign{
	int len;
	int d[21];
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
bign multi(bign a,int b){
	bign c;
	int carry = 0;
	for (int i = 0;i < a.len; i++){
		int temp = a.d[i] * b + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0){
		c.d[c.len++] = carry % 10;
		carry /= 10;
	}
	return c;
}
bool judge(bign a,bign b){
	if (a.len != b.len) return false;
	int count[10] = {0};
	for (int i = 0;i < a.len;i++){
		count[a.d[i]]++;
		count[b.d[i]]--;
	}
	for (int i = 0;i < 10;i++){
		if (count[i] != 0) return false;
		else continue;
	}
	return true;
}
void print(bign a){
	for (int i = a.len - 1;i >= 0;i--){
		printf("%d",a.d[i]);
	}
}
int main(){
	char a[21];
	gets(a);
	bign A = change(a);
	bign B = multi(A,2);
	if (judge(A,B) == true) printf("Yes\n");
	else printf("No\n");
	print(B);
} 
