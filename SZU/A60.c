#include <stdio.h>
//����ͼ��С������,prim�㷨,�ڽ�����ʽ,���Ӷ�O(n^2)
//������С�������ĳ���,����ͼ�Ĵ�Сn���ڽ���mat,�����ڵ��Ȩinf
//�ɸ��ı�Ȩ������,pre[]�������Ĺ���,�ø�����ʾ,���ڵ�(��һ��)preֵΪ-1
//���뱣֤ͼ����ͨ��!

#define MAXN 1000
#define inf 100000000
typedef int elem_t;
int mat[MAXN][MAXN];
int pre[MAXN];
elem_t prim(int n){
	elem_t min[MAXN],ret=0;
	int v[MAXN],i,j,k;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[j=0]=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,ret+=min[k],i=0;i<n;i++)
			if (!v[i]&&mat[k][i]<min[i])
				min[i]=mat[pre[i]=k][i];
	}
	return ret;
}

int main()
{
	int i, j,  n, cost;
	int cases;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);		
		/* ��ȡ����Ϣ */
		for (i = 0; i < n ; i++){
			for (j = 0; j < n ; j++){
				scanf("%d",&cost);
				mat[i][j] = cost;			
			}
		}
		
		/* �����С������ */
		cost = prim(n);
		
		/* �����СȨֵ�� */
		printf("%d\n", cost);
		
	}
 
	return 0;	
}