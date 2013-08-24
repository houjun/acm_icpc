#include "stdafx.h"


#include <stdio.h>
#include <string.h>
char map[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};
void convert(int num,int base,char number[200]){				/*store it in number[10]*/
	int t=0,tmp;
	while(num){
		tmp=num%base;
		number[t++]=map[tmp];
		num/=base;
	}
	number[t]='\0';
}
int test(char number[200]){
	int l;
	char *pfront,*pback;
	l=strlen(number);
	pfront=&number[0];
	pback=&number[l-1];
	while(pfront<=pback){
		if(*pfront!=*pback)	
			return 0;
		pback--;pfront++;
	}
	return 1;
}
int main()
{

	int base,i,j,times,n;
	char number[200];
	char num1[200];
	scanf("%d",&times);
	while(times--){
		scanf("%d %d",&n,&base);
		for(i=1;i<n;i++){							/*generate n square from n=1 to 300*/
			convert(i*i,base,number);					/*convert n*n to number in base b*/
			if(test(number)){	
				convert(i,base,num1);
				for(j=strlen(num1)-1;j>=0;j--)
					printf("%c",num1[j]);
					printf(" %s\n",number);
			}
		}
	}





	return 0;
}
