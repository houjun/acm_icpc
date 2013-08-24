#include <stdio.h>
#include <string.h>
#define MAX 201
int main(){
	int cases,t,i,j,result,len1,len2;
	char s1[MAX],s2[MAX],s3[MAX+MAX];
	char ans[2][5]={"no","yes"};
	char form[MAX+MAX][MAX+MAX]={'\0'};
	scanf("%d",&cases);
	for (t = 1; t <= cases ; t++){
		scanf("%s %s %s",s1,s2,s3);
		len2=strlen(s2);
		len1=strlen(s1);

		//DP
		for (i = 0; i <= len2 ; i++){
			for (j = 0; j <= len1 ; j++){
				if (i==0&&j==0)
					form[i][j]='1';
				else if(		form[i-1][j]=='1'&&s3[i+j-1]==s2[i-1]
					  ||form[i][j-1]=='1'&&s3[i+j-1]==s1[j-1])
					form[i][j]='1';
				else
					form[i][j]='0';
			}
		}

		result=form[len2][len1]-'0';
		printf("Data set %d: %s\n",t,ans[result]);
	}
	return 0;
}