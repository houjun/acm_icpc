//���������������Ƿ���һ�ֽ�����ʹ������������ȡ�
//��ⲻΨһ��ѡ��������������С��һ��
//�ȷֱ����������ĺͣ��������������Ϊ�������޽�
//ż��ʱ��ö�����п��ܣ������������¼���Ž�
#include <stdio.h>
 
int main()
{
	int n,m,i,j,min,l,r1,r2;
	int tn,hn;
	int t[101],h[101];
	while(scanf("%d%d",&n,&m),n){
		tn = hn = 0;
		for (i = 0; i < n ; i++){
			scanf("%d",&t[i]);
			tn += t[i];
		}
		for (i = 0; i < m ; i++){
			scanf("%d",&h[i]);
			hn += h[i];
		}
		l = hn - tn;
		if( l< 0)	l = -l;
		if(l % 2 != 0){
			printf("-1\n");
			continue;
		}
		l /= 2;
		min = 2000;
		for (i = 0; i < n ; i++){
			for (j = 0; j < m ; j++){
				if((t[i] - h[j] == l && tn >= hn) || (t[i] - h[j] == -l && tn <= hn)){
					if(t[i] + h[j] <= min ){
						r1 = t[i];
						r2 = h[j];
						min = r1 + r2;
					}
				}
			}
		}
		if(min == 2000)
			printf("-1\n");
		else
			printf("%d %d\n",r1,r2);
 
	}
	return 0;
}