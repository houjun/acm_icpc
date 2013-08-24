//博弈题
//找规律:对应和都为21且n可以整出21 或者 n等于21时Carl必输
#include <stdio.h>
 
int main()
{
	int n,i,flag;
	int num[21];
 
	while(scanf("%d",&n),n){
		flag = 1;
		for (i = 1; i <= 20 ; i++){
			scanf("%d",&num[i]);
			if(i + num[i] != 21)
				flag = 0;
		}
		if(flag && n%21 == 0 || n==21)
			printf("Carl can't win\n");
		else
			printf("Carl can win\n");
	}
	return 0;
}