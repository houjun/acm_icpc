#include <stdio.h>
#include <stdlib.h>
 
int main()
{
	int i,j;
	int n,now,flag,on,off;
	while(scanf("%d",&n),n){
		flag=1;
		now=0;
		for(i=0;i<n;i++){
			scanf("%d%d",&off,&on);
			now-=off;
			if(now<0)
				flag=0;
			now+=on;
		}
		if(now!=0)
			flag=0;
 
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
 
	}
 
	return 0;
}