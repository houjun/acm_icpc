//����һ���ֵ䣬�����������֣��ٸ�����_����ĸ��ɵ���
//�»��߿�������ƥ�䣬��ĸ�����Ӧ���������ظ������Ƿ���Թ����ֵ��е���
//ͳ��_���ִ�����Ϊ�ֵ�����ֽ���һ�������ʾ26����ĸ���ִ�����
//���ø������ֺ�_����ĸƵ��������գ�����������ָ�����_����һ
//����ĸƵ�����»�������һΪ�������޷������ֵ������
#include <stdio.h>
#include <string.h>
int main()
{
	int cases;
	int i,j,k,len,blank,count,tmp,t ;
	char dic[1001][10];
	char word[10];
	int wordmap[26],cpywordmap[26];
	while(scanf("%d",&cases),cases){
		memset(wordmap,0,sizeof(wordmap));
		count = blank = 0;
		for (i = 0; i < cases ; i++)
			scanf("%s",dic[i]);
		scanf("%s",word);
		len = strlen(word);
		for (j = 0; j < len ; j++){
			if(word[j] == '_')
				blank ++;
			else
				wordmap[word[j]-'A'] ++;
		}
		t = blank;
		for (i = 0; i < cases ; i++){
			for (k = 0; k < 26 ; k++)
				cpywordmap[k] = wordmap[k];
			blank = t;
			for (j = 0; j < strlen(dic[i]) ; j++){
				tmp = dic[i][j] - 'A';
				if(blank < 0)
					break;
				if(cpywordmap[tmp] == 0)
					blank--;
				else
					cpywordmap[tmp]--;
			}
			if(blank >= 0)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}