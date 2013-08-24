#include <stdio.h>
#include <string.h>
void b2d(char s[16])
{
	int t=strlen(s);
	int i,tmp=1,result=0;
	for ( i = t - 1; i >= 0 ; i--){
		result+=(s[i]-'0')*tmp;
		tmp*=-2;
	}
	printf("%d\n",result);

}
void d2b(int n)
{
	int i=0,c[16];
	if(n==0)
		printf("0");
	while(n!=0){
		c[i]=n%(-2);
		n/=(-2);
		if(c[i]<0){
			c[i]=c[i]*(-1);
			n=n+1;
		}
		i++;
    }
	while(i--)
		printf("%d",c[i]);
	printf("\n");
}
int main()
{
	int cases,n;
	char s[16],ch[2];
	scanf("%d",&cases);
	while(cases--){
		scanf("%s",ch);
		if(ch[0]=='d'){
			scanf("%d",&n);
			printf("From decimal: %d is ",n);
			d2b(n);
		}
		else{
			scanf("%s",s);
			printf("From binary: %s is ",s);
			b2d(s);
		}
	}
	return 0;
}
