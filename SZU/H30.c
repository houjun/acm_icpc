//�������n��쳲�����������λ����
//����λÿ15000��ѭ������һ���ȡ�༴��
#include <stdio.h>
#define MAX 15000
int fib[MAX]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
int main()
{
	int i,j,t;
	for (i = 10; i < MAX ; i++){
		fib[i] = fib[i -1] + fib[i - 2];
		if (fib[i] >= 10000)
			fib[i] = fib[i] % 10000;
	}
	while(scanf("%d",&t),t>=0){
		t %= MAX;
		printf("%d\n",fib[t]);
	}
	return 0;
}