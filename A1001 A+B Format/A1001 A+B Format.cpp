/*Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas
(unless there are less than four digits).

Input
Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991
计算a+b并且用标准格式输出和，每三位之间要用逗号隔开 
输入：每个输入文件包含一个实例，每一个实例包含一对整数a和b，数字被空格分割开
输出：对每一个输出，你必须输出a和b的和在一行里，和必须使用标准格式 
*/

#include <cstdio>
#include <vector> 
using namespace std;
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	int c = a + b;
	int symbol = 0;
	if (c < 0){
		symbol = -1;
		c = -1*c; 
	}
	vector<char> num;
	int n;
	int count = 0;
	while(1){
		n = c % 10;
		num.push_back(n);
		count++;
		if (count % 3 == 0 && c / 10 != 0) num.push_back('-');
		c = c / 10;
		if (c == 0) break;
	}
	if (symbol == -1){
		printf("-");
	}
	puts(num);
	return 0;
} 
