#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main () {
	char buf[256];
	int i, n, pn, len;
	int count, max;
 
	if(fgets(&(buf[0]), sizeof(buf), stdin) == NULL){
		return(0);
	}
 
	n = atoi(&(buf[0]));
 
	for(pn = 1; pn <= n; pn++){
		if(fgets(&(buf[0]), sizeof(buf), stdin) == NULL || strlen(&(buf[0])) > 150){
			printf("%d Line too long [%s]\n", pn, &(buf[0]));
			continue;
		}
		count = 0;
		max = 0;
		len = strlen(&(buf[0]));
		for (i = 0; i < len; i++) {
			if(buf[i] == '['){
				count++;
				if(count > max){
					max = count;
				}
			} else if(buf[i] == ']'){
				count--;
			} else {
				break;
			}
		}
 
		printf("%d %d\n", pn, 1 << max);
	}
	return(0);
}