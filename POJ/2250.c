#include <stdio.h>
#include <string.h>
#define MAX 110
char s1[MAX][32],s2[MAX][32];
int a[MAX+1][MAX+1],path[MAX+1][MAX+1],t;

void findpath(int i,int j){
	if(i==0||j==0)
		return;
	
	if(path[i][j]==0){
		findpath(i-1,j-1);
		if(t==0)	printf("%s",s1[i]);
		else		printf(" %s",s1[i]);
		t++;
	}
	else if(path[i][j]==-1)
		findpath(i-1,j);
	
	else if(path[i][j]==1)
		findpath(i,j-1);
	
}
int main()
{
	int i,j,l1,l2;
	while(scanf("%s",s1[1])!=EOF){
		t=0;
		for (i = 2; i < MAX ; i++){
			scanf("%s",s1[i]);
			if(strcmp(s1[i],"#")==0){
				l1=i-1;
				break;
			}
		}//get s1
		for (i = 1; i <= MAX ; i++){
			scanf("%s",s2[i]);
			if(strcmp(s2[i],"#")==0){
				l2=i-1;
				break;
			}
		}//get s2

		for (i = 0; i < MAX ; i++){
			a[i][0]=a[0][i]=0;
		}//init a[][]

		for (i = 1; i <= l1 ; i++){
			for (j = 1; j <= l2 ; j++){
				if (strcmp(s1[i],s2[j])==0){
					a[i][j]=a[i-1][j-1]+1;
					path[i][j]=0;
				}
				else{
					if(a[i-1][j]>=a[i][j-1]){
						a[i][j]=a[i-1][j];
						path[i][j]=-1;
					}
					else{
						a[i][j]=a[i][j-1];
						path[i][j]=1;
					}
				}

			}
		}
		findpath(l1,l2);
		printf("\n");
	
	
	}
	
	return 0;
}
