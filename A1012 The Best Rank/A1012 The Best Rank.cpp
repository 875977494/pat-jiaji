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
���룺 ���ǵ�һ��csרҵ��ѧ�������ǹ涨���ǵĳɼ������ţ�C c���ԣ�M �ߵȴ�����E Ӣ�
���Ǵ�ӡ��ÿһ��ѧ������ѳɼ�
ÿ�������ļ�����һ������ʵ����ÿһ���������������ֿ�ʼ N �� M N��ѧ������ M�Ǽ������������ѧ����������������N�У�ÿ�а���ѧ��id��6λ�ַ�������
�����������ɼ� C M E �� Ȼ��M�У�ÿһ�а���һ��ѧ����id
�������ÿһ��ѧ������һ�д�ӡ������óɼ���������Ȼ�� ���һ��ѧ��û�ڳɼ�������N/A 
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
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct student{
	int id;
	int C;
	int M;
	int E;
	int A;
}; 
bool cmp_a(student a,student b){
	return a.A > b.A;
}
bool cmp_c(student a,student b){
	return a.C > b.C;
}
bool cmp_m(student a,student b){
	return a.M > b.M;
}
bool cmp_e(student a,student b){
	return a.E > b.E;
}

char Max(student s){
	int c,m,e,a;
	c = s.C;       // A > C > M > E
	m = s.M;
	e = s.E;
	a = s.A;
	if (a >= m && a >= c && a >= e) return 'A';
	else if (c >= a && c >= e && c >= m) return 'C';
	else if (m >= a && m >= c && m >= e) return 'M';
	else return 'E';
}

int Get_a_rank(vector<student> a,student b){
	int rank;
	int score = b.A;
	vector<student> temp = a;
	sort(temp.begin(),temp.end(),cmp_a);
	for (int i = 0;i != temp.size();i++){
		if (temp[i].A == score){
			rank = i + 1;
			return rank;
		}
	}
}

int Get_c_rank(vector<student> a,student b){
	int rank;
	int score = b.C;
	vector<student> temp = a;
	sort(temp.begin(),temp.end(),cmp_c);
	for (int i = 0;i != temp.size();i++){
		if (temp[i].C == score){
			rank = i + 1;
			return rank;
		}
	}
}

int Get_m_rank(vector<student> a,student b){
	int rank;
	int score = b.M;
	vector<student> temp = a;
	sort(temp.begin(),temp.end(),cmp_m);
	for (int i = 0;i != temp.size();i++){
		if (temp[i].M == score){
			rank = i + 1;
			return rank;
		}
	}
}

int Get_e_rank(vector<student> a,student b){
	int rank;
	int score = b.E;
	vector<student> temp = a;
	sort(temp.begin(),temp.end(),cmp_e);
	for (int i = 0;i != temp.size();i++){
		if (temp[i].E == score){
			rank = i + 1;
			return rank;
		}
	}
}
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	vector<student> s;
	while(N--){
		student temp;
		scanf("%d%d%d%d",&temp.id,&temp.C,&temp.M,&temp.E);
		temp.A = (temp.C + temp.M + temp.E) / 3;
		if ((temp.C + temp.M + temp.E) % 3 > 1) temp.A++;
		s.push_back(temp);
	}
	while(M--){
		int temp;
		int count = 0;
		scanf("%d",&temp);
		for (int i = 0; i != s.size();i++){
			if (s[i].id == temp){
				char a = Max(s[i]);
				int rank;
				if (a == 'A'){
					rank = Get_a_rank(s,s[i]);
					printf("%d A\n",rank);
					break;
				}else if (a == 'C'){
					rank = Get_c_rank(s,s[i]);
					printf("%d C\n",rank);
					break;
				}else if (a == 'M'){
					rank = Get_m_rank(s,s[i]);
					printf("%d M\n",rank);
					break;
				}else if (a == 'E'){
					rank = Get_e_rank(s,s[i]);
					printf("%d E\n",rank);
					break;
				}
			}else count++;
			if (count == s.size()) printf("N/A\n");
			count = 0;
		}	
	}
} 
