#include <stdio.h>
#include <string.h>
#define MAX 30
int prefix(char *a,char *b,int la,int lb){//la<lb
	int i,flag=1;
	if(la>lb)	return 0;
	for (i = 0; i < la ; i++){
		if(a[i]!=b[i]){
			flag=0;
			break;
		}			
	}
	return flag;
}
int suffix(char *a,char *b,int la,int lb){
	int i,flag=1,j=lb-1;
	if(la>lb)	return 0;
	for (i = la-1; i >= 0 ; i--,j--){
		if(a[i]!=b[j]){
			flag=0;
			break;
		}			
	}
	return flag;
}
int main()
{
	char s[3][MAX];
	int cases,freeall,i,j;
	scanf("%d",&cases);
	while(cases--){
		freeall=0;
		for (i = 0; i < 3 ; i++){
			scanf("%s",s[i]);
		}
		for (i = 0; i < 3&&!freeall ; i++){
			for (j = 0; j < 3 ; j++){
				if(i!=j){
					freeall=prefix(s[i],s[j],strlen(s[i]),strlen(s[j]));
					freeall=suffix(s[i],s[j],strlen(s[i]),strlen(s[j]));
					if(freeall)
						break;
				}
			}
		}
		if(freeall)	printf("No\n");
		else		printf("Yes\n");

	}
	return 0;
}
