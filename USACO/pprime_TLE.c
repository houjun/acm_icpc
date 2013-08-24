
/*
ID: neil.li2
LANG: C
TASK: pprime
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int pnum[1000000];
char b[10000000];
int pwr[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int start=0,knum;

int isprime(int num){
	if (num%2==0){
		return 0;
	}
	int i,flag=1;
    for (i=3;i<=sqrt(num);i+=2)
		if (num%i==0) {flag=0;break;}
		return flag;
		
}
int prime2(int a[],int min,int n)
{
    int i,num,t=1;
	memset(b,'1',sizeof(b));
	start=0;
    a[0]=2;a[1]=3;num=2;
	if (min%2==0)
		min++;
	
	for (i = min; i <= n ; i+=2){
		if (isprime(i)){
			a[num++]=i;
		}
	}
	
	return num;
}

int prime1(int a[],int min,int n)
{
    int i,j,k,x,num,t=1;
    n++;
    n/=2;
    a[0]=2;a[1]=3;num=2;
	memset(b,'0',sizeof(b));
    for(i=3;i<=n;i+=3)
        for(j=0;j<2;j++)
		{
            x=2*(i+j)-1;
            while(b[x]=='0')
			{
                a[num++]=x;
				if(x>=min&&t) {
					start=num-1;
					t=0;
				}
                for(k=x;k<=2*n;k+=x)
                    b[k]='1';
			}
		}
		return num;
}

int getdigit(int num,int n){
	if(n==1)
		return num%10;
	else
		return (num%pwr[n]-num%pwr[n-1])/pwr[n-1];
}
int ispal(int num){
	int s1[10];
	int i=0,j,len=0;
	  while(num){
		  s1[i++]=num-num/10*10;	
		  len++;
		  num/=10;
	  }
	  j=len-1;
	  
	  if (s1[j]%2==0)
		  return 0;
	  for (i = 0; i <= len/2 ; i++,j--)
	  	if (s1[i]!=s1[j])
			return 0;
	  	
	  return 1;
		  
}
int getlen(int num){
	int len=0;
	  while(num){
		  len++;
		  num/=10;
	  }
	return len;
}


int main()
{

	FILE *fin=fopen("pprime.in","r");
	FILE *fout=fopen("pprime.out","w");   
	int a,b,i,num;

	clock_t begin, end;
	double  cost;
	begin = clock();

	fscanf(fin,"%d %d",&a,&b);

	if((b-a)>500000)
		num=prime1(pnum,a,b);
	else{
		num=prime2(pnum,a,b);
		start=0;
	}

	for (i = start; i < num ; i++){
		if(pnum[i]>1000&&getlen(pnum[i])%2==0)
			i++;
		if(pnum[i]>=a)
			if(ispal(pnum[i]))
				fprintf(fout,"%d\n",pnum[i]);		
	}

	end = clock();
	cost = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%lf seconds\n", cost);


	return 0;
}


