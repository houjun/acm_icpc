#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>
int A[30000][5];
void sort(int A[][5],int p,int l,int r)
{
    int tmp[5];
    int i,j,k,s;
    if(l>=r)
    return;
    tmp[0]=A[l][0];
    tmp[1]=A[l][1];
    tmp[2]=A[l][2];
    tmp[3]=A[l][3];
    tmp[4]=A[l][4];
    i=l;
    j=r;
    while(i<j)
    {
        while(i<j&&A[j][p]<=tmp[p])
        j--;
        for(s=0;s<5;s++)
        {
            A[i][s]=A[j][s];
        }
        while(i<j&&A[i][p]>=tmp[p])
        i++;
        for(s=0;s<5;s++)
        {
            A[j][s]=A[i][s];
        }
    }
    for(s=0;s<5;s++)
    {
        A[i][s]=tmp[s];
    }
    sort(A,p,l,i-1);
    sort(A,p,i+1,r);
}
int search(int A[][5],int l,int r,int d)
{
    int m;
    if(l==r)
    return l;
    m=(l+r)/2;
    if(A[m][0]==d)
    return m;
    else if(A[m][0]>d)
    return search(A,m+1,r,d);
    else
    return search(A,l,m-1,d);
}
int main()
{
    int n;
    int m,q;
    int i,j,k,r,s;
    scanf("%d",&n);
    for(s=0;s<n;s++)
    {
        scanf("%d%d",&m,&q);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&A[i][0],&A[i][1],&A[i][2]);
            A[i][3]=0;
            A[i][4]=0;
        }
        sort(A,1,0,m-1);
        for(i=m-1;i>0;i--)
        {
            for(j=i-1;j>=0;j--)
            {
                if(A[j][2]>=A[i][2])
                break;
            }
            A[i][3]=A[j][0];
            A[j][4]+=A[i][4]+1;
        }
        sort(A,0,0,m-1);
        for(i=0;i<q;i++)
        {
            scanf("%d",&r);
            k=search(A,0,m-1,r);
            printf("%d %d\n",A[k][3],A[k][4]);
        }
    }
    return 0;
}