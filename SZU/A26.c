// SZU A26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char words[51],test[51];
	int times;
	scanf("%s",words);
	scanf("%d",&times);
	while(times--){
		scanf("%s",test);

		if (strcmp(words,test)==0){
			printf("IDENTICAL\n");
			continue;
		}
		else if (strlen(words)!=strlen(test))	printf("NOT AN ANAGRAM\n");
		else{
				int alphabet[26]={0};
				int i,t;
				t=strlen(words);
				for (i=0;i<t;i++){
					alphabet[words[i]-'a']++;
					alphabet[test[i]-'a']--;
				}
				for (i=0;i<26;i++){
					if (alphabet[i]<0)
					{
						printf("NOT AN ANAGRAM\n");
						break;
					}
				}

				if (i==26)	printf("ANAGRAM\n");
			
		}

	}

	return 0;
}
