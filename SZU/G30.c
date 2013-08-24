#include <stdio.h>
int main()
{
	int i,j;
	double score[10];
	double maxscore,minscore,sum;
	int cases;
	scanf("%d",&cases);
	while(cases--){
		maxscore=0.0;
		minscore=20.0;
		sum=0.0;
		scanf("%lf",&score[0]);
		for(i=1;i<8;i++){
			scanf("%lf",&score[i]);
			sum+=score[i];
			if(score[i]>maxscore)
				maxscore=score[i];
			if(score[i]<minscore)
				minscore=score[i];
		}
		sum-=minscore+maxscore;
		sum/=5.0;
		sum*=score[0];
		printf("%.4lf\n",sum);
 
 
	}
 
	return 0;
}