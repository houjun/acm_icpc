//һ�Ѽ���������������С�������У����ұ��+�泯��
//���취��ÿ���ҵ������е����ı������������ڷ�������λ��
//������Щ��������λ�û򶥲������жϣ�������Ϻ��豣֤��Ϊ-ʹ���ٷ�Ϊ+
//��������˺þã������������и������3n-2���뵽���취
//���취ÿ����������λ�õ�����λ�����ֻ������
//������������Ϊ-�ڷ��ñ�������ָ��λ�ã�
//������һ�����ֻ������Ϊ-ʱ��һ�£������3n-2
#include <stdio.h>
int cake[31],sq[100],count;
void flip(int h)
{
	int i,j,tmp;
	i = 0;
	j = h;
	while(i<j){
		tmp = cake[i];
		cake[i] = -cake[j];
		cake[j] = -tmp;
		i++,j--;
	}
	if(i == j)
		cake[i] = -cake[i];
	sq[count++] = h + 1;	
}
int main()
{
	int cases,minus;
	int n,i,j,t;
	char tmp;
	scanf("%d",&cases);
	for(t = 1; t <= cases; t++){
		count = 0;
		scanf("%d",&n);
 
		for (i = 0; i < n ; i++){
			scanf(" %c%d",&tmp,&cake[i]);
			if(tmp == '-')
				cake[i] *= -1;
		}
 
		for (i = n; i > 0 ; i--){
			for (j = 0; j < n ; j++){
				if(cake[j] == i || cake[j] == -i )
					break;
			}
			if(j != 0 && cake[j] != j + 1 ){
				flip(j);
				if (i != 1){
					if(cake[0] > 0)
						flip(0);
					flip(i - 1);			
				}
			}
			else if(i != 1 && j == 0){
				if(cake[0] > 0)
					flip(0);
				flip(i - 1);
			}
		}
		if(cake[0] < 0)
			flip(0);
		printf("%d %d",t,count);
		for (i = 0; i < count ; i++){
			printf(" %d",sq[i]);
		}
		printf("\n");
	}
	return 0;
}