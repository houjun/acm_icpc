#include<stdio.h>
int A[500010];
int table[3500000]={0};

int main()
{
	int n;      
	int i,t;
	A[0]=0;
	for(i=1;i<=500000;i++)
	{
		t=A[i-1]-i;
		if(t>0&&!table[t])
			A[i]=t;
		else
			A[i]=A[i-1]+i;
		table[A[i]]=1;
	}
      scanf("%d",&n);
      while(n!=-1)
      {
		  printf("%d\n",A[n]);
		  scanf("%d",&n);
      }
      return 0;
}