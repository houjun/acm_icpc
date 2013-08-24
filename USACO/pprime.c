/*
ID: neil.li2
LANG: C
TASK: pprime
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isprime(int num){
	int i,flag=1;
	if (num%2==0){
		return 0;
	}
    for (i=3;i<=sqrt(num);i+=2)
		if (num%i==0) {flag=0;break;}
		return flag;
		
}

int main(){
	
	int d1,d2,d3,d4,palindrome;	
	FILE *fin=fopen("pprime.in","r");
	FILE *fout=fopen("pprime.out","w");  
	int a,b,i,num=3;
	int pal[5000]={5,7,11};

	fscanf(fin,"%d %d",&a,&b);

	//3 digits
	if(a<1000&&b>100){
		for (d1 = 1; d1 <= 9; d1+=2) {
			if(d1==5)	continue;
			for (d2 = 0; d2 <= 9; d2++) {
					palindrome = 100*d1 + 10*d2 + d1;
					if (isprime(palindrome))
						pal[num++]=palindrome;
			}
		}
	}
	//5 digits
	if(a<100000&&b>10000){
		for (d1 = 1; d1 <= 9; d1+=2) {
			if(d1==5)	continue;
			for (d2 = 0; d2 <= 9; d2++) {
				for (d3 = 0; d3 <= 9; d3++) {
					palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
					if (isprime(palindrome))
						pal[num++]=palindrome;
				}
			}
		}
	}
	//7 digits
	if(b>1000000){
		for (d1 = 1; d1 <= 9; d1+=2) {
			if(d1==5)	continue;
			for (d2 = 0; d2 <= 9; d2++) {
				for (d3 = 0; d3 <= 9; d3++) {
					for (d4 = 0; d4 <= 9; d4++) {
						palindrome = 1000000*d1 + 100000*d2 +10000*d3 + 1000*d4 + 100*d3 + 10*d2 + d1;
						if (isprime(palindrome))
							pal[num++]=palindrome;
					}
				}
			}
		}

	}
	for (i = 0; i < num ; i++){
		if(pal[i]>=a&&pal[i]<=b)
			fprintf(fout,"%d\n",pal[i]);
		if (pal[num]>b)
			break;
	}

	
	
	return 0;
}