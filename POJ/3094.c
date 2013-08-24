#include <stdio.h>
#include <string.h>
int main()
{
	char a[256];
	int l,i,r;
	while(gets(a),strcmp(a,"#")!=0){
		r=0;
		l=strlen(a);
		for (i = 0; i < l ; i++){
			if(a[i]!=' ')
				r+=(i+1)*(a[i]-'A'+1);
		}
		printf("%d\n",r);
	}
	return 0;
}
