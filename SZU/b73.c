#include <stdio.h>

long long lcf(long long a,long long b){
    long long r=0;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return(a);
} 

long long lcd(long long u,long long v){
	long long t=u*v;
	if(u==0)
		return v;
	else
		return t/lcf(u,v);
}

int main(){
	int cases,i,len;
	long long d,n,cd,a[110],b[110];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&len);
		for (i = 0; i < len ; i++)
			scanf("%lld",&a[i]);
		for (i = 0; i < len ; i++)
			scanf("%lld",&b[i]);
		
		for (i = 0; i < len ; i++){
			cd=lcf(a[i],b[i]);
			a[i]=a[i]/cd;
			b[i]=b[i]/cd;//分式化简
		}
		n=d=0;
		for (i = 0; i < len ; i++)
			n=lcd(n,b[i]);		
		for (i = 0; i < len ; i++)
			d+=a[i]*n/b[i];
		
		cd=lcf(d,n);
		d=d/cd;
		n=n/cd;//分式化简

		if (n<0){
			n*=-1;
			d*=-1;
		}

		if(d==0)	n=1;
		printf("%lld %lld\n",d,n);


	}


	return 0;
}

