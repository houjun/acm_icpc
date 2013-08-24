#include <stdio.h>
#include <string.h>
int main(){

	char map[]={'V','W','X','Y','Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U'};
	char s[250];
	char t[250];
	int i,len;
	while(scanf("%s",t),strcmp(t,"ENDOFINPUT")!=0){
		gets(t);
		gets(s);
		gets(t);
		len=strlen(s);
		for (i = 0; i < len ; i++){
			if(s[i]>='A'&&s[i]<='Z')
				printf("%c",map[s[i]-'A']);
			else
				printf("%c",s[i]);
		}
		printf("\n");
	}
	return 0;
}
