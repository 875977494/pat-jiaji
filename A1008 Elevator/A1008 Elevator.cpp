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
翻译：我们城市最高的建筑只有一个电梯。由N个大于零的数字组成请求的队列。数字表示在哪些楼层电梯会停下来，用确定的命令。它会花费六秒钟让电梯上一层楼。
并且会花费四秒钟下楼。电梯在每一个楼层停五秒。
给定一个请求列表，你被要求去计算这个队列的总是截。
电梯从第零层开始并且在完成队列后不需要回到零层。
输入实例：每一个输入文件包含一个测试实例，每一个测试实例包含一个大于零的数N，接下来N个大于零的数字。所有的输入数字都小于100
输出实例：对每一个测试实例，打印出总时间 
*/
#include <cstdio>
#include <vector>
using namespace std;
const int Null = -1; 
struct elevator{
	int now_floor ;
	int next_floor; //如果指向Null代表停止 
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
