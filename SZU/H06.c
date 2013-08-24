//给定N个地点以及相连的道路长度，求给出所有道路长度与最小生成树长度之差
//MST模版 因节点较多，只能采用正向表+克鲁斯卡尔算法
#include <stdio.h>
#include <stdlib.h>
#define SET_SIZE 200010
 
typedef struct _edge
{
    int length;
    int beg;
    int end;
}ST_EDGE;
ST_EDGE edges[SET_SIZE];
 
int m, n, parent[SET_SIZE];
 
int comp(const void *a, const void *b)
{
    ST_EDGE *pa = (ST_EDGE *)a;
    ST_EDGE *pb = (ST_EDGE *)b;
    return pa->length - pb->length;
}
 
void make_set()
{
    int i;
 
    /* make it point to itself */
    for (i=0 ; i<m ; i++)
        parent[i] = i;
}
/*注意这个函数，在查找集合的时候实现路径压缩*/
int find_set(int x)
{
    if (x != parent[x])
        parent[x] = find_set(parent[x]);
    return parent[x];
}
 
void union_set(int x, int y)
{
    parent[find_set(y)] = find_set(x);
}
 
int kruskal()
{
    int i, cnt_edge, ret1, ret2, sum;
 
    qsort(edges, n, sizeof(ST_EDGE), comp);
    make_set();
 
    cnt_edge = sum = 0;
    for (i=0 ; i<n ; i++)
    {
        ret1 = find_set(edges[i].beg);
        ret2 = find_set(edges[i].end);
        /* the same set */
        if (ret1 == ret2)
            continue;
        union_set(edges[i].beg, edges[i].end);
        sum += edges[i].length;
        cnt_edge++;
        if (m - 1 == cnt_edge)
            break;
    }
 
    return sum;
}
 
int main()
{
    int i, sum, mst_len;
 
    while (1)
    {
        scanf("%d %d", &m, &n);
        if (0 == m && 0 == n)
            break;
 
        sum = 0;
        for (i=0 ; i<n ; i++)
        {
            scanf("%d %d %d", &edges[i].beg, &edges[i].end, &edges[i].length);
            sum += edges[i].length;
        }
 
        mst_len = kruskal();
        printf("%d\n", sum - mst_len);
    }
	return 0;
}