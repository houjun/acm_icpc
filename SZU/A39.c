#include "stdafx.h"

#include <stdio.h>
int main()
{
	int cases,n,w,c,i,j,max,tot,maxtot,cut,t;
	int len[55];
	scanf("%d",&cases);
	while(cases--){
		max=maxtot=0;
		scanf("%d %d %d",&n,&w,&c);	
		for (i = 0; i < n ; i++){
			scanf("%d",&len[i]);
			max=max>len[i]?max:len[i];
		}

		for (i = 1; i <= max ; i++){
			tot=0;
			for (j = 0; j < n ; j++){
				cut=len[j]/i;
				if(len[j]%i==0) 
					cut--;	
				t=len[j]/i;
				tot+=t*i*w-cut*c;
			}
			maxtot=maxtot>tot?maxtot:tot;
		}
		
		
		printf("%d\n",maxtot);

	}
	return 0;
}
