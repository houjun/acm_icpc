#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#define LISTSIZE 100
#define LISTINCRMENT 10
typedef struct{
 int *elem;
 int length;
 int listsize;
} SqList;

int InitList(SqList &L){
 L.elem=(int *)malloc(LISTSIZE*sizeof(int));
 if(!L.elem) exit(-2);
 L.length=0;
 L.listsize=LISTSIZE;
 return 1;
}
int ListInsert(SqList &L, int i, int e) {
		int *newbase;
		int *p,*q;
        if (i<1 || i>L.length+1) return -1;
        if (L.length >= L.listsize) {
            newbase = (int *)realloc(L.elem,(L.listsize+LISTINCRMENT) * sizeof(int)) ;
            if (!newbase) exit(-2);    L.elem = newbase;
            L.listsize += LISTINCRMENT; 
		}  
        q = &(L.elem[i-1]);  
        for (p=&(L.elem[L.length-1]); p>=q; --p) *(p+1) = *p;
        *q = e;    ++L.length;    return 1;  
} 
int ListDelete(SqList &L, int i, int e) {
  int *p,*q;
        if (i<1 || i>L.length) return -1;
        p = &(L.elem[i-1]);   
        e = *p;
        q = L.elem + L.length -1;   
        for (++p; p<=q; ++p) *(p-1) = *p; 
        --L.length;  
        return 1;
}
void LinkList_Show(SqList L){
	 int i;
	 for(i=0;i<L.length;i++)
		printf("%d ",*L.elem++);
	 printf("\n");
}

int ListCreate(SqList &L, int a[],int n){
	 int i;
	 L.elem=(int *)malloc(LISTSIZE*sizeof(int));
	 if(!L.elem) exit(-2);
	 L.length=0;
	 L.listsize=LISTSIZE;
	 for(i=1;i<n+1;i++)
	  ListInsert(L,i,a[i-1]);

	 return 1;
}
void ListMerge(SqList La,SqList Lb,SqList &Lc){
	int *pa=La.elem;
	int *pb=Lb.elem;
	Lc.listsize=Lc.length=La.length+Lb.length;
	int *pc=Lc.elem=(int *)malloc(Lc.listsize*sizeof(int));
	int *pa_last=La.elem+La.length-1;
	int *pb_last=Lb.elem+Lb.length-1;
	while (pa<=pa_last&&pb<=pb_last)
	{
		if(*pa<=*pb)	*pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<=pa_last)	*pc++=*pa++;
	while(pb<=pb_last)	*pc++=*pb++;
	 

}
int main(){
		 SqList L;
		 InitList(L);
		 ListInsert(L, 1, 2008);
		 ListInsert(L, 2, 262 );
		 ListInsert(L, 3, 20  );
		 ListInsert(L, 4, 1989);
		 ListInsert(L, 5, 3);
		 ListInsert(L, 6, 11);
		 printf("实验题:\n");
		 LinkList_Show(L);
		 ListInsert(L, 2, 130);
		 printf("插入5-7位后:");
		 LinkList_Show(L);
		 ListDelete(L,4,20);
		 printf("删除年龄后：");
		 LinkList_Show(L);

		 printf("\n");

		 /*选做题自此开始...囧*/
		 /*第一题*/
		 int a[10]={1,3,5,7,9,11,13,15,17,19};
		 int n=10;
		 SqList L2;
		 ListCreate(L2, a, n);
		 printf("选做题第一题\n");
		 LinkList_Show(L2);
		 printf("\n");
		 /*第二题*/
		 SqList La,Lb,Lc;
		 int i;
		 InitList(La);
		 InitList(Lb);
		 InitList(Lc);
		 for(i=1;i<=10;i++){
			ListInsert(La, i, i*2);
		 }
		 for(i=1;i<=10;i++){
			ListInsert(Lb, i, i);
		 }
		 /*开始合并*/
		printf("选做题第二题\n");
		printf("First   List :");
		LinkList_Show(La);
		printf("Second  List :");
		LinkList_Show(Lb);

		ListMerge(La,Lb,Lc);

		printf("After convert:");
		LinkList_Show(Lc);


		 return 0;
}