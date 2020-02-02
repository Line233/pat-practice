#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
#define MAXN 550
int dis[MAXN];			  //start到i的距离
int spend[MAXN];		  //start到i的费用
int e[MAXN][MAXN];		  //i到j的距离
int cost[MAXN][MAXN];	 //i到j的费用
bool vis[MAXN] = {false}; //i点是否已经成为跳板
int pre[MAXN];
void dfs(int v)
{
	if (v == pre[v])
	{
		printf("%d ", v);
		return;
	}
	dfs(pre[v]);
	printf("%d ", v);
}
int *test1()
{
}
int main()
{
	while(true)
	{
		fill(dis, dis + MAXN, INT_MAX);
		fill(spend, spend + MAXN, INT_MAX);
		fill(e[0], e[0] + MAXN * MAXN, INT_MAX);
		fill(cost[0], cost[0] + MAXN * MAXN, INT_MAX);
		int n, m, start, end;
		scanf("%d%d%d%d", &n, &m, &start, &end);
		while (m--)
		{
			int City1, City2, Distance, Cost;
			scanf("%d%d%d%d", &City1, &City2, &Distance, &Cost);
			e[City1][City2] = e[City2][City1] = Distance;
			cost[City1][City2] = cost[City2][City1] = Cost;
		}
		dis[start] = 0;
		spend[start] = 0;
		pre[start] = start;
		for (int i = 0; i < n; i++)
		{
			int k = -1, min = INT_MAX;
			for (int j = 0; j < n; j++)
			{
				if (vis[j] == false && dis[j] < min)
				{
					min = dis[j];
					k = j;
				}
			}
			if (k == -1)
				break;
			vis[k] = true;
			for (int j = 0; j < n; j++)
			{
				if (vis[j] == false && e[k][j] < INT_MAX)
				{
					if (e[k][j] + dis[k] < dis[j])
					{ //如果新路径比原来的路径距离短，更新
						pre[j] = k;
						spend[j] = spend[k] + cost[k][j];
						dis[j] = e[k][j] + dis[k];
					}
					else if (e[k][j] + dis[k] == dis[j] && spend[k] + cost[k][j] < spend[j])
					{ //如果距离一样 花费更少
						pre[j] = k;
						spend[j] = spend[k] + cost[k][j];
					}
				}
			}
		}
		dfs(end);
		printf("%d %d", dis[end], spend[end]);
		cin.sync();
		cin.get();
	}
	return 0;
}