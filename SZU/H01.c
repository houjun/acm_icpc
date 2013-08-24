//RGB颜色匹配，给出16个基础RGB颜色，再给出一些RGB，根据给定公式
//求与那个基础颜色公式值最小
//枚举每个值，记录最小。
#include <stdio.h>
#include <math.h>
int main()
{
	int target[16][3];
	int i,r1,g1,b1,record;
	double min,d;
	for (i = 0; i < 16 ; i++){
		scanf("%d%d%d",&target[i][0],&target[i][1],&target[i][2]);
	}
	while(scanf("%d%d%d",&r1,&g1,&b1),r1!=-1){
		min = 1234567;
		for (i = 0; i < 16 ; i++){
			d = sqrt((target[i][0]-r1)*(target[i][0]-r1)+(target[i][1]-g1)*(target[i][1]-g1)+(target[i][2]-b1)*(target[i][2]-b1));
			if(d < min){
				min = d;
				record = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",r1,g1,b1,target[record][0],target[record][1],target[record][2]);
	}
	return 0;
}