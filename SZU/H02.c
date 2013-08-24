//给出某些名字及对应的值，再给出一些加法等式/不等式，判断式子是否成立
//输入时判断字串比较麻烦，每次读入一个，再判断是否是+空格或者不等号
//基本会输入就可以做了
#include <stdio.h>
#include <string.h>
int main()
{
	int p,g,count = 1,t1,t2;
	int i,j,len,k,l,left,right,equal,flag;
	char name[51][22],tmp[500],t[50],c;
	double vp;
	int v[51];
	scanf("%d%d",&p,&g);
	for (i = 0; i < p ; i++){
		scanf("%s%d.%d",name[i],&t1,&t2);
		v[i] = t1 * 10 + t2;
	}
	getchar();
	for (i = 0; i < g ; i++){
		flag = 0;
		left = k = 0;
		gets(tmp);
		len = strlen(tmp);
		for (j = 0; j < len ; j++){
			c = tmp[j];
			if(c == '<'){
				if(tmp[++j] == '=')	{				
					equal = 1;
					j++;
				}
				else
					equal = 0;
				j ++;
				if(tmp[j+1] != 0)
					right = (tmp[j] - '0') * 10 + (tmp[j +1 ] - '0');
				else
					right = tmp[j] - '0';
				right *= 10;
				if (left < right)
					flag = 1;
				if(equal)
					if(left == right)
						flag = 1;
				break;
			}
			else if(c == '>'){
				if(tmp[++j] == '=')	{				
					equal = 1;
					j++;
				}
				else
					equal = 0;
				j ++;
				if(tmp[j+1] != 0)
					right = (tmp[j] - '0') * 10 + (tmp[j +1 ] - '0');
				else
					right = tmp[j] - '0';
				right *= 10;
				if (left > right)
					flag = 1;
				if(equal)
					if(left == right)
						flag = 1;
				break;
			}
			else if(c == '='){
				j += 2;
				if(tmp[j+1] != 0)
					right = (tmp[j] - '0') * 10 + (tmp[j +1 ] - '0');
				else
					right = tmp[j] - '0';
				right *= 10;
				if(left == right)
					flag = 1;
				break;
			}
			else if(c == '+')
				continue;
			else if(c != ' '){
				while (c = tmp[j] ,c != ' '){
					t[k++] = c;
					j++;
				}
				t[k] = 0;
				k = 0;
				for (l = 0; l < p ; l++){
					if(strcmp(name[l],t) == 0){
						left += v[l];
						break;
					}
				}
			}
 
		}
		if (flag)
			printf("Guess #%d was correct.\n",count);
		else
			printf("Guess #%d was incorrect.\n",count);
		count++;
	}
	return 0;
}