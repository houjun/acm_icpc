#include "stdafx.h"

#include <string.h>
#include <stdio.h>
int main()
{
	char name[25][25],ch,start[25];
	int t,i,j,n,tot,result;
	scanf("%d",&t);
	while(t--){
		getchar();
		i=j=0;
		while(1){
			ch=getchar();
			if(ch=='\n'){
				name[i][j]='\0';
				break;
			}
			else if(ch==' '){
				name[i][j]='\0';
				i++;
				j=0;
			}
			else{
				name[i][j]=ch;
				j++;
			}
			
		}
		scanf("%s%d",start,&n);
		tot=i+1;
		for (i = 0; i < tot ; i++){
			if (strcmp(name[i],start)==0)
				break;
		}
		result=n%tot+i;
		result%=tot;
		if (result==0){
			result=tot;
		}
		printf("%s\n",name[result-1]);
		


	}

	return 0;
}


/*


Sample Input

3
Alex Karyn Maude
Karyn
5
Alex Karyn Maude
Alex
6
Alex Karyn Zach Becca Maude
Zach
8
Sample Output

Maude
Maude
Maude


*/