#include <stdio.h>
#include <string.h>
int main()
{
	int n,i;
	int mark[3001];
	int last,now,tmp,flag;
	while(scanf("%d",&n) != EOF){
		flag = 1;
		memset(mark,0,sizeof(mark));
		scanf("%d",&last);
		for (i = 1; i < n ; i++){
			scanf("%d",&now);
			tmp = now - last;
			if(tmp < 0)
				tmp = -tmp;
			if(mark[tmp] == 1 || tmp >= n){
				flag = 0;
			}
			else{
				mark[tmp] = 1;
			}
			last = now;
		}
		if(flag)
			printf("Jolly\n");
		else
			printf("Not jolly\n");

	}
	return 0;
}