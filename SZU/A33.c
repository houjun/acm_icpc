//一堆煎饼，由上至下需从小到大排列，并且标号+面朝上
//构造法，每次找到待排列的最大的饼，翻到顶，在翻到最终位置
//可能有些已在最终位置或顶部，需判断，翻到最顶上后需保证其为-使得再翻为+
//这题纠结了好久，后来看到题中给的最多3n-2，想到构造法
//构造法每个饼从任意位置到最终位置最多只需三步
//（翻到顶；如为-在翻该饼；翻到指定位置）
//而最上一张最多只需在其为-时翻一下，故最多3n-2
#include <stdio.h>
int cake[31],sq[100],count;
void flip(int h)
{
	int i,j,tmp;
	i = 0;
	j = h;
	while(i<j){
		tmp = cake[i];
		cake[i] = -cake[j];
		cake[j] = -tmp;
		i++,j--;
	}
	if(i == j)
		cake[i] = -cake[i];
	sq[count++] = h + 1;	
}
int main()
{
	int cases,minus;
	int n,i,j,t;
	char tmp;
	scanf("%d",&cases);
	for(t = 1; t <= cases; t++){
		count = 0;
		scanf("%d",&n);
 
		for (i = 0; i < n ; i++){
			scanf(" %c%d",&tmp,&cake[i]);
			if(tmp == '-')
				cake[i] *= -1;
		}
 
		for (i = n; i > 0 ; i--){
			for (j = 0; j < n ; j++){
				if(cake[j] == i || cake[j] == -i )
					break;
			}
			if(j != 0 && cake[j] != j + 1 ){
				flip(j);
				if (i != 1){
					if(cake[0] > 0)
						flip(0);
					flip(i - 1);			
				}
			}
			else if(i != 1 && j == 0){
				if(cake[0] > 0)
					flip(0);
				flip(i - 1);
			}
		}
		if(cake[0] < 0)
			flip(0);
		printf("%d %d",t,count);
		for (i = 0; i < count ; i++){
			printf(" %d",sq[i]);
		}
		printf("\n");
	}
	return 0;
}