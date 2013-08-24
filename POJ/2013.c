
#include <stdio.h>
int main()
{
	int times,i,j;
	char s[16][26];
	j=0;
	while(scanf("%d",&times),times!=0){
		j++;
		for (i = 0; i < times ; i++){
			scanf("%s",s[i]);			
		}
		printf("SET %d\n",j);
		for (i = 0; i < times ; i+=2){
			printf("%s\n",s[i]);
		}
		if(i==times+1)
			i=times-2;
		else
			i=times-1;
		for (; i >=0 ; i-=2){
			printf("%s\n",s[i]);
		}
	}
	return 0;
}
