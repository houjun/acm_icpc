#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
	int i,j;
	char op[10];
	double water,salt,t,w;
	scanf("%lf%lf",&water,&salt);
	while(scanf("%s",op),strcmp(op,"exit")!=0){
		switch(op[2]){
		case 'l'://salt
			scanf("%lf",&t);
			salt+=t;
			break;
		case 't'://water
			scanf("%lf",&t);
			water+=t;
			break;
		case 'o':
			w=salt/(salt+water);
			printf("%.4lf\n",w);	
 
 
		}
 
 
	}
 
 
	return 0;
}