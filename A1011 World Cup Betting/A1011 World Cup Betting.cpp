/*With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players from the best teams doing battles
 for the World Cup trophy in South Africa. Similarly, football betting fans were putting their money where their mouths were,
  by laying all manner of World Cup bets.

Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: first select any three of the games. 
Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose. There was an odd assigned to each result.
 The winner's odd would be the product of the three odds times 65%.

For example, 3 games' odds are given as the following:
 W    T    L
1.1  2.5  1.7
1.2  3.0  1.6
4.1  1.2  1.1
To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans, 
then the maximum profit would be (4.1*3.0*2.5*65%-1)*2 = 37.98 yuans (accurate up to 2 decimal places).

Input
Each input file contains one test case. Each case contains the betting information of 3 games. 
Each game occupies a line with three distinct odds corresponding to W, T and L.

Output
For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places. 
The characters and the number must be separated by one space.

Sample Input
1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1
Sample Output
T T W 37.98
翻译：随着2010世界杯的开始，最有竞争力的球队粉丝增长了。相似地是， 博彩爱好者……
中国足球博彩提供一种三赢游戏，规则很简单：首先选择任意三个游戏结果，然后选择比赛，赌博某个游戏结果，W是赢，T是平局，L是输，每场比赛结果唯一。
比如：三场比赛的结果如下： 为了得到最大收益，必须买第三场赢，第二场平，第一场平。如果每一个买2元，会获得37.98
输入：每个输入文件包含一个测试实例，每一个测试包含 
*/
#include <cstdio>
#include <algorithm>
using namespace std;
double max(double a,double b,double c){
	double m = max(a,b);
	m = max(m,c);
	return m;
}

int main(){
	double a,b,c;
	double money = 1;
	int d[3];
	for (int i = 0;i < 3;i++){
		scanf("%lf %lf %lf",&a,&b,&c);
		double m = max(a,b,c);
		if (m == a) d[i] = 1;  //W
		else if (m == b) d[i] = 2; //T
		else d[i] = 3; //L
		money *= m;
	}
	money = (money * 0.65 - 1) * 2;
	for (int i = 0;i < 3;i++){
		if (d[i] == 1) printf("W ");
		else if(d[i] == 2) printf("T ");
		else printf("L ");
	}
	printf("%.2lf",money);
}
