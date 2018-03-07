/*
The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.
Input Specification:
Each input file contains one test case. For each case, the first line contains an integer N (in [3, 105]), followed by N integer distances D1 D2 ... DN, 
where Di is the distance between the i-th and the (i+1)-st exits, and DN is between the N-th and the 1st exits. All the numbers in a line are separated by a space. 
The second line gives a positive integer M (<=104), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. 
It is guaranteed that the total round trip distance is no more than 107.

Output Specification:
For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.
Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7
翻译：这个任务非常简单：给你N个出口组成圆的出口在一条路上，你被要求找到最短的距离。
输入规范：每一个输入文件一个测试。对每一个测试范例，第一行包含一个N（范围[3,105]），跟在N后面有完整的距离D1，...,DN，
Di 代表i到i+1之间的距离，并且Dn是n和第一个的距离。所有的数字在一行里以空格分开， 第二行给你大于零的M，在M之后，包含一对数字， 数字是从1到N
距离不会超过107
输出规范：对每一个情况，输出你的结果，包含最短距离在给定的数据之间。 
*/

#include <stdio.h>
int distance(int a,int b,int n[],int N,int sum);
int main(){
	int N,M,i;
	int n[100005] = {0},a[10005] = {0},b[10005] = {0};
	int d;
	int sum;
	scanf("%d",&N);
	for (i = 1;i < N + 1;i++){
		scanf("%d",&n[i]);
	}
	scanf("%d",&M);
	for (i = 0;i < N + 1;i++){
		sum += n[i];
	}
	for (i = 1;i < M + 1;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	for (i = 1;i < M + 1;i++){
		d = distance(a[i],b[i],n,N,sum);
		printf("%d\n",d);
	}
} 

int distance(int a,int b,int n[],int N,int sum){
	int d1 = 0,d2 = 0; 
	int m;
	if (a > b){
		int temp = a;
		a = b;
		b = temp;
	}
	for (int i = a;i < b;i++){
		d1 += n[i];
	}
	d2 = sum - d1;
	if (d2 < d1) return d2;
	else return d1;
}

