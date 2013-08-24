#include<stdio.h>
#include<string.h>
 
 
int main()
{
int t,n,i,f,g,h;
 
char a[12000000]={0};
scanf("%d",&t);
while(t--)
{
	g=0;
	f=0;
 
scanf("%d",&n);
 
  for(i=0;i<n;i++)
  { 
	  scanf("%s",a);     
	  g=strlen(a);
	  if(a[0]!='-'&&a[0]!='0')	 
		  f++;
	  else
		  if(a[0]=='0')
	  for(h=1;h<g;h++)
		  if(a[h]!='0')
		  {
			  f++;break;
  }
  }
  printf("%d\n",f);
}
 
return 0;
}