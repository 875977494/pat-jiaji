/*
 Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University.
 Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test.
 Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.
 
 Input Specification:
 Each input file contains one test case. For each case, the first line contains a positive countber N (<=100), the countber of test locations.
 Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the countber of testees,
 and then K lines containing the registration countber (a 13-digit countber) and the total score of each testee. All the countbers in a line are separated by a space.
 
 Output Specification:
 For each test case, first print in one line the total countber of testees.
 Then print the final ranklist in the following format:
 registration_countber final_rank location_countber local_rank
 The locations are countbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks.
 The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration countbers.
 
 ���룺PAT���㽭��ѧ��֯�ı�����ÿһ��������Ҫ��ͬʱ�����ڼ����ص㣬�����ڲ���֮���Գɼ�������չ����
 ������Ĺ�����дһ������ȥ��ȷ�غϲ����еĳɼ������������������
 
 ����ʵ����ÿһ�������ļ�����һ������ʵ������ÿһ��ʵ������һ�а���һ���������N��<=100�������Եص����Ŀ��
 N֮��ÿһ����ʼ��һ�а���һ���������K��K<=300,����������������K�а���ע����(13λ����)��ÿһ���������ܷ֡�ȫ���������ÿո�ֿ���
 ���ʵ��������ÿһ������ʵ������һ�е�һ�����������������
 Ȼ��������������ý������ĸ�ʽ  ע����  ��������  �����  ��������
 �ص㱻����Ϊ1����N����������Էǽ�������������ͬ�ֿ�����������ͬ�������������������������ע����ǽ������С�
 */
 
#include <cstdio>
#include <cstring>
#include <algorithm> 
using namespace std;
struct Student{
    char id[14];
    int local;
    int score;
    int localrank;
}S[30001];

bool cmp(Student a,Student b){
    if (a.score != b.score) return a.score > b.score;
    else return strcmp(a.id,b.id) < 0;
}

int main(){
    int N;
    int K;
    int i,j,count = 0;
    scanf("%d",&N);
    for(i = 1;i < N + 1;i++){
        scanf("%d",&K);
        for(j = 0;j < K;j++){
            scanf("%s%d",S[count].id,&S[count].score);
            S[count].local = i;
            count++;
        }
        sort(S + count - K,S + count,cmp);
        S[count - K].localrank = 1;
        for (j = count - K + 1;j < count;j++){
        	if (S[j].score == S[j - 1].score){
        		S[j].localrank = S[j - 1].localrank;
			}
			else{
				S[j].localrank = j + 1 - (count - K);
			}
		}
    }
    printf("%d\n",count);
    sort(S,S + count,cmp);
    int r = 1;
    for (i = 0;i < count;i++){
    	if (i > 0 && S[i].score != S[i - 1].score) r = i + 1;
    	printf("%s ",S[i].id);
    	printf("%d %d %d\n",r,S[i].local,S[i].localrank);
	}
}
