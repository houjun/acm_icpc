#include <stdio.h>
#include <stdlib.h>

#define HASHKEY 10007

typedef struct HASHTBL{
	int number;
	struct HASHTBL *next;
}HASHTBL,*Ptr;

HASHTBL table[HASHKEY];

void insert(int n,HASHTBL *Head){

	Ptr s=(HASHTBL*)malloc(sizeof(HASHTBL));

	s->number=n;

	s->next = Head->next;
	Head->next=s;	
}


int main()
{
	int i,n,cases,opnum,tmp;
	char op[10];
	Ptr p,q;
 
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		//init
		for (i = 0; i < HASHKEY ; i++){
			table[i].next=NULL;
		}
		while(n--){

			scanf("%s %d",op,&opnum);
			//negative number
			tmp=opnum;
			if(tmp<0)	tmp=-tmp;
			tmp=tmp%HASHKEY;

			//add
			if(op[1]=='d')
				insert(opnum,&table[tmp]);
			
			//ask
			else{
				p=table[tmp].next;
				while(p){
					if(p->number==opnum){
						printf("YES\n");
						break;
					}
					p=p->next;
				}

				if(p==NULL)
					printf("NO\n");
			}			

		}

		//free
		for (i = 0; i < HASHKEY ; i++){
			p=table[i].next;
			while(p){
				q=p->next;
				free(p);
				p=q;
			}
		}

 
	}
 
	return 0;
}
