//DP
#include <stdio.h>
#define max2(a,b) (a)>(b)?(a):(b)
#define MAX 110
int map[5][5]={ 5,-1,-2,-1,-3,
			   -1, 5,-3,-2,-4,
			   -2,-3, 5,-2,-2,
			   -1,-2,-2, 5,-1,
			   -3,-4,-2,-1, 0 };

int convert(char a){
	if	   (a=='A')	return 0;
	else if(a=='C')	return 1;
	else if(a=='G')	return 2;
	else if(a=='T')	return 3;
	else			return 4;
}

int op(char a,char b){
	return	map[convert(a)][convert(b)];
}

int mymax(int a,int b,int c){
	int t=max2(a,b);
	return max2(t,c);
}
int main(){
	char s1[MAX],s2[MAX];
	int result[MAX][MAX];
	int times,len1,len2,i,j;
	scanf("%d",&times);
	while(times--){
		scanf("%d %s",&len1,s1);
		scanf("%d %s",&len2,s2);
		
		result[0][0]=0;
		//NULL with S1
		for (i = 1; i <= len1 ; i++)
			result[0][i]=result[0][i-1]+op('-',s1[i-1]);		
		//NULL with S2
		for (i = 1; i <= len2 ; i++)
			result[i][0]=result[i-1][0]+op('-',s2[i-1]);

		for (i = 1; i <= len2 ; i++){
			for (j = 1; j <= len1 ; j++){
				result[i][j]=mymax(	result[i-1][j-1]+op(s1[j-1],s2[i-1]),
									result[i-1][j  ]+op(s2[i-1],'-'),
									result[i  ][j-1]+op(s1[j-1],'-')	);
			}
		}
		
		printf("%d\n",result[len2][len1]);

	}

	return 0;
}