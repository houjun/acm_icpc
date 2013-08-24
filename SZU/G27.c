#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s[110];
	int number[110];
	int i,len,binum,length;
	while(scanf("%s",s),strcmp(s,"0")!=0){
		binum=0;
		length=len=strlen(s);
		length--;
		//converse the number order
		for (i = 0; i < len ; i++)
			number[len-i-1]=s[i]-'0';
		
		//compute
		while(length>=0||number[0]!=0){
			for (i = len - 1 ; i > 0  ; i--){
				if(number[i]==0)
					continue;
				
				if(number[i] == 1){
					number[i-1] += 10 * number[i]; 
					number[i] = 0;
				}
				
				if(number[i] % 2 != 0){
					number[i-1]+=10;
					number[i]--;
				}						
				number[i]/=2;
			}
			if(number[0]%2==1)
				binum++;
			number[0]/=2;
			while(number[length]==0){
				length--;
			}
			
		}
		printf("%d\n",binum);
		
	}
	return 0;
}