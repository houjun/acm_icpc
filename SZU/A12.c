#include <stdio.h>
 
int main()
{
	int times,timess;
	int jump[100];
	int i,count,max=0;
 
	scanf("%d",&times);
	while(times--){
		scanf("%d",&timess);
		for(i=0;i<timess;i++)
			scanf("%d",&jump[i]);
		count=0;
		max=0;
 
		for(i=1;i<timess;i++){			
			if(jump[i]==jump[i-1]){
				if(count>max)
					max=count;
				count=0;
			}
			else 
				count++;
		}
	if(count>max)
		max=count;
	max++;
	printf("%d\n",max);
 
	}
	    return 0; 
 
}