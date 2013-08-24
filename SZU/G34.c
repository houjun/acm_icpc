#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
	int i,j,ttt,k;
	int cases,len,tt;
 
	char word[500];
	char tmp[10];
	int second[50][2];//[][0]first num,[][1]second4
	char third[50];
	char morse[10][10];
	char cell[10][5];
	char keyboard[30]="KXVMCNOPHQRSZYIJADLEGWBUFT";
	char fourth[50];
	char pre[50],end[50];
	char fifth[50];
 
	strcpy(morse[0],"-----");
	strcpy(morse[1],"*----");
	strcpy(morse[2],"**---");
	strcpy(morse[3],"***--");
	strcpy(morse[4],"****-");
	strcpy(morse[5],"*****");
	strcpy(morse[6],"-****");
	strcpy(morse[7],"--***");
	strcpy(morse[8],"---**");
	strcpy(morse[9],"----*");
	strcpy(cell[2],"ABC");
	strcpy(cell[3],"DEF");
	strcpy(cell[4],"GHI");
	strcpy(cell[5],"JKL");
	strcpy(cell[6],"MNO");
	strcpy(cell[7],"PQRS");
	strcpy(cell[8],"TUV");
	strcpy(cell[9],"WXYZ");
 
 
	scanf("%d",&cases);
	while(cases--){
		scanf("%s",word);
		len=strlen(word);
		ttt=0;
		for(i=1;i<len-6;i+=6){
			strncpy(tmp,word+i,5);
			tmp[5]='\0';
			for(j=0;j<10;j++){
				if(strcmp(tmp,morse[j])==0){
					second[ttt][0]=j;					
					break;
				}
			}
			i+=6;
			strncpy(tmp,word+i,5);
			for(j=0;j<10;j++){
				if(strcmp(tmp,morse[j])==0){
					second[ttt][1]=j;
					ttt++;
					break;
 
				}
			}
		}//for i
		//ttt= total number;
 
		for(i=0;i<ttt;i++)
			third[i]=cell[second[i][0]][second[i][1]-1];
 		third[i]='\0';
 
		for(i=0;i<ttt;i++)
			fourth[i]=keyboard[third[i]-'A'];
		fourth[i]='\0';
		tt=(ttt+1)/2;
		for(i=0;i<tt;i++)
			pre[i]=fourth[i];
		pre[i]='\0';
		for(j=0;i<ttt;j++,i++)
			end[j]=fourth[i];
		end[j]='\0';
 
		for(i=0,j=0,k=0;i<ttt;i++){
 
			if(j<tt){
				fifth[i]=pre[j];
				j++;
			}
			i++;
			if(k<ttt-tt){
				fifth[i]=end[k];
				k++;
			}
 
		}
		if(ttt%2==1)
			i-=1;
		fifth[i]='\0';//4
 
		len=strlen(fifth);
		for(i=len-1;i>=0;i--)
			printf("%c",fifth[i]);
		printf("\n");
 
 
 
	}
 
	return 0;
}