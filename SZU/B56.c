#include <stdio.h>
#include <string.h>
int a,b,c;
int flag[21][21],can[21];
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
void dfs(int x,int y,int z) {
    if (flag[x][y]==1) return;
    flag[x][y]=1;
    if (x==0) can[z]=1;
    if (x>0 && y<b) dfs(max(0,x+y-b),min(b,x+y),z);
    if (x>0 && z<c) dfs(max(0,x+z-c),y,min(c,x+z));
    if (y>0 && x<a) dfs(min(a,y+x),max(0,y+x-a),z);
    if (y>0 && z<c) dfs(x,max(0,y+z-c),min(c,y+z));
    if (z>0 && x<a) dfs(min(a,z+x),y,max(0,z+x-a));
    if (z>0 && y<b) dfs(x,min(b,z+y),max(0,z+y-b));
}
 
int main() {
	int i,cases;
	scanf("%d",&cases);
	while(cases--){
		memset(flag,0,sizeof(flag));
		memset(can,0,sizeof(can));
		scanf("%d %d %d",&a,&b,&c);
		dfs(0,0,c);
		for (i=0;i<c;i++) 
			if (can[i]==1) 
				printf("%d ",i);
			printf("%d\n",c);
 
	}
    return 0;
}