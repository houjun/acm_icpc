// SZU B47.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
#define MAX 1010

/********************************AB比较**********************************/
int fcmp(char fa[MAX],char fb[MAX]){	    
	if((strlen(fa)>strlen(fb))||(strlen(fa)==strlen(fb)&&strcmp(fa,fb)>0))
		return 1;
	else if(strcmp(fa,fb)==0)
		return 1;
	else
		return -1;
}
/********************************AB互换**********************************/
void swap(char *fa,char *fb){					 
	char t[MAX];
	strcpy(t,fa);strcpy(fa,fb);strcpy(fb,t);
}
/********************************加法计算********************************/
void minus(int *pa,int *pb,int *result){          
	int i;
	for (i=MAX-1;i>=0;i--){
		result[i]+=pa[i]-pb[i];
		if (result[i]<0){						 /*判断是否该进位*/
			result[i]+=10;
			result[i-1]--;						 /*进位*/
		}
	}

}
/*********************************减法计算********************************/
void add(int *pa,int *pb,int *result){
	int i;
	for (i=MAX-1;i>=0;i--){
		result[i]+=pa[i]+pb[i];
		if (result[i]>=10){						 /*判断是否该借位*/
			result[i]-=10;
			result[i-1]++;						 /*借位*/
		}
	}
}
/************************************************************************/
void print(int *result,int neg){
	int i,flag;
		for(i=0,flag=0;i<MAX;i++){
			if (flag)
				printf("%d",result[i]);				/*输出第二个起的结果*/
			else if(result[i]!=0)
			{
				if(neg==-1)		printf("-");				/*输出符号位*/
				printf("%d",result[i]);				/*跳过前面的0并输出第一个非零数*/
				flag=1;
			}
		}
	if(flag==0)		printf("0");					/*避免结果是0时零输出*/
	printf("\n");
}

/************************************************************************/
/*                             MAIN 函数                                */
/************************************************************************/
int main()
{
	int times,i,j,rs1,rs2,sign1,sign2,cmp,reverse,la,lb;
	char a[MAX],b[MAX];
	scanf("%d",&times);
	while(times--){
		int num1[MAX]={0},num2[MAX]={0},result[MAX]={0};
		reverse=0;								 /*reverse表示A+B是否转换为A-B*/
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
		if(cmp<0)	swap(a,b);					 /*|A|<|B|交换AB*/

		for (i=strlen(a)-1,j=MAX-1;i>=0;i--,j--)	 /*大数在串中右对齐*/
			num1[j]=a[i]-'0';
		for (i=strlen(b)-1,j=MAX-1;i>=0;i--,j--)
			num2[j]=b[i]-'0';

		if		(sign1==1&&sign2==-1&&cmp==-1)		{rs1=-1;	rs2=1;	}	/*判断结果的符号*/
		else if (sign1==1&&sign2==-1&&cmp==1)		{rs1=1;		rs2=1;	}	/*rs1是A+B结果的符号*/
		else if (sign1==-1&&sign2==1&&cmp==-1)		{rs1=1;		rs2=-1;	}	/*rs2是A-B结果的符号*/
		else if (sign1==-1&&sign2==1&&cmp==1)		{rs1=-1;	rs2=-1;	}
		else if (sign1==-1&&sign2==-1&&cmp==1)		{rs1=-1;	rs2=-1;	}
		else if (sign1==-1&&sign2==-1&&cmp==-1)		{rs1=-1;	rs2=1;  }
		else if (sign1==1&&sign2==1&&cmp==1)		{rs1=1;		rs2=1;	}
		else if (sign1==1&&sign2==1&&cmp==-1)		{rs1=1;		rs2=-1;	}

		if((sign1==-1||sign2==-1)
			&&!(sign1==-1&&sign2==-1))	reverse=1;		/*AB之一有一个带负号 A+B是转换为A-B*/
	
		if(reverse==0)		add(num1,num2,result);		/*计算|A|+|B|*/
		else				minus(num1,num2,result);
		print(result,rs1);

		memset(result,0,sizeof(result));				/*result清零*/
		
		if(reverse==0)		minus(num1,num2,result);	/*计算|A|-|B|*/
		else				add(num1,num2,result);
		print(result,rs2);





	}

	return 0;
}

