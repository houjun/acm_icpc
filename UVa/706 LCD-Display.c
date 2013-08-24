#include <stdio.h>
#include <string.h>
void printspace()
{
	printf(" ");
}
void printrow(char sq[11],int size,char s[10])
{
	int i,j,len;
	len=strlen(s);
	for ( i = 0; i < len ; i++){
		if (i) printspace();
		printspace();
		for ( j = 0; j < size ; j++){
			printf("%c",sq[s[i]-'0']);
		}
		printspace();
	}
}
void printcol(char sq[2][11],int size,char s[10])
{
	int i,j,k,len;
	len=strlen(s);
	for ( k = 0; k < size ; k++){
		for ( i = 0; i < len ; i++){
			if (i) printspace();
			printf("%c",sq[0][s[i]-'0']);
			for ( j = 0; j < size ; j++)
				printspace();		
			printf("%c",sq[1][s[i]-'0']);			
		}
		printf("\n");

	}
}
int main()
{
	int s;
	char num[10];
	char a[11]="- -- -----";
	char b[2][11];
	char c[11]="  ----- --";
	char d[2][11];
	char e[11]="- -- -- --";
	strcpy(b[0],"|   ||| ||");
	strcpy(b[1],"|||||  |||");
	strcpy(d[0],"| |   | | ");
	strcpy(d[1],"|| |||||||");

	while(scanf("%d %s",&s,num),s){
		printrow(a,s,num);
		printf("\n");
		printcol(b,s,num);
		printrow(c,s,num);
		printf("\n");
		printcol(d,s,num);
		printrow(e,s,num);
		
		printf("\n\n");
	}


	return 0;
}
