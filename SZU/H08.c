//给出每个人买每轮彩票的数目，求每个人赢钱数最多的概率分数
//奖金是2的幂，所以只要赢最后一轮，一定赢钱最多
//算出应最后一轮的概率并约分
#include <stdio.h>
 
int gcd(int a, int b)  // a>=b
{
	int t =  a% b;
	while( t > 0 )
	{
		a= b;
		b= t;
		t = a%b;   
	}
	return b;
} 
int main()
{
	int n,m,i,j,t;
	int tmp,total;
	int p[10001];
	while(scanf("%d%d",&n,&m),n&&m){
		total = 0;
		for (i = 0; i < n ; i++){
			for (j = 0; j < m-1 ; j++){
				scanf("%d",&tmp);
			}
			scanf("%d",&p[i]);
			total += p[i];
		}
		for (i = 0; i < n ; i++){
			if(p[i] != 0){
				t = gcd(total,p[i]);
				printf("%d / %d\n",p[i]/t,total/t);
			}
			else
				printf("0 / 1\n");
		}
 
	}
	return 0;
}