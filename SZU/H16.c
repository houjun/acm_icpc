//����һ��������i�����ִ����i��������ǰ�м���������
//���һ��������ʾ���i����������Եġ�����֮��ġ�������Ŀ+1
//���ݸ����������Թ���Ψһ�ģ�����ϣ���ͨ�������������������С�
#include <stdio.h>
 
int main()
{
	int cases;
	int n,num[21];
	int i,j,k,l,t,count;
	char p[50];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		for (i = 0; i < n ; i++)
			scanf("%d",&num[i]);
		k = l = 0;
		for (i = 0; i < n ; i++){
			for (j = 0; j < num[i] - l ; j++){
				p[k++] = '(';	
			}
			p[k++] = ')';
			l = num [i];
		}
		p[k++] = '\0';
		t = 0;
		for (i = 1; i < n * 2 ; i++){
			if(p[i] == ')'){
				count = 1;
				for (j = i - 1; j >= 0 ; j--){
					if(p[j] == 0)
						count++;
					if(p[j] == '('){
						p[j] = 0;
						if(t == 0)
							printf("%d",count);
						else
							printf(" %d",count);
						t++;
						break;
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}