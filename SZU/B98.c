#include <stdio.h>
 
void sort(long a[3]);
 
int main()
{
	int times;
	long a[3],b[3];
	scanf("%d",&times);
	while(times--)
	{
		scanf("%ld%ld%ld",&a[0],&a[1],&a[2]);
		scanf("%ld%ld%ld",&b[0],&b[1],&b[2]);
		sort(a);
		sort(b);	
 
		if (a[0]<=b[0]&&a[1]<=b[1]&&a[2]<=b[2])
			printf("Yes\n");
		else if (b[0]<=a[0]&&b[1]<=a[1]&&b[2]<=a[2])
			printf("Yes\n");
        else
			printf("No\n");
	}
 
	return 0;
}
void sort(long a[3])
{
	int i,j;
	long t;
	for(i=0;i<3;i++)
		for(j=i+1;j<3;j++)
		{
			if (a[i]>a[j])
			{	t=a[i];
				a[i]=a[j];
				a[j]=t;				
			}
		}
 
}