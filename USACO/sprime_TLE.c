/*
ID: neil.li2
LANG: C
TASK: sprime
*/
#include <stdio.h>
#include <math.h>
#include <string.h>
int prime[7000000];

int isprime(int num){
	int i,flag=1;
	if (num==2)
		return 1;
	if(num==1)
		return 0;
	if (num%2==0){
		return 0;
	}
    for (i=3;i<=sqrt(num);i+=2)
		if (num%i==0) {flag=0;break;}
		return flag;
		
}
int getprime(int a[],int low,int high)
{
    int i,num,t=1;
    a[0]=2;a[1]=3;num=2;
	if (low==1)		i=5;
	else	i=low;

	for (; i <= high ; i+=2){
		if (isprime(i)){
			a[num++]=i;
		}
	}
	a[num]=-1;
	
	return num;
}
int main(){
	FILE *fin=fopen("sprime.in","r");
    FILE *fout=fopen("sprime.out","w");

	int len,low,high,i,j,num,temp,flag;
	fscanf(fin,"%d",&len);
	low=1;
	for (i = 1; i < len ; i++)
		low*=10;
	high=low*10;
	if(low!=1)	low++;
	//generate prime from low to high
	num=getprime(prime,low,high);


	if (low>10)		i=2;
	else			i=0;

	for (; i < num ; i++){
		temp=prime[i]/10;
		//current prime from low
		for (j = 1,flag=1; j < len ; j++){
			if (isprime(temp)==0){
				flag=0;
				break;
			}
			temp/=10;
		}
		if (flag){
			fprintf(fout,"%d\n",prime[i]);
		}
	}

	return 0;
}