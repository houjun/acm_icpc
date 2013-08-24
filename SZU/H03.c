//给定一个字典，里面有若干字，再给出由_和字母组成的字
//下划线可以任意匹配，字母必须对应（可能有重复）问是否可以构成字典中的字
//统计_出现次数，为字典里的字建立一个数组表示26个字母出现次数，
//在用给定的字和_的字母频数与其对照（相减）若出现负数，_数减一
//若字母频数或下划线数任一为负，则无法构成字典里的字
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