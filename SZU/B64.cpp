//给出一系列连通的两点，或询问两点是否连通，统计询问时连通不连通的数量
//采用并查集模版
#include <stdio.h>
#include <string.h>
#define MAXN 10000
#define _ufind_run(x) for(;p[t=x];x=p[x],p[t]=(p[x]?p[x]:x))
#define _run_both _ufind_run(i);_ufind_run(j)

struct ufind{
	int p[MAXN],t;
	void init(){memset(p,0,sizeof(p));}
	void set_friend(int i,int j){_run_both;p[i]=(i==j?0:j);}
	int is_friend(int i,int j){_run_both;return i==j&&i;}
};
int main()
{
	int cases,n,a,b,y,no,t = 0;
	ufind net;
	char c;
	scanf("%d",&cases);
	while(cases--){
		if(t != 0)
			printf("\n");
		t++;
		net.init();
		y = no = 0;
		scanf("%d",&n);
		getchar();
		while(c = getchar(),c != EOF){
			if(c == '\n')	break;
			scanf(" %d %d",&a,&b);
			if(c == 'c'){
				net.set_friend(a,b);
			}
			else if(c == 'q'){
				if(net.is_friend(a,b) == 1 )
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