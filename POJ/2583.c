
#include <stdio.h>
int main()
{
	int x,y,z;
	while(scanf("%d %d %d",&x,&y,&z)!=EOF){
		printf("%d %d %d\n",3*z+x-3*y,-8*y+3*x+6*z,-15*y+6*x+10*z);

	}
	return 0;
}
