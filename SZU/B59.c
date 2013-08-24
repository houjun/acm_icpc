#include <stdio.h>
#include <stdlib.h>
typedef struct EGG{
	int weigh;
	struct EGG *next;
}EGG,*Ptr;

EGG Head;
void insert(int n){
	Ptr p=&Head;
	if(!p->next){
		Ptr q=(EGG*)malloc(sizeof(EGG));
		q->weigh=n;
		p->next=q;
		q->next=NULL;
		return;
	}
	while(p->next){
		if(n<=p->next->weigh||!p->next){
			Ptr q=(EGG*)malloc(sizeof(EGG));
			q->weigh=n;
			q->next=p->next;
			p->next=q;
			return;
		}
		if (n>p->next->weigh&&!p->next->next){
			Ptr q=(EGG*)malloc(sizeof(EGG));
			q->weigh=n;
			q->next=p->next->next;
			p->next->next=q;
			return;
		}
	
		p=p->next;
	}

}
int main()
{
	int num,i,tmp,op,opn,cases;
	Head.next=NULL;
	Head.weigh=-1;

	scanf("%d",&num);
	for (i = 0; i < num ; i++){
		scanf("%d",&tmp);
		insert(tmp);
	}

	Ptr ptr=Head.next;
	while(ptr){
		printf(" %d",ptr->weigh);
		ptr=ptr->next;
	}
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&op);
		if(op){
			scanf("%d",&opn);
			insert(opn);
		}
		else{
			printf("%d\n",Head.next->weigh);
			Head.next=Head.next->next;
		}
			
	}

	return 0;
}
