/*People in Mars represent the colors in their computers in a similar way as the Earth people.
 That is, a color is represented by a 6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green,
  and the last 2 digits for Blue. The only difference is that they use radix 13 (0-9 and A-C) instead of 16. 
  Now given a color in three decimal numbers (each between 0 and 168), you are supposed to output their Mars RGB values.

Input

Each input file contains one test case which occupies a line containing the three decimal color values.

Output

For each test case you should output the Mars RGB value in the following format: first output "#", 
then followed by a 6-digit number where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a "0" to the left.

Sample Input
15 43 71
Sample Output
#123456
翻译：火星上的人使用电脑中的颜色方式与地球人相似。
一个颜色通过六位数字组成，头两位红色，中间两位绿色，后两位蓝色。 不同的是他们使用13个基数来代替16
现在给定你一个颜色在三个数字（都在0-168之间），你被要求去输出RGB的值
输入：每一个输入文件包含一个测试实例，在一行中输入三个颜色的值
输出：对每一个测试实例，你应该输出火星的rgb值，在#之后，然后用一个六位的数字 
*/
#include <cstdio>
int main(){
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	char radix[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	printf("#%c%c",radix[r/13],radix[r%13]);
	printf("%c%c",radix[g/13],radix[g%13]);
	printf("%c%c",radix[b/13],radix[b%13]);
} 
