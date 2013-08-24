//给出国家名和比赛结果，求最终排名
//以此读取比赛情况，记录积分，从大到小输出
#include <stdio.h>
#include <string.h>
int main()
{
	int teams,matchs;
	char team[33][15],first[15],second[15],t[5];
	int score[33]={0};
	int i,j,k,t1,t2;
	scanf("%d",&teams);
	for ( i = 0; i < teams ; i++){
		scanf("%s",team[i]);
	}
	scanf("%d",&matchs);
	for (i = 0; i < matchs ; i++){
		scanf("%s %s %s %d:%d",first,t,second,&t1,&t2);
		for (j = 0; j < teams ; j++){
			if (strcmp(first,team[j]) == 0)
				break;			
		}
		for (k = 0; k < teams ; k++){
			if (strcmp(second,team[k]) == 0)
				break;			
		}
		if (t1 > t2)
			score[j] += 3;
		else if(t1 < t2)
			score[k] +=3;
		else{
			score[j]++;
			score[k]++;
		}
	}
	k = 1;
	for (i = 100; i >= 0 ; i--){
		for (j = 0; j < teams ; j++){
			if(score[j] == i)
				printf("%d %s %d\n",k++,team[j],score[j]);
		}
	}
	return 0;
}