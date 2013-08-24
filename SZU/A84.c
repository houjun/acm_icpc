// SZU A84.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int length,i,Meven,Modd,Jeven,Jodd,lose,win,t;
	length=1;
	while(length){
		scanf("%d",&length);
		if(length==0) break;
		Meven=Modd=Jeven=Jodd=0;
		for (i=0;i<length;i++)
		{
			scanf("%d",&t);
			if (t%2==0)		Meven++;
			else			Modd++;
			}
		for (i=0;i<length;i++)
		{
			scanf("%d",&t);
			if (t%2==0)		Jeven++;
			else			Jodd++;
		}
		
		lose=(Meven>Jodd?Jodd:Meven);
		lose+=(Modd>Jeven?Jeven:Modd);
		win=length-lose;
		printf("%d\n",win);
	
	}

	return 0;
}
