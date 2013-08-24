
#include <stdio.h>
#include <string.h>
#define MAX 220
int main()
{
	char s1[MAX],s2[MAX];
	int i,j,count,l1,l2,a[MAX+1][MAX+1];
	while(scanf("%s%s",s1,s2)!=EOF){
		l1=strlen(s1);
		l2=strlen(s2);
		count=0;
		for (i = 0; i < l1 ; i++){
			a[i][0]=0;
		}
		for (i = 0; i < l2 ; i++){
			a[0][i]=0;
		}
		for (i = 1; i <= l1 ; i++){
			for (j = 1; j <= l2 ; j++){
				if(s1[i-1]==s2[j-1]){
					a[i][j]=a[i-1][j-1]+1;
				}
				else{
					a[i][j]=a[i-1][j]>a[i][j-1]?a[i-1][j]:a[i][j-1];
				}
			}
			
		}
		

		printf("%d\n",a[l1][l2]);

	}

	return 0;
}
