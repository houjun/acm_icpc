
#include <stdio.h>
#include <stdlib.h>
char p[1000000];

int main()
{
	int n,i,j;
	p[2] = 1;
    for(i=3; i<1000000; i+=2)
        p[i] = '1';
	
    for(i=2; i<1000000/2; i++) {
        if(p[i]=='1')
            for(j=2; j<1000000/i; j++)
                p[i + i * j] = '0';
    }

	while(scanf("%d",&n),n!=0){
		for (i = 0; i < 500000 ; i++){
			if(p[i]=='1'&&p[n-i]=='1'){
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
			
		}

	}
	return 0;
}
