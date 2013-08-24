#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10001
int father[MAX], num[MAX];
 
void Make_Set(int x)
{
	father[x] = x;
	num[x] = 0;
}
 
int Find_Set(int x)
{
	if (x != father[x])
		father[x] = Find_Set(father[x]);
	return father[x];
}
void Union_Set(int a, int b)
{
	if (a == b) return;
	if (num[a] <= num[b]){
		father[a] = b;
		num[b] += num[a];
	}
	else{
		father[b] = a;
		num[a] += num[b];
	}
}
 
int main()
{
	int cases,n,i,a,b,y,no,t = 0;
	char c;
	scanf("%d",&cases);
	while(cases--){
		if(t != 0)
			printf("\n");
		t++;
		scanf("%d",&n);
		for (i = 0; i <= n; i++)
			Make_Set(i);
		y = no = 0;
		getchar();
		while(c = getchar(),c != EOF){
			if(c == '\n')	break;
			scanf(" %d %d",&a,&b);
			a = Find_Set(a);
			b = Find_Set(b);
			if(c == 'c')
				Union_Set(a,b);
			else if(c == 'q'){
				if(a == b)
					y++;
				else
					no++;
			}
			else
				break;
			getchar();
		}		
		printf("%d,%d\n",y,no);
	}
	return 0;
}