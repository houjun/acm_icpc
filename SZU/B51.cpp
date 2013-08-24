//同USACO
//给出一系列农民挤奶的起始和终止时间，求最长挤奶时间和最长间断时间
//用两个数组表示起始、终止时间，并算出开始和结束时间跨度，以此长度建立新数组
//在新数组中进行标记，再遍历查找
//标记时采取(]以防止出现1,2 2,3被标记成123。
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--){
		int *a,m,i,*b,min=1000000,max=0,*p,j,max1=0,min1=0;
		cin>>m;
		a=new int [m+1];
		b=new int [m+1];
		for(i=0;i<m;i++)
		{
			cin>>a[i]>>b[i];
			if(min>a[i])min=a[i];
			if(max<b[i])max=b[i];
		}
		p=new int[max+1];
		for(i=min+1;i<=max;i++)
		{
			p[i]=0;
		}
		for(i=0;i<m;i++)
			for(j=a[i]+1;j<=b[i];j++)
				p[j]=1;
			int max2=0,min2=0;
			for(i=min+1;i<=max;i++)
			{
				if(p[i]==1)
				{
					max1++;
					if(min2<=min1)
					{
						min2=min1;
 
					}min1=0;
				}
				if(p[i]==0)
				{
					min1++;
					if(max1>=max2)
					{
						max2=max1;
 
					}max1=0;
				}
 
			}if(max1>max2)max2=max1;
			if(min1>min2)min2=min1;
 
			cout<<max2<<" "<<min2<<endl;
 
	}
      return 0;
}