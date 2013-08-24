// A13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h> 
#include <math.h> 

void getarray(int n); 
double getresult(int n); 
int array[10][10];/*设矩阵不超过10阶，可更改*/ 

int main() 
{ 
	int times;
	scanf("%d",&times);
	while(times--){
		int n; 
		double result; 
		scanf("%d",&n); 
		getarray(n); 
		result=getresult(n); 

		printf("%.0lf\n",result); 

	}
	return 0; 
} 

void getarray(int n) 
{ 
	int row,col; 
	for(row=0;row<n;row++) 
	{ 
		for(col=0;col<n;col++) 
			scanf("%d",&array[row][col]); 
	} 
} 


double getresult(int n) 
{ 
	double temp,result=1.0; 
	int switchtime=0,flag=0; 
	int row,nextrow,col,stemp; 
	for(row=0;row<n-1;row++) 
	{ 
		nextrow=row+1; 
		if(array[row][row]==0)/* 开始处理第一列，如果行列式第一行第一个数为零，要交换行 */ 
		{ while(array[nextrow][row]==0) 
		{ 
			nextrow++; /* 如果行列式第二行第一个数为零，行增加继续寻找非零数值的行 */ 
			if(nextrow==n)/* 如果遍历完行列式行列式第一列元素都为零，退出while循环 */ 
			{ flag=1; 
			break; 
			} 
		} 
		if(flag==1) /* 退出while循环后回到for(row=0;row<n-1;row++)行加1?*/ 
			continue; /* 从array[row][row]==0知列也相应加1，开始处理第二列 */ 
		switchtime++; /* 每交换一次行，行列式符号变化1次，统计变化次数 */ 
		for(col=0;col<n;col++) /* 交换非零行到行列式顶部 */ 
		{ 
			stemp=array[row][col]; 
			array[row][col]=array[nextrow][col]; 
			array[nextrow][col]=stemp; 
		} 
		} 
		for(nextrow=row+1;nextrow<n;nextrow++)
		{ /* 类似高斯消去法，消第一行下各行第一列数值到零*/ 
			temp=array[nextrow][row]/array[row][row]; 
			for(col=0;col<n;col++) 
				array[nextrow][col]+=-temp*array[row][col];/* 化行列式为上三角行列式形式 */ 
		} 
	} 
	for(row=0;row<n;row++) 
		result*=array[row][row]; 
	if(switchtime%2) 
		return -result; 
	else 
		return result; 
} 