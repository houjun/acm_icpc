//给出一组数，第i个数字代表第i个“）”前有几个“（”
//输出一组数，表示与第i个“）”配对的“（”之间的“（”数目+1
//根据给出的数可以构造唯一的（）组合，在通过（）组合算出待求序列。
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