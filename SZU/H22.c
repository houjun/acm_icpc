//��N�ƣ��ߵ�i�˰���i���������Ŀ��أ���N�˺����һյ�Ƶ����
//ת��Ϊ�ж�����N����������ż�������ӣ�ֻ����ȫƽ������ż����
//������ȫƽ�������һյΪOFF
#include <stdio.h>
#include <math.h>
int main()
{
	int n,t;
	while(1){
		scanf("%d",&n);
		if(n==0)
		        break;
		t = sqrt(n);
		t *= t;
		if(t==n)
             printf("ON\n");
        else
            printf("OFF\n");
 
	}
 
	return 0;
}