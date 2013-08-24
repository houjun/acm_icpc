//有N灯，走第i趟按下i的整数倍的开关，求N趟后，最后一盏灯的情况
//转换为判断整数N有奇数或是偶数个因子，只有完全平方数有偶数个
//所以完全平方数最后一盏为OFF
#include <stdio.h>
#include <math.h>
int main()
{
	int n,t;
	while(1){
		scanf("%d",&n);
		if(n==0)
		        break;
		t = sqrt(n);
		t *= t;
		if(t==n)
             printf("ON\n");
        else
            printf("OFF\n");
 
	}
 
	return 0;
}