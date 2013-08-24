//根据指示画图、输出
//trick 在于X1 X2、Y1 Y2 大小不定 Floodfill也可以用递归，但需判断
#include <stdio.h>
#define MAX 255
int row,col;
char map[MAX][MAX];
void mark(int i,int j,char c)
{
	if(j > 0 && j<= row && i > 0 && i <= col)
		map[j][i] = c;
}

int aj(int x,int y)
{
	if (y - 1 > 0){
		if(map[y - 1][x] == '1')
			return 1;
	}
	if (y + 1 <= col){
		if(map[y + 1][x] == '1')
			return 1;
	}
	if (x - 1 > 0){
		if(map[y][x - 1] == '1')
			return 1;
	}
	if (x + 1 <= row){
		if(map[y][x + 1] == '1')
			return 1;
	}
	return 0;
}
int main()
{
	char op,color,tmp[100],s;
	int x,y,x1,x2,y1,y2,i,j,flag,t;
	while(scanf("%c",&op),op!='X'){
		if (op == 'I'){
			scanf(" %d %d",&col,&row);
			getchar();
			for (i = 1; i <= row ; i++){
				for (j = 1; j <= col ; j++)
					map[i][j] = 'O';
				map[i][j] = '\0';
			}
		}
		else if(op == 'C'){
			getchar();
			for (i = 1; i <= row ; i++)
				for (j = 1; j <= col ; j++)
					map[i][j] = 'O';
		}
		else if (op =='L'){
			scanf(" %d %d %c",&x,&y,&color);
			getchar();
			mark(x,y,color);
		}
		else if (op =='V'){
			scanf(" %d %d %d %c",&x,&y1,&y2,&color);
			if(y1>y2){t=y1;y1=y2;y2=t;}	
			getchar();
			for (i = y1; i <= y2 ; i++)
				mark(x,i,color);			
		}
		else if (op =='H'){
			scanf(" %d %d %d %c",&x1,&x2,&y,&color);
			if(x1>x2){t=x1;x1=x2;x2=t;}	
			getchar();
			for (i = x1; i <= x2 ; i++)
				mark(i,y,color);
		}
		else if (op =='K'){
			scanf(" %d %d %d %d %c",&x1,&y1,&x2,&y2,&color);
			getchar();
			for (i = x1; i <= x2 ; i++)
				for (j = y1; j <= y2 ; j++)
					mark(i,j,color);
		}
		else if (op =='F'){
			scanf(" %d %d %c",&x,&y,&color);
			getchar();
			if(color == map[y][x])
				continue;
			s = map[y][x];
			map[y][x] = '1';
			do {
				flag = 0;
				for (i = 1; i <= row ; i++)
 					for (j = 1; j <= col ; j++)
						if(map[i][j] == s){
							if(aj(j,i)){
								flag++;
								map[i][j] = '1';
							}
						}

			} while(flag>0);
			for (i = 1; i <= row ; i++){
				for (j = 1; j <= col ; j++)
					if (map[i][j] == '1'){
						map[i][j] = color;
					}
			}
		}
		else if (op == 'S'){
			gets(tmp);
			printf("%s\n",tmp + 1);
			for (i = 1; i <= row ; i++)
					printf("%s\n",map[i] + 1);

		}

	return 0;
}