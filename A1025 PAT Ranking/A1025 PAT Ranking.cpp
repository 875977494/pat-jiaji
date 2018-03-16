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
 
 翻译：PAT是浙江大学组织的比赛。每一个比赛被要求同时比赛在几个地点，并且在测试之后考试成绩会立刻展出，
 现在你的工作是写一个程序去正确地合并所有的成绩并且输出最终排名。
 
 输入实例：每一个输入文件包含一个测试实例，对每一个实例，第一行包含一个大于零的N（<=100），测试地点的数目。
 N之后，每一个开始的一行包含一个大于零的K，K<=300,考生的数量。并且K行包含注册码(13位数字)和每一个考生的总分。全部的数字用空格分开。
 输出实例：对于每一个测试实例，第一行第一个数字输出考生数量
 然后输出最终排名用接下来的格式  注册码  最终排名  考点号  考点排名
 地点被命名为1——N。输出必须以非降序排列排名。同分考生必须有相同的排名，并且输出必须以他们注册码非降序排列。
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
