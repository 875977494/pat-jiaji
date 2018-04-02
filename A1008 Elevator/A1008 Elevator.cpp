/*The highest building in our city has only one elevator. A request list is made up with N positive numbers. 
The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, 
and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list.
 The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:
For each test case, print the total time on a single line.

Sample Input:
3 2 3 1
Sample Output:
41
���룺���ǳ�����ߵĽ���ֻ��һ�����ݡ���N��������������������Ķ��С����ֱ�ʾ����Щ¥����ݻ�ͣ��������ȷ����������Ứ���������õ�����һ��¥��
���һỨ����������¥��������ÿһ��¥��ͣ���롣
����һ�������б��㱻Ҫ��ȥ����������е����ǽء�
���ݴӵ���㿪ʼ��������ɶ��к���Ҫ�ص���㡣
����ʵ����ÿһ�������ļ�����һ������ʵ����ÿһ������ʵ������һ�����������N��������N������������֡����е��������ֶ�С��100
���ʵ������ÿһ������ʵ������ӡ����ʱ�� 
*/
#include <cstdio>
#include <vector>
using namespace std;
const int Null = -1; 
struct elevator{
	int now_floor ;
	int next_floor; //���ָ��Null����ֹͣ 
};

void print(vector<elevator> a){
//	printf("%d",a.size());
	for (int i = 0;i != a.size();i++){
		printf("now_floor:%d next_floor:%d\n",a[i].now_floor,a[i].next_floor);
	}
}

int time(vector<elevator> a){
	int t = 0;
	t = a.size() * 5;
	int temp;
	for (int i = 0;i != a.size();i++){
		temp = a[i].now_floor - a[i].next_floor;
		if (temp > 0){
			t += temp * 4;
		}else {
			t += -1 * temp * 6;
		}
	}
	return t;
}

int main(){
	int N;
	scanf("%d",&N);
	vector<elevator> a;
	elevator temp;
	int n;
	while(N--){
		scanf("%d",&temp.next_floor);
		if (a.size() == 0){
			temp.now_floor = 0;
		}else {
			temp.now_floor = a[a.size() - 1].next_floor;
		}
		a.push_back(temp);
	}
	print(a);
	int t = time(a);
	printf("%d",t);
} 
