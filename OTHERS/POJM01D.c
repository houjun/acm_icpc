// POJM01D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void mult(char a[],char b[],char s[])
{
	int i,j,k=0,alen,blen,sum=0,res[65][65]={0},flag=0;
	char result[65];
	alen=strlen(a);blen=strlen(b); 
	
	for (i=0;i<alen;i++)
		for (j=0;j<blen;j++) res[i][j]=(a[i]-'0')*(b[j]-'0');
		
		for (i=alen-1;i>=0;i--)
		{
			for (j=blen-1;j>=0;j--) sum=sum+res[i+blen-j-1][j];
			result[k]=sum%10;
			k=k+1;
			sum=sum/10;
		}
		
		for (i=blen-2;i>=0;i--)
		{
			for (j=0;j<=i;j++) sum=sum+res[i-j][j];
			result[k]=sum%10;
			k=k+1;
			sum=sum/10;
		}
		if (sum!=0) {result[k]=sum;k=k+1;}
		
		for (i=0;i<k;i++) result[i]+='0';
		for (i=k-1;i>=0;i--) s[i]=result[k-1-i];
		s[k]='\0';
		
		while(1)
		{
			if (strlen(s)!=strlen(a)&&s[0]=='0') 
				strcpy(s,s+1);
			else
				break;
		}
}

void sub(char s1[],char s2[],char t[])
{
	int i,l2,l1,k;
	l2=strlen(s2);l1=strlen(s1);
	t[l1]='\0';l1--;
	for (i=l2-1;i>=0;i--,l1--)
        {
		if (s1[l1]-s2[i]>=0) 
			t[l1]=s1[l1]-s2[i]+'0';
		else
		{
			t[l1]=10+s1[l1]-s2[i]+'0';
			s1[l1-1]=s1[l1-1]-1;
		}
        }
	k=l1;
	while(s1[k]<0) {s1[k]+=10;s1[k-1]-=1;k--;}
	while(l1>=0) {t[l1]=s1[l1];l1--;}
loop:
	if (t[0]=='0') 
        {
		l1=strlen(s1);
		for (i=0;i<l1-1;i++) t[i]=t[i+1];
		t[l1-1]='\0';
		goto loop;
        }
	if (strlen(t)==0) {t[0]='0';t[1]='\0';}
} 

void add(char a[],char b[],char back[])
{
	int i,j,k,up,x,y,z,l;
	char *c;
	if (strlen(a)>strlen(b)) l=strlen(a)+2; else l=strlen(b)+2;
	c=(char *) malloc(l*sizeof(char));
	i=strlen(a)-1;
	j=strlen(b)-1;
	k=0;up=0;
	while(i>=0||j>=0)
        {
		if(i<0) x='0'; else x=a[i];
		if(j<0) y='0'; else y=b[j];
		z=x-'0'+y-'0';
		if(up) z+=1;
		if(z>9) {up=1;z%=10;} else up=0;
		c[k++]=z+'0';
		i--;j--;
        }
	if(up) c[k++]='1';
	i=0;
	c[k]='\0';
	for(k-=1;k>=0;k--)
		back[i++]=c[k];
	back[i]='\0';
} 

void main()
{
	int m,times,i,j,len1,len2,nn;
	char n[1010],t[5];
	int a[101],b[101];

	scanf("%d",&times);
	while(times--){
		scanf("%s %d",n,&m);
		itoa(m,t,10);
		len1=strlen(n);
		len2=strlen(t);
		if(len1<=2)
			nn=atoi(n);
		for (i = 0; i < m ; i++){
			scanf("%d",&a[i]);
		}
		for (i = 0; i < m ; i++){
			scanf("%d",&b[i]);
		}

		if (  len1<len2 || (len1==len2&&strcmp(n,t)<=0)  ){
			printf("%d\n",a[nn-1]);
		}
		else{

		}


	}

}
