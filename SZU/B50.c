// clocks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
int clock[9],tmpclock[9],flag,seq[9];
void moveclk(char t,int tt){
	int i=t-'A';
	tmpclock[i]=(tmpclock[i]+tt)%4;
	
}
void move(int n,int t){
	if		(n==1){
		moveclk('A',t);moveclk('B',t);moveclk('D',t);moveclk('E',t);
	}
	else if (n==2){
		moveclk('A',t);moveclk('B',t);moveclk('C',t);
	}
	else if (n==3){
		moveclk('B',t);moveclk('C',t);moveclk('E',t);moveclk('F',t);
	}
	else if (n==4){
		moveclk('A',t);moveclk('D',t);moveclk('G',t);
	}
	else if (n==5){
		moveclk('B',t);moveclk('D',t);moveclk('E',t);moveclk('F',t);moveclk('H',t);
	}
	else if (n==6){
		moveclk('C',t);moveclk('F',t);moveclk('I',t);
	}
	else if (n==7){
		moveclk('D',t);moveclk('E',t);moveclk('G',t);moveclk('H',t);
	}
	else if (n==8){
		moveclk('G',t);moveclk('H',t);moveclk('I',t);
	}
	else if (n==9){
		moveclk('E',t);moveclk('F',t);moveclk('H',t);moveclk('I',t);
	}
}
int checkclk(){
	int i;
	for (i = 0; i < 9 ; i++){
		if (tmpclock[i]!=0){
			return 0;
		}
	}
	return	1;
}

void turn(int n){
	int i,t,j;
	if(n==10&&checkclk()==1){
		//�����ѵó��ķ���
		for (i = 0; i < 9 ; i++){
			if (seq[i]){
				for(j=0;j<seq[i];j++){
						printf("%d",i+1);					
				}
			}
		}			
		printf("\n");		
		return;
	}
	else if(n==10){
		return;
	}
	else{
		for (i = 3; i >= 0 ; i--){
			move(n,1);
			seq[n-1]=(4-i)%4;
			turn(n+1);
		}
		for (t = 0; t < i ; t++){
			move(n-1,-1);			
		}
	}
}

int main()
{
	int i,times;
	scanf("%d",&times);
	while(times--){
		for (i = 0; i < 9 ; i++){
			seq[i]=0;
		}
		for (i = 0; i < 9 ; i++){
			scanf("%d",&tmpclock[i]);
		}
		turn(1);

	}
	return 0;
}
