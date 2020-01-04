/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>



/*=========================================================================
  Constants and definitions:
==========================================================================*/




/*-------------------------------------------------------------------------
  The main program
 -------------------------------------------------------------------------*/

int avarage(int num1, int num2, int num3);
int min(int num1, int num2);
int absolute(int num);
int root(int num);
int power(int n, int p); // 1000000000
int f(int x, int n);
void printThreeDigitsOpenMessage();
void printResults(int avg,int rootOfMinNum,int avgPowTwoRootOfMinNum, int fvalofxinn);
void printCharactersOpenMessage();
void printDataPerGivenCharAsInput(char ch,int numberOfTimesAppeared);
void printNumberOfOtherCharsAppeared(int numberOfOtherCharsAppeared);





int main()
{
    int curr, three[3]= {0}, i;
    printThreeDigitsOpenMessage();
    for(i=0;(i<3) && (scanf("%d", &curr)==1);i++)
    {
        three[i] = curr;
    }
    int abs_min_num = absolute(min(min(three[2],three[1]),three[0]));
    int avg = avarage(three[2],three[1],three[0]);
    int root_absolute_min  = root(abs_min_num);
    int avg_pow_min = power(avg, abs_min_num);
    int n = root_absolute_min;
    if (n == -1)
    {
        n = 3;
    }
    int fvalofxinn = f(abs_min_num, n);
    printResults(avg, root_absolute_min,avg_pow_min, fvalofxinn);

    return 0;
}








 int avarage(int num1, int num2, int num3)
 {
     return (num1 + num2 + num3) / 3;
 }

 int min(int num1, int num2)
 {
     if (num1 > num2)   return num2;
     return num1;
 }
 int absolute(int num)
 {
    if (num < 0)   num = -num;
    return num;
 }
 int root(int num)
 {
     if (num == 1) return 1;
     if (num < 0) return -1;
     for(int i=1; i< num; i++)
     {
         if (i*i == num)    return i;
     }
     return -1;
 }
 int power(int n, int p)
 {
     int c = 1;
     if (n < 0 || p < 0) return -1;
     if (n == 0 && p == 0) return 1;
     for (int i=1; i<=p;i++)
     {
         int tmp = n;
         c *= tmp;
     }
     if (c > 1000000000) return -1;
     return c;
 }


int f(int x, int n)
{
    if (n < 0 || x < 0) return -1;
    int sum = 0;
    for (int i=0; i<=n; i++)
    {
        sum += power(x, i);
    }
    if (sum > 1000000000) return -1;
    return sum;
}
void printThreeDigitsOpenMessage()
{
    printf("Please enter three integers:\n");
}

void printResults(int avg,int rootOfMinNum,int avgPowTwoRootOfMinNum, int fvalofxinn){
    printf("%d %d %d %d\n",avg,rootOfMinNum,avgPowTwoRootOfMinNum,fvalofxinn);
}
