/*
Shuffling is a procedure used to randomize a deck of playing cards. Because standard shuffling techniques are seen as weak,
 and in order to avoid "inside jobs" where employees collaborate with gamblers by performing inadequate shuffles, many casinos employ automatic shuffling machines. 
 Your task is to simulate a shuffling machine.

The machine shuffles a deck of 54 cards according to a given random order and repeats for a given number of times. 
It is assumed that the initial status of a card deck is in the following order:

S1, S2, ..., S13, H1, H2, ..., H13, C1, C2, ..., C13, D1, D2, ..., D13, J1, J2

where "S" stands for "Spade", "H" for "Heart", "C" for "Club", "D" for "Diamond", and "J" for "Joker".
A given order is a permutation of distinct integers in [1, 54]. If the number at the i-th position is j, 
it means to move the card from position i to position j. For example, suppose we only have 5 cards: S3, H5, C1, D13 and J2. 
Given a shuffling order {4, 2, 5, 3, 1}, the result will be: J2, H5, D13, S3, C1. If we are to repeat the shuffling again, 
the result will be: C1, H5, S3, J2, D13.
尝试翻译：洗牌是一种随机将牌打乱顺序的工序。 因为标准的洗牌技术洗的不充分，并且为了避免赌场内部人员与赌徒合作，许多赌场老板使用自动洗牌机。你的任务是
模拟一个自动洗牌机。
机器按照给定的随机顺序并且重复给定的次数洗一副牌。
假设一副牌的初始状态如下 
其中 S代表spade黑桃，H代表heart红心，c代表club梅花，d代表diamond方块，J代表joker
一个给定的顺序是一个不一样的1-54的排列组合。xxxxx 
这意味着从位置i移动卡片到位置j。比如，假设我们只有五张牌，黑桃3，红桃5，草花A，方块K，以及小王
给定你一个洗牌顺序{4,2,5,3,1}，那么结果应该是，小王，红桃5，方块K，黑桃3，草花A。如果我们再次重复这个顺序，
那么结果应该是 C1, H5, S3, J2, D13。 
*/
#include <cstdio>
int main(){
	int N;
	int count = 0;
	scanf("%d",&N);
	int num[54],i,j;
	int a[54];
	for (i = 0;i < 54;i++){
		num[i] = i + 1;
		//printf("%d ",num[i]);
	}
	int order[54];
	for (i = 0;i < 54;i++){
		scanf("%d",&order[i]);
	}
	while(N--){  //替换的主程序 
		for (i = 0;i < 54;i++){
			a[order[i] - 1] = num[i];
		}
		for (i = 0;i < 54;i++){
			num[i] = a[i];
		}
	}
	for (i = 0;i < 54;i++){
		if (num[i] == 53) {
			printf("J1");count++;	
		}
		else if (num[i] == 54){
			printf("J2");count++;
		} 
		else if (num[i] == 13){
			printf("S13");count++;
		} 
		else if (num[i] == 26) {
			printf("H13");count++;
		}
		else if (num[i] == 39) {
			printf("C13");count++;
		}
		else if (num[i] == 52){
			printf("D13");count++;
		} 
		else if (num[i]/13 == 0) {
			printf("S%d",num[i]%13);count++;
		}
		else if (num[i]/13 == 1){
			printf("H%d",num[i]%13);count++;
		}
		else if (num[i]/13 == 2){
			printf("C%d",num[i]%13);count++;
		}
		else {
			printf("D%d",num[i]%13);count++;
		}
		if (count != 54) printf(" ");
	}
} 
