
#include <stdio.h>
#include <string.h>
#define MAX 5010
char s1[MAX],s2[MAX];
short a[MAX+1][MAX+1];
int main()
{
	int i,j,count,l1;

		scanf("%d",&l1);
		scanf("%s",s1);
		for (i = 0; i < l1 ; i++){
			s2[i]=s1[l1-i-1];
		}
		s2[i]='\0';
		count=0;
		for (i = 0; i < l1 ; i++){
			a[0][i]=a[i][0]=0;
		}
		for (i = 1; i <= l1 ; i++){
			for (j = 1; j <= l1 ; j++){
				if(s1[i-1]==s2[j-1]){
					a[i][j]=a[i-1][j-1]+1;
				}
				else{
					a[i][j]=a[i-1][j]>a[i][j-1]?a[i-1][j]:a[i][j-1];
				}
			}	
		}
		
		printf("%d\n",l1-a[l1][l1]);
		
	
	
	return 0;
}
