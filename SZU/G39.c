// 在wiki上找到公式，mod 2时和组合数有关系。原文如下： Using a Sierpiński triangle, it's easy to show that the parity of a Stirling number of the second kind is equal to the parity of a related binomial coefficient: Or directly, let two sets contain positions of 1's in binary representations of results of respective expressions: then mimic a bitwise AND operation by intersecting these two sets: to obtain the parity of a Stirling number of the second kind in O(1) time.
#include <stdio.h>
int main()
{
	int cases;
	int n, m, a, b, c, twos;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d %d",&n,&m);
		a = n-1-m/2; 
		b = (m-1)/2; 
		c = a - b;
		twos = 0;
		while(a){
			a/=2;
			twos+=a;
		}
		while(b){
			b/=2;
			twos-=b;
		}
		while(c){
			c/=2;
			twos-=c;
		}
		if (twos>0)
			printf("0\n");
		else
			printf("1\n");
 
	}
	return 0;
}