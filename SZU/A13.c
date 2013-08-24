// A13.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h> 
#include <math.h> 

void getarray(int n); 
double getresult(int n); 
int array[10][10];/*����󲻳���10�ף��ɸ���*/ 

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
		if(array[row][row]==0)/* ��ʼ�����һ�У��������ʽ��һ�е�һ����Ϊ�㣬Ҫ������ */ 
		{ while(array[nextrow][row]==0) 
		{ 
			nextrow++; /* �������ʽ�ڶ��е�һ����Ϊ�㣬�����Ӽ���Ѱ�ҷ�����ֵ���� */ 
			if(nextrow==n)/* �������������ʽ����ʽ��һ��Ԫ�ض�Ϊ�㣬�˳�whileѭ�� */ 
			{ flag=1; 
			break; 
			} 
		} 
		if(flag==1) /* �˳�whileѭ����ص�for(row=0;row<n-1;row++)�м�1?*/ 
			continue; /* ��array[row][row]==0֪��Ҳ��Ӧ��1����ʼ����ڶ��� */ 
		switchtime++; /* ÿ����һ���У�����ʽ���ű仯1�Σ�ͳ�Ʊ仯���� */ 
		for(col=0;col<n;col++) /* ���������е�����ʽ���� */ 
		{ 
			stemp=array[row][col]; 
			array[row][col]=array[nextrow][col]; 
			array[nextrow][col]=stemp; 
		} 
		} 
		for(nextrow=row+1;nextrow<n;nextrow++)
		{ /* ���Ƹ�˹��ȥ��������һ���¸��е�һ����ֵ����*/ 
			temp=array[nextrow][row]/array[row][row]; 
			for(col=0;col<n;col++) 
				array[nextrow][col]+=-temp*array[row][col];/* ������ʽΪ����������ʽ��ʽ */ 
		} 
	} 
	for(row=0;row<n;row++) 
		result*=array[row][row]; 
	if(switchtime%2) 
		return -result; 
	else 
		return result; 
} 