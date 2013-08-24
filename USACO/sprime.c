/*
ID: neil.li2
LANG: C
TASK: sprime
*/
#include <stdio.h>
#include <math.h>
FILE *fout;
int isprime(int num){
	int i,flag=1;
	if (num%2==0){
		return 0;
	}
    for (i=3;i<=sqrt(num);i+=2)
		if (num%i==0) {flag=0;break;}
		return flag;
		
}


void sprime(int n, int ndigit)
{
	if(ndigit == 0) {
		fprintf(fout, "%d\n", n);
		return;
	}
	
	n *= 10;
	if(isprime(n+1))
		sprime(n+1, ndigit-1);
	if(isprime(n+3))
		sprime(n+3, ndigit-1);
	if(isprime(n+7))
		sprime(n+7, ndigit-1);
	if(isprime(n+9))
		sprime(n+9, ndigit-1);
}

int main()
{
	int n;
	FILE *fin=fopen("sprime.in","r");
	fout=fopen("sprime.out","w");


	fscanf(fin, "%d", &n);
	
	sprime(2, n-1);
	sprime(3, n-1);
	sprime(5, n-1);
	sprime(7, n-1);
	return 0;
}