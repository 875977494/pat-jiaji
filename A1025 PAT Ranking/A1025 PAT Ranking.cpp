/*
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. 
Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. 
Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. 
Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, 
and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:
For each test case, first print in one line the total number of testees. 
Then print the final ranklist in the following format:
registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. 
The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

���룺PAT���㽭��ѧ��֯�ı�����ÿһ��������Ҫ��ͬʱ�����ڼ����ص㣬�����ڲ���֮���Գɼ�������չ����
������Ĺ�����дһ������ȥ��ȷ�غϲ����еĳɼ������������������

����ʵ����ÿһ�������ļ�����һ������ʵ������ÿһ��ʵ������һ�а���һ���������N��<=100�������Եص����Ŀ��
N֮��ÿһ����ʼ��һ�а���һ���������K��K<=300,����������������K�а���ע����(13λ����)��ÿһ���������ܷ֡�ȫ���������ÿո�ֿ���
���ʵ��������ÿһ������ʵ������һ�е�һ�����������������
Ȼ��������������ý������ĸ�ʽ  ע����  ��������  �����  ��������
�ص㱻����Ϊ1����N����������Էǽ�������������ͬ�ֿ�����������ͬ�������������������������ע����ǽ������С� 
*/
#include <cstdio>
#include <algorithm>
struct Student{
	char id[14];
	int local;
	int score;
}S[30001];

bool cmp(){
	
}

int main(){
	int N;
	scanf("%d",&N);
	while(N--){
		
	}
}
