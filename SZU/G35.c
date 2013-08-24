#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAX 10010
 
int cmp ( const void *a , const void *b ) 
{ 
return *(int *)a - *(int *)b; 
} 
 
 
int main()
{
	int i,j,t;
	int n,m,total;
	int num[MAX];
 
	while(scanf("%d%d",&n,&m),n&&m){
		total=0;
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
 
		qsort(num,n,sizeof(num[0]),cmp); 
		t=0;
		for(i=n-1;i>=t;i--){
			for(j=t;j<i;j++){
				if(num[i]+num[j]>=m){
					total++;
					j++;
					t=j;
					break;
				}
			}
 
		}
		printf("%d\n",total);		
 
	}
 
	return 0;
}