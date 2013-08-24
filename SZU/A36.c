/*题目大意：输入n，把4*n的棋盘用若干个1*2的牌完美覆盖，求能采用的覆盖方案总数

分析：每一列有4个点，每个点存在2种状态，设被牌覆盖为1，未被覆盖为0。则完美覆盖的最后一列，也就是第n列的状态必定为1111。要达到这个状态，前一列的状态只能为：0000,0011,1100,0110,1001,1100,1111。这6个状态又可以从上一列的其它状态转变而来：0000从1111转来，0011从1100或1111转来，0110从1001或1111转来，1001从0110转来，1100从0011或1111转来，1111从0000,0011,1100,0110或1100转来（排除1001因为已经包括在1111里了）。DP就从状态之间的转移开始

状态表示：
   0 0000 from 5
   1 0011 from 4,5
   2 0110 from 3,5
   3 1001 from 2
   4 1100 from 1,5
   5 1111 from 0,1,2,4,5

dp[i][s]表示4*i的棋盘在状态s时的方案总数，可写出下列的状态转移方程：
   dp[i][0]=dp[i-1][5];
   dp[i][1]=dp[i-1][4]+dp[i-1][5];
   dp[i][2]=dp[i-1][3]+dp[i-1][5];
   dp[i][3]=dp[i-1][2];
   dp[i][4]=dp[i-1][1]+dp[i-1][5];
   dp[i][5]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][4]+dp[i-1][5];
*/

#include <stdio.h>

//dp[i][s] means the total number of ways when there're i columns at situation s
int dp[22][6]={0};

int main(void)
{
    int n,i,th;
    //init: the first column cannot be 1001
    dp[1][0]=dp[1][1]=dp[1][2]=dp[1][4]=dp[1][5]=1;
    for(i=2;i<=21;i++){
        n=i-1;
        dp[i][0]=dp[n][5];
        dp[i][1]=dp[n][4]+dp[n][5];
        dp[i][2]=dp[n][3]+dp[n][5];
        dp[i][3]=dp[n][2];
        dp[i][4]=dp[n][1]+dp[n][5];
        dp[i][5]=dp[n][0]+dp[n][1]+dp[n][2]+dp[n][4]+dp[n][5];
        //printf("%d %d\n",i,dp[i][5]);printf("   2147483647\n");system("pause");
    }
    scanf("%d",&n);
    for(th=1;th<=n;th++){
        scanf("%d",&i);
        printf("%d %d\n",th,dp[i][5]);
    }
    return 0;
}