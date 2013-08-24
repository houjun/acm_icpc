
#include "stdafx.h"

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode, *HuffmanTree;

void Select(HuffmanTree HT,unsigned int i1,unsigned int *s1,unsigned int *s2)
{
	unsigned int j,s;
	
	s=0;
	for(j=1;j<=i1;j++)
	{
		if(HT[j].parent==0)
		{
			if(s==0)
				s=j;
			if(HT[j].weight<HT[s].weight)
				s=j;
		}
	}
	*s1=s;
	
	s=0;
	for(j=1;j<=i1;j++)
	{
		if((HT[j].parent==0)&&(j!=*s1))
		{
			if(s==0)
				s=j;
			if(HT[j].weight<HT[s].weight)
				s=j;
		}
	}
	*s2=s;
}


int main(int argc, char* argv[])
{
	int w[MAX];
	char cd[MAX];
	unsigned int i,m,n,c,f,s1,s2,start;
	
	printf("Please input the total number:");
	scanf("%d",&n);
	m=2*n-1;

	printf("Please input the weigh of each input:\n");
	for (i=0;i<n;i++)
		scanf("%d",&w[i]);
	
	HuffmanTree HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
	for(i=1;i<=n;++i)
	{
		HT[i].weight=w[i-1];
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for(;i<=m;++i)
	{
		HT[i].weight=0;
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	
	for(i=n+1;i<=m;++i)
	{
		Select(HT,i-1,&s1,&s2);
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	
	cd[n-1]=0;
	for(i=1;i<=n;i++)
	{
		start=n-1;
		for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
		{
			if(HT[f].lchild==c)
				cd[--start]='0';
			else
				cd[--start]='1';
		}
		printf("%c=%d,code=%s\n",i+'A'-1,HT[i].weight,&cd[start]);
	}
	return 0;
}


