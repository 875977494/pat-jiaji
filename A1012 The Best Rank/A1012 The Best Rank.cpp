/*To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language,
 M - Mathematics (Calculus or Linear Algebra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- 
 that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.
For example, The grades of C, M, E and A - Average of 4 students are given as the following:

StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, 
while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, 
and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, 
followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

Output
For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.
The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, 
output the one with the highest priority.
If a student is not on the grading list, simply output "N/A".
翻译： 我们第一年cs专业的学生，我们规定他们的成绩有三门，C c语言，M 高等代数，E 英语。
我们打印出每一个学生的最佳成绩
每个输入文件包含一个测试实例。每一个测试以两个数字开始 N 和 M N是学生总数 M是检查他们排名的学生总数。接下来的N行，每行包含学生id（6位字符串），
接下来三个成绩 C M E 。 然后M行，每一行包含一个学生的id
输出：对每一个学生，在一行打印他的最好成绩的排名，然后 如果一个学生没在成绩表里，输出N/A 
Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output
1 C
1 M
1 E
1 A
3 A
N/A
*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int num;
struct student{
	int id;
	int score[4];
	int rank[4];
};

bool cmp(student a,student b){
	return a.score[num] > b.score[num];
}

bool cmp2(student a,student b){
	return a.id < b.id;
}

int getmin(int s[]){
	int flag = 0;
	for (int i = 0;i < 4;i++){
		if (s[i] < s[flag]) flag = i;
	}
	return flag;
}
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	vector<student> s;
	while(N--){
		student temp;
		scanf("%d%d%d%d",&temp.id,&temp.score[1],&temp.score[2],&temp.score[3]);
		temp.score[0] = temp.score[3] + temp.score[1] + temp.score[2];
		s.push_back(temp);
	}
	//排四次序
	for (num = 0;num < 4;num++){
		sort(s.begin(),s.end(),cmp);
		for (int j = 0;j != s.size();j++){
			if (j != 0 && s[j].score[num] == s[j - 1].score[num]) s[j].rank[num] = j;
			else s[j].rank[num] = j + 1;
		}
	}
//	sort(s.begin(),s.end(),cmp2);
//	for (int i = 0;i != s.size();i++){
//		printf("%d %d %d %d %d %d\n",s[i].id,s[i].rank[0],s[i].rank[1],s[i].rank[2],s[i].rank[3],getmin(s[i].rank));
//	}
	while(M--){
		int temp;
		scanf("%d",&temp);
		int count = 0;
		for (int i = 0;i < s.size();i++){
			if (temp == s[i].id) {
				int flag = getmin(s[i].rank);
				if (flag == 0) {
					printf("%d A\n",s[i].rank[0]);
				}
				else if (flag == 1) printf("%d C\n",s[i].rank[1]);
				else if (flag == 2) printf("%d M\n",s[i].rank[2]);
				else if (flag == 3) printf("%d E\n",s[i].rank[3]);
			}else {
				count++;
				continue;
			}
			
		}
		if (count == s.size()) printf("N/A\n");
		count = 0;
	}
}
