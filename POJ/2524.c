//说下题目大意。已知有n个大学生，其中有m对宗教信仰相同的学生，请你估算这n个学生中最多有多少种宗教信仰。

//依旧是简单的并查集应用。宗教信仰的最大值为学生数n，因此一开始把n个学生作为n个集合，对给出的每对大学生 a 和 b ，如果他们在不同的集合，就合并他们
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51
int father[MAX], rank[MAX];
 
void init(int n)
{
	father[n] = n;
	rank[n] = 0;
}

int findset(int n)
{
	while(father[n] != n){
		n = findset(father[n]);
	}
	return father[n];
}

void unionset(int x,int y)
{
	if(x == y)	return;
	if(rank[x] > rank[y])
		father[y] = father[x];
	else{
		if(rank[x] == rank[y])
			rank[y] ++;
		father[x] = father[y];
	}
}

int main()
{
	int m,n,a,b,i,res,t = 1;
	while(scanf("%d%d",&m,&n),m){
		for (i = 1; i <= m ; i++)
			init(i);
		for (i = 0; i < n ; i++){
			scanf("%d%d",&a,&b);
			a = findset(a);
			b = findset(b);
			unionset(a,b);
		}
		res = m;
		for (i = 1; i <= m ; i++){
			if(father[i] != i)
				res--;
		}
		printf("Case %d: %d\n",t++,res);
			
		
	}
	return 0;
}