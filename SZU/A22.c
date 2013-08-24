#include <stdio.h>
int row,col,max,find1,find2;
char field[11][11];
int search(int i,int j){
	int k,l,t1,t2,flag,t,max1,max2;
	max1=max2=find1=find2=0;
	for (l = j; l < col ; l++){	//find the right most consistent 0
		if (field[i][l]=='1')
			break;
		else
			find1++;
	}
	t=find1;
	while(l>j){
		for (t1 = i+1; t1 < row ; t1++){
			flag=1;
			for (t2 = j; t2 < l ; t2++){
				if(field[t1][t2]=='1'){
					flag=0;
					break;
				}
			}
			if(flag)
				find1+=l-j;
			else
				break;
		}
		if(find1>max1)	max1=find1;
		l--;
		find1=--t;
	}

	for (k = i; k < row ; k++){	//find the down most consistent 0
		if (field[k][j]=='1')
			break;
		else
			find2++;
	}
	t=find2;
	while(k>i){
		for (t2 = j+1; t2 < col ; t2++){
			flag=1;
			for (t1 = i; t1 < k ; t1++){
				if(field[t1][t2]=='1'){
					flag=0;
					break;
				}
				
			}
			if(flag)
				find2+=k-i;
			else
				break;
		}
		if(find2>max2)	max2=find2;
		k--;
		find2=--t;
	}
	

	return 	max1>max2?max1:max2;
	
}
int main(){

	int cases,i,j,tmp;
	scanf("%d",&cases);
	while(cases--){
		max=0;
		scanf("%d %d",&row,&col);
		for (i = 0; i < row ; i++)
			scanf("%s",&field[i]);
		
		for (i = 0; i < row ; i++){
			for (j = 0; j < col ; j++){
				if(field[i][j]=='0'){
					tmp=search(i,j);
					if (tmp>max)
						max=tmp;
				}
			}
		}

		printf("%d\n",max);


	}

	return 0;
}
