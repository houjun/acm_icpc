// SZU B47.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
#define MAX 1010

/********************************AB�Ƚ�**********************************/
int fcmp(char fa[MAX],char fb[MAX]){	    
	if((strlen(fa)>strlen(fb))||(strlen(fa)==strlen(fb)&&strcmp(fa,fb)>0))
		return 1;
	else if(strcmp(fa,fb)==0)
		return 1;
	else
		return -1;
}
/********************************AB����**********************************/
void swap(char *fa,char *fb){					 
	char t[MAX];
	strcpy(t,fa);strcpy(fa,fb);strcpy(fb,t);
}
/********************************�ӷ�����********************************/
void minus(int *pa,int *pb,int *result){          
	int i;
	for (i=MAX-1;i>=0;i--){
		result[i]+=pa[i]-pb[i];
		if (result[i]<0){						 /*�ж��Ƿ�ý�λ*/
			result[i]+=10;
			result[i-1]--;						 /*��λ*/
		}
	}

}
/*********************************��������********************************/
void add(int *pa,int *pb,int *result){
	int i;
	for (i=MAX-1;i>=0;i--){
		result[i]+=pa[i]+pb[i];
		if (result[i]>=10){						 /*�ж��Ƿ�ý�λ*/
			result[i]-=10;
			result[i-1]++;						 /*��λ*/
		}
	}
}
/************************************************************************/
void print(int *result,int neg){
	int i,flag;
		for(i=0,flag=0;i<MAX;i++){
			if (flag)
				printf("%d",result[i]);				/*����ڶ�����Ľ��*/
			else if(result[i]!=0)
			{
				if(neg==-1)		printf("-");				/*�������λ*/
				printf("%d",result[i]);				/*����ǰ���0�������һ��������*/
				flag=1;
			}
		}
	if(flag==0)		printf("0");					/*��������0ʱ�����*/
	printf("\n");
}

/************************************************************************/
/*                             MAIN ����                                */
/************************************************************************/
int main()
{
	int times,i,j,rs1,rs2,sign1,sign2,cmp,reverse,la,lb;
	char a[MAX],b[MAX];
	scanf("%d",&times);
	while(times--){
		int num1[MAX]={0},num2[MAX]={0},result[MAX]={0};
		reverse=0;								 /*reverse��ʾA+B�Ƿ�ת��ΪA-B*/
		sign1=sign2=1;
		scanf("%s %s",a,b);
		la=strlen(a);lb=strlen(b);
		if(a[0]=='-'){sign1=-1;strncpy(a,a+1,la);la--;}
		if(b[0]=='-'){sign2=-1;strncpy(b,b+1,lb);lb--;}
		if(a[0]=='0'){
			for (i=0;i<la;i++){	
				if(a[i]!='0') break;
			}
				strncpy(a,a+i,la-i+1);
		}
		if(b[0]=='0'){
			for (i=0;i<lb;i++){	
				if(b[i]!='0') break;
			}
			strncpy(b,b+i,lb-i+1);
		}

		cmp=fcmp(a,b);							 /*cmp=1:|A|>|B| 0:|A|=|B| -1:|A|<|B|*/
		if(cmp<0)	swap(a,b);					 /*|A|<|B|����AB*/

		for (i=strlen(a)-1,j=MAX-1;i>=0;i--,j--)	 /*�����ڴ����Ҷ���*/
			num1[j]=a[i]-'0';
		for (i=strlen(b)-1,j=MAX-1;i>=0;i--,j--)
			num2[j]=b[i]-'0';

		if		(sign1==1&&sign2==-1&&cmp==-1)		{rs1=-1;	rs2=1;	}	/*�жϽ���ķ���*/
		else if (sign1==1&&sign2==-1&&cmp==1)		{rs1=1;		rs2=1;	}	/*rs1��A+B����ķ���*/
		else if (sign1==-1&&sign2==1&&cmp==-1)		{rs1=1;		rs2=-1;	}	/*rs2��A-B����ķ���*/
		else if (sign1==-1&&sign2==1&&cmp==1)		{rs1=-1;	rs2=-1;	}
		else if (sign1==-1&&sign2==-1&&cmp==1)		{rs1=-1;	rs2=-1;	}
		else if (sign1==-1&&sign2==-1&&cmp==-1)		{rs1=-1;	rs2=1;  }
		else if (sign1==1&&sign2==1&&cmp==1)		{rs1=1;		rs2=1;	}
		else if (sign1==1&&sign2==1&&cmp==-1)		{rs1=1;		rs2=-1;	}

		if((sign1==-1||sign2==-1)
			&&!(sign1==-1&&sign2==-1))	reverse=1;		/*AB֮һ��һ�������� A+B��ת��ΪA-B*/
	
		if(reverse==0)		add(num1,num2,result);		/*����|A|+|B|*/
		else				minus(num1,num2,result);
		print(result,rs1);

		memset(result,0,sizeof(result));				/*result����*/
		
		if(reverse==0)		minus(num1,num2,result);	/*����|A|-|B|*/
		else				add(num1,num2,result);
		print(result,rs2);





	}

	return 0;
}

