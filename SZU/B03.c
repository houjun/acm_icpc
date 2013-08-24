//Bell Number
//递推公式为:
//B(0) = 1,B(n+1) = Sum(0,n) C(n,k)B(k). n = 1,2,...
//其中，Sum(0,n)表示对k从0到n求和，C(n,k) = n!/[k!(n-k)!]
#include <stdio.h>

long double C(int n,int m)
{
    long double c=1.0;
	if(m==0||n==0)
		return 1.0;
    int i=m;
    while(i!=0)
        {c*=n;n--;i--;}
    while(m!=0)
        {c/=m;m--;}
    return c;
} 


int main()
{
	int  i,j,num;
	long double B[1000]={1.0};
	
	while(scanf("%d",&num),num){
		if (num==1.0)
			printf("1 1\n");
		else{
			for (i = 0; i < num ; i++){
				B[i+1]=0.0;
				for (j = 0; j <= i ; j++){
					B[i+1]+=C(i,j)*B[j];					
				}
			}
			printf("%d %.0llf\n",num,B[num]);
		}

	}
	return 0;
}
