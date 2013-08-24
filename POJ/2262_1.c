#include<stdio.h>
#define MAX 1000000
int prime[MAX] = {0};
int main()
{
    int i, j, a;
    prime[2] = 1;
    for(i=3; i<MAX; i+=2)
        prime[i] = 1;

    for(i=2; i<MAX/2; i++)
    {
        if(prime[i])
            for(j=2; j<MAX/i; j++)
                prime[i + i * j] = 0;
    }

    while(scanf("%d", &a))
    {
        if(a == 0)
            break;
        for(i=3; i<MAX/2; i += 2)
        {
            if(prime[i] && prime[a-i])
                break;
        }
        printf("%d = %d + %d\n", a, i, a-i);
    }
    return 0;
}