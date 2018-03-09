/*this time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: 
K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, 
respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output
For each test case you should output the sum of A and B in one line, with the same format as the input. 
Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2
翻译题目：这次，你被要求去寻找A+B，A+B是两个多项式
输入：每一个输入文件包含一个实例。每一个实例包含2行，并且每一行包含多项式的信息，K是多项式的非零项个数，Ni到aNi是指数和系数。K在[1,10]，NK在[1,1000]
输出：对每一个测试你必须输出A+B的和在一行里，用与输入相同的格式
注意，那里必须没有额外的空格在最后一行。请输出1位小数 */


#include <cstdio>
const int max_n = 1111;
int main(){
	int m,n;
	double M[max_n] = {0},N[max_n] = {0},sum[max_n] = {0};
	int e,count = 0;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&e);
		scanf("%lf",&M[e]);
	}
	scanf("%d",&n);
	while(n--){
		scanf("%d",&e);
		scanf("%lf",&N[e]);
	}
	for (int i = 0;i < max_n;i++){
		sum[i] = M[i] + N[i];
		if (sum[i] != 0) count++;
	}
	printf("%d",count);
	for (int i = max_n - 1;i >= 0;i--){
		if (sum[i] != 0) {
			printf(" %d %.1lf",i,sum[i]);
			count--;
		}
		else continue;
	}
	return 0;
}
