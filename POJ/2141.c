#include <stdio.h>
int main()
{
	char map[27],c;
	scanf("%s",map);
	getchar();
	while(scanf("%c",&c)!=EOF){
		if(c>='a'&&c<='z')
			printf("%c",map[c-'a']);
		else if(c>='A'&&c<='Z')
			printf("%c",map[c-'A']-32);
		else
			printf("%c",c);
	}
	return 0;
}
