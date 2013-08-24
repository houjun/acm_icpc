// B51.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMILKING 5010

typedef struct Milking	Milking;
struct Milking {
    int begin;
    int end;
};

Milking milking[MAXMILKING];
int nmilking;

int
milkcmp(const void *va, const void *vb)
{
    Milking *a, *b;
	
    a = (Milking*)va;
    b = (Milking*)vb;
	
    if(a->begin > b->begin)
		return 1;
    if(a->begin < b->begin)
		return -1;
    return 0;
}

int main()
{
	int times;
	scanf("%d",&times);
	while(times--){
		int i, t, tmilk, tnomilk;
		Milking cur;
		
		scanf("%d", &nmilking);
		for(i=0; i<nmilking; i++)
			scanf("%d %d", &milking[i].begin, &milking[i].end);
		qsort(milking, nmilking, sizeof(Milking), milkcmp);
		
		tmilk = 0;
		tnomilk = 0;
		cur = milking[0];
		for(i=1; i<nmilking; i++) {
			if(milking[i].begin > cur.end) {	/* a down time */
				t = milking[i].begin - cur.end;
				if(t > tnomilk)
					tnomilk = t;
				
				t = cur.end - cur.begin;
				if(t > tmilk)
					tmilk = t;
				
				cur = milking[i];
			} else {	
				if(milking[i].end > cur.end)
					cur.end = milking[i].end;
			}
		}
		
		t = cur.end - cur.begin;
		if(t > tmilk)
			tmilk = t;
		
		printf("%d %d\n", tmilk, tnomilk);
		}

    
	return 0;
}