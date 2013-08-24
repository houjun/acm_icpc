#include <stdio.h>
#include <string.h>
int main(){
	char s[50];
	int len,i,sum;
	while(scanf("%s",s),strcmp(s,"#")!=0){
		len=strlen(s);
		sum=0;
		for (i = 0; i < len-1 ; i++){
			if (s[i]=='1')
				sum++;			
		}
		if(sum%2==0){//s has even '1'
			if(s[len-1]=='e')
				s[len-1]='0';
			else
				s[len-1]='1';
		}
		else{
			if(s[len-1]=='o')
				s[len-1]='0';
			else
				s[len-1]='1';
		}
		printf("%s\n",s);

	}


	return 0;
}
