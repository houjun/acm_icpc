#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define INF 2147483647
#define max(a,b) (a)>(b)?(a):(b)

int cmp ( const void *a , const void *b ) 
{ 
	return *(int *)a - *(int *)b; 
} 

int main()
{
	int boxcases,itemcases,i,j,minv=INF,minnum;
	int t[3];
	struct BOX{
		int l,w,h;//l>=w>=h
		int v;
	}box[MAX];

	struct ITEM{
		int l,w,h;		
	}item[MAX];
	
	scanf("%d",&boxcases);
	for ( i = 0; i < boxcases ; i++){
		scanf("%d%d%d",&t[0],&t[1],&t[2]);
		qsort(t,3,sizeof(t[0]),cmp);
		box[i].h=t[0];
		box[i].w=t[1];
		box[i].l=t[2];
		box[i].v=t[1]*t[0]*t[2];		
	}//input of box size

	scanf("%d",&itemcases);
	for ( i = 0; i < itemcases ; i++){
		scanf("%d%d%d",&t[0],&t[1],&t[2]);
		qsort(t,3,sizeof(t[0]),cmp);
		item[i].h=t[0];
		item[i].w=t[1];
		item[i].l=t[2];
	}//input of item size
	
	for ( j = 0; j < itemcases ; j++){
		minv=INF;
		for ( i = 0; i < boxcases ; i++){		
			if (item[j].h<=box[i].h&&item[j].w<=box[i].w&&item[j].l<=box[i].l){
				if (box[i].v<minv){
					minv=box[i].v;
					minnum=i;
				}
			}
		}		
		
		if (minv!=INF){
			printf("%d\n",box[minnum].v);
		}
		else
			printf("Item does not fit.\n");
	}

	
	return 0;
}