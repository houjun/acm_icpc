#include <stdio.h>
#include <string.h>
int att[500][100];

int main()
{
	int n=1,d=1,i,j,flag,gotone;
	while (scanf("%d %d",&n,&d),n&&d){
		memset(att,0,sizeof(att));
		for (i=0;i<d;i++){
			for (j=0;j<n;j++)
				scanf("%d",&att[i][j]);
		}
		
		for (i=0,gotone=0;i<n;i++){
			
			for (j=0,flag=1;j<d;j++){
				if(att[j][i]==0){
					flag=0;
				}
			}
			if(flag){
				gotone=1;
				break;
			}
		}
		if(gotone)	printf("yes\n");
		else		printf("no\n");
		
	}
	return 0;
}