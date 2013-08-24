
#include <stdio.h>
#include <stdlib.h>
int a[10000];
int prime(int a[],int n)
{
    int i,j,k,x,num,*b;
    n++;
    n/=2;
    b=(int *)malloc(sizeof(int)*(n+1)*2);
    a[0]=2;a[1]=3;num=2;
    for(i=1;i<=2*n;i++)
        b[i]=0;
    for(i=3;i<=n;i+=3)
        for(j=0;j<2;j++)
		{
            x=2*(i+j)-1;
            while(b[x]==0)
			{
                a[num++]=x;
                for(k=x;k<=2*n;k+=x)
                    b[k]=1;
			}
		}
		return num;
}

int main()
{
	int n,i,j,t,s;
	prime(a,10000);
	while(scanf("%d",&n),n!=0){
		t=0;
		for (i = 0; a[i] <= n ; i++){
			for (j = i,s=0; s <= n ; j++){
				s+=a[j];
				if(s==n)
					t++;
			}
		}
		printf("%d\n",t);
	}
	return 0;
}
