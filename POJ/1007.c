//simple search
#include <stdio.h>

void quicksort(int l,int r,int b[])
{
    int i,j,x;
    if(l>=r) return;
    i=l;
    j=r;
    x=b[i];
    while(i!=j)
        {
        while(b[j]>x&&j>i) j--;
        if(i<j)
            {
            b[i]=b[j];
            i++;
            }
        while(b[i]<x&&j>i)i++;
            if(i<j)
                {
                b[j]=b[i];
                j--;
                }
        }
    b[i]=x;
    quicksort(l,j-1,b);
    quicksort(i+1,r,b);
}


int main(){

	char s[100][55];
	int sorted[100]={0};
	int index[100]={0};
	int len,cases,i,j,k;

	scanf("%d %d",&len,&cases);

	for (i = 0; i < cases ; i++)
		scanf("%s",s[i]);

	for (i = 0; i < cases ; i++){
		for (j = 0; j < len ; j++){
			for (k = j+1 ; k < len ; k++){
				if(s[i][j]>s[i][k]) //former > latter 
					index[i]++;
			}
		}
		sorted[i]=index[i];
	}

	quicksort(0,cases,sorted);
	//output
	for (i = 1; i <= cases ; i++){
		for (j = 0; j < cases ; j++){
			if (sorted[i]==index[j]){
				printf("%s\n",s[j]);
				index[j]=-1;
				break;
			}
		}
	}
		
	

	return 0;
}
