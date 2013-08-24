//博弈题，也可以通过DP解决

#include <stdio.h>
 
int main()
{
	int  y, m, d;
	int cases;
	scanf("%d",&cases);
	while(cases--){
		int res = 0;
        scanf("%d%d%d", &y, &m, &d);
        if( (m == 2 && d == 28)|| (m == 9 && d == 30) || (m == 11 && d == 31) || (m == 11 && d == 31) || ((m + d) % 2 == 0) )
			printf("YES\n");
        else printf("NO\n");
 
	}
	return 0;
}