    /*This time, you are supposed to find A*B where A and B are two polynomials.
     Input Specification:
     Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK,
     where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively.
     It is given that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.
     
     Output Specification:
     For each test case you should output the product of A and B in one line, with the same format as the input.
     Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.
     
     Sample Input
     2 1 2.4 0 3.2
     2 2 1.5 1 0.5
     Sample Output
     3 3 3.6 2 6.0 1 1.6
     翻译：这次，你被要求去寻找A*B，A和B是两个多项式。
     输入实例：每一个输入文件包含一个测试实例，每一个实例包含两行，并且每一行包含信息是…… K是非零项的个数。Ni和aNi分别是指数和系数
     K1-10，N0-1000
     输出实例：对每一个测试实例，你必须输出A和B的乘积在一行里，用与输入相同的格式
     注意最后一格没有额外的空格，请保留一位小数。*/
    #include <cstdio>
    const int max_n = 11111;
    int main(){
        int m,n,e;
        double M[max_n] = {0},N[max_n] = {0},product[2*max_n] = {0};
        int count = 0;
        scanf("%d",&m);
        while(m--){
            scanf("%d",&e);
            scanf("%lf",&M[e]);
        }
        scanf("%d",&n);
        while(n--){
            scanf("%d",&e);
            scanf("%lf",&N[e]);
            for (int i = 0;i < max_n;i++){
                    product[i + e] = product[i + e] + M[i]*N[e];
                }
            }
        for (int i = 0;i < 2*max_n;i++){
            if (product[i] != 0) count++;
        }
        printf("%d",count);
        for (int i = 2*max_n - 1;i >= 0;i--){
            if (product[i] != 0) {
            	printf(" %d %.1lf",i,product[i]);
			}
            else continue;
        }
    }

