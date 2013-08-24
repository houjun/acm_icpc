//按给定规则进行日期格式转换
//比较麻烦，按给定的要求一步一步写吧..
#include <stdio.h>
#include <string.h>
char TDay[][10]={	"Imix", "Ik", "Akbal", "Kan", "Chikchan", "Kimi",				//6
					"Manik", "Lamat", "Muluk", "Ok", "Chuen", "Eb",					//6
					"Ben", "Ix", "Men", "Kib", "Kaban", "Etznab", "Kawak", "Ajaw"};	//8
 
char HMonth[][10]={	"Pohp", "Wo", "Sip", "Zotz", "Sek", "Xul",						//6
					"Yaxkin", "Mol", "Chen", "Yax", "Sak", "Keh",					//6
					"Mak", "Kankin", "Muan", "Pax", "Kayab", "Kumku", "Wayeb"};		//7				
int cases,i,m1,d1,m2,d2,n;
char in1[10],in2[10];
int CRdate[4];
int LCdate[5];
int check()
{
	if (CRdate[0]==d1&&CRdate[1]==m1&&CRdate[2]==d2&&CRdate[3]==m2){
		return 1;
	}
	return 0;
}
void add(int l1,int l2,int l3,int l4)
{
	LCdate[4]+=l4;
	if (LCdate[4]>=20){
		LCdate[4]-=20;
		LCdate[3]++;
	}
	LCdate[3]+=l3;
	if (LCdate[3]>=18){
		LCdate[3]-=18;
		LCdate[2]++;
	}
	LCdate[2]+=l2;
	if (LCdate[2]>=20){
		LCdate[2]-=20;
		LCdate[1]++;
	}
	LCdate[1]+=l1;
	if (LCdate[1]>=20){
		LCdate[1]-=20;
		LCdate[0]++;
	}
 
}
int main()
{
 
	scanf("%d",&cases);
	while(cases--){
		scanf("%d %s %d %s",&d1,in1,&d2,in2);
		for ( i = 0; i < 20 ; i++){
			if (strcmp(TDay[i],in1)==0){
				m1=i+1;
			}
		}
		for ( i = 0; i < 19 ; i++){
			if (strcmp(HMonth[i],in2)==0){
				m2=i+1;
			}
		}
		//check invalid input
		if (d1<1||d1>13||d2<1||d2>20||m2==19&&d2>5){
			printf("0\n");
			continue;
		}		
 
		CRdate[0]=9;CRdate[1]=20;CRdate[2]=3;CRdate[3]=3;				//Calendar Round   	        d1.m1  d2.m2 
		LCdate[0]=8;LCdate[1]=0;LCdate[2]=0;LCdate[3]=0;LCdate[4]=0;	//  Long   Count 8.0.0.0.0 = 9.20   3.3
 
		for ( i = 1; i <= 18980 ; i++){
			if (check()){
				break;
			}
			add(0,0,0,1);
			CRdate[0]=(CRdate[0]+1)%13;
			if (CRdate[0]==0)	CRdate[0]=13;			
			CRdate[1]=(CRdate[1]+1)%20;
			if (CRdate[1]==0)	CRdate[1]=20;
 
			if (CRdate[2]==20){		
				CRdate[3]++;
				CRdate[2]=1;
			}			
			else if (CRdate[3]==19&&CRdate[2]==5){
				CRdate[3]=CRdate[2]=1;
			}
			else if (CRdate[3]==19){
				CRdate[2]=(CRdate[2]+1)%5;
				if (CRdate[2]==0)	CRdate[2]=5;
			}				
			else{
				CRdate[2]=(CRdate[2]+1)%20;
				if (CRdate[2]==0)	CRdate[2]=20;
			}				
		}//	LC is the date
		if (i==18981){
			printf("0\n");
			continue;
		}
		if (i<=3300)	n=16;
		else			n=15;
		printf("%d\n",n);
		for ( i = 0; i < n ; i++){
			printf("%d.%d.%d.%d.%d\n",LCdate[0],LCdate[1],LCdate[2],LCdate[3],LCdate[4]);
			add(2,12,13,0);
		}	
 
 
	}
	return 0;
}