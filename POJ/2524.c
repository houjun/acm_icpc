//˵����Ŀ���⡣��֪��n����ѧ����������m���ڽ�������ͬ��ѧ�������������n��ѧ��������ж������ڽ�������

//�����Ǽ򵥵Ĳ��鼯Ӧ�á��ڽ����������ֵΪѧ����n�����һ��ʼ��n��ѧ����Ϊn�����ϣ��Ը�����ÿ�Դ�ѧ�� a �� b ����������ڲ�ͬ�ļ��ϣ��ͺϲ�����
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