// B92.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

int matrix[12][12];
int mark[12][12];
int times,n;

void markmat(int i,int j,int i1,int j1,int i2,int j2){
	mark[i][j]=mark[i1][j1]=mark[i2][j2]=times;
	times++;
}//在mark矩阵中标记已经判断出的三个骰子

int judge(int i,int j,int i1,int j1,int i2,int j2){
	if (   i1>0&&j1>0&&i2>0&&j2>0&&( (matrix[i][j]+matrix[i1][j1]+matrix[i2][j2])==n )
		&&(mark[i][j]==-100||mark[i1][j1]==-100||mark[i2][j2]==-100||mark[i][j]!=mark[i1][j1]||mark[i1][j1]!=mark[i2][j2])   )
			return 1;	
	else 
		return 0;
}//判断三个骰子相加是否为给定值

void test(int i,int j){
	int i1,j1,i2,j2;

	i1=i;j1=j-1;i2=i-1;j2=j;
	if(judge(i,j,i1,j1,i2,j2))	markmat(i,j,i1,j1,i2,j2);

	i1=i;j1=j+1;i2=i-1;j2=j;
	if(judge(i,j,i1,j1,i2,j2))	markmat(i,j,i1,j1,i2,j2);

	i1=i;j1=j-1;i2=i+1;j2=j;
	if(judge(i,j,i1,j1,i2,j2))	markmat(i,j,i1,j1,i2,j2);

	i1=i;j1=j+1;i2=i+1;j2=j;
	if(judge(i,j,i1,j1,i2,j2))	markmat(i,j,i1,j1,i2,j2);

	i1=i;j1=j-1;i2=i;j2=j+1;
	if(judge(i,j,i1,j1,i2,j2))	markmat(i,j,i1,j1,i2,j2);

	i1=i-1;j1=j;i2=i+1;j2=j;
	if(judge(i,j,i1,j1,i2,j2))	markmat(i,j,i1,j1,i2,j2);

}//枚举六种情况判断

int main()
{
	int r,s,i,j,t=1;
	scanf("%d %d %d",&r,&s,&n);
	while(n!=0){
		times=0;
		for (i=0;i<12;i++)
			for (j=0;j<12;j++)
				matrix[i][j]=mark[i][j]=-100;		
		
		for (i=1;i<=r;i++)
			for (j=1;j<=s;j++)
				scanf("%d",&matrix[i][j]);					

		for (i=1;i<=r;i++){
			for (j=1;j<=s;j++){
				test(i,j);
			}
		}
		printf("Array %d has the sum %d appear %d times.\n",t,n,times);
		t++;

		scanf("%d %d %d",&r,&s,&n);
	}

	return 0;
}
