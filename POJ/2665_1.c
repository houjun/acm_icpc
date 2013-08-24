#include<stdio.h>

int main()
{
    int len,n,a,b;
    int i,j;
    while(scanf("%d%d",&len,&n),len||n)
    {
        len++;
        for(i=0;i<n;i++)scanf("%d %d",&a,&b),len-=(b-a+1);
        printf("%d\n",len);
    }    
    return 0;
}    