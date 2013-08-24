//给出一至二十的英文，求A+B
//字符串搜索，再计算，输出对应结果即可
#include <stdio.h>
#include <string.h>
char num[21][10]={" ","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
int main()
{
	int i,t,a,b;
	char n[10],aa[10],bb[10];
	scanf("%s",n);
	for(i=1;i<=20;i++){
		if(strcmp(n,num[i])==0)
			t=i;
	}
	while(t--){
		scanf("%s%s",aa,bb);
		for(i=1;i<=20;i++){
			if(strcmp(aa,num[i])==0)
				a=i;
		}
		for(i=1;i<=20;i++){
			if(strcmp(bb,num[i])==0)
				b=i;
		}
		printf("%s\n",num[a+b]);
 
	}
 
	return 0;
}