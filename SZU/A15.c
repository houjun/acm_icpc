#include <stdio.h>
#include <stdlib.h>
#define INF 2147483647 
#define MAX 1010
int cmp( const void *a , const void *b ) 
{ 
	return *(int *)a > *(int *)b ? 1 : -1; 
} 
int bs(int a[], int l, int h, int v){ 
     int m; 
     while ( l < h ){ 
         m = ( l + h ) >> 1; 
         if (a[m] == v) return v; 
         if (a[m] <  v) l=m+1; 
         else             h=m; 
     } 
     return INF; 
}

int main()
{
	int num[MAX];
	int cases,n,i;
	int begin,end, free,t;
	scanf("%d",&cases);
	while(cases--){
		free=INF;
		scanf("%d",&n);
		for ( i = 0; i < n ; i++)
			scanf("%d",&num[i]);
		qsort(num,n,sizeof(num[0]),cmp);
 	for ( begin = 0 ; begin < n - 2 ; begin++){
			for ( end = begin + 2; end < n ; end++){
				if ((num[begin]+num[end])%2!=0)
					continue;
				else{
					t=(num[begin]+num[end])/2;
					free=bs(num,begin+1,end,t);
					if(free==t){
						goto NOT;
					}
				}
			}
		}

		if (free==INF){
			printf("Triple-Free\n");
			continue;
		}
		NOT:	printf("Triple-NotFree\n");
	}
	return 0;
}
