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
���Է��룺ϴ����һ��������ƴ���˳��Ĺ��� ��Ϊ��׼��ϴ�Ƽ���ϴ�Ĳ���֣�����Ϊ�˱���ĳ��ڲ���Ա���ͽ���������ĳ��ϰ�ʹ���Զ�ϴ�ƻ������������
ģ��һ���Զ�ϴ�ƻ���
�������ո��������˳�����ظ������Ĵ���ϴһ���ơ�
����һ���Ƶĳ�ʼ״̬���� 
���� S����spade���ң�H����heart���ģ�c����club÷����d����diamond���飬J����joker
һ��������˳����һ����һ����1-54��������ϡ�xxxxx 
����ζ�Ŵ�λ��i�ƶ���Ƭ��λ��j�����磬��������ֻ�������ƣ�����3������5���ݻ�A������K���Լ�С��
������һ��ϴ��˳��{4,2,5,3,1}����ô���Ӧ���ǣ�С��������5������K������3���ݻ�A����������ٴ��ظ����˳��
��ô���Ӧ���� C1, H5, S3, J2, D13�� 
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
	while(N--){  //�滻�������� 
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
