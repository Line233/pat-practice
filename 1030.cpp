// https://pintia.cn/problem-sets/994805342720868352/problems/994805464397627392
#include <iostream>
#include <stack>

using namespace std;
#define INT_MAX 2147483647

typedef struct node
{
    int destination;
    int disctance;
    int cost;
    node *next;
} node;
typedef struct city
{
    bool known = false;
    int pre = -1;
    int distance = INT_MAX;
    int cost = INT_MAX;
    node *next = NULL;
} city;
typedef city *graph;

graph initial_graph(int n)
{
    graph g = (graph)malloc(sizeof(city) * n);
    for (int i = 0; i < n; i++)
    {
        g[i].known = false;
        g[i].pre = -1;
        g[i].distance = INT_MAX;
        g[i].cost = INT_MAX;
        g[i].next = NULL;
    }
    return g;
}
void _graph_insert(graph g, int s, int d, int distance, int cost)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->destination = d;
    new_node->disctance = distance;
    new_node->cost = cost;
    new_node->next = g[s].next;
    g[s].next = new_node;
}
void graph_insert(graph g, int s, int d, int distance, int cost)
{
    _graph_insert(g, s, d, distance, cost);
    _graph_insert(g, d, s, distance, cost);
}

bool ischange(graph g, int d, int s, node *path)
{
    int dis_new = g[s].distance + path->disctance, cost_new = g[s].cost + path->cost;
    return g[d].distance > dis_new || (g[d].distance == dis_new && g[d].cost > cost_new);
}
void update_dis(graph g, int node_changed)
{
    node *des = g[node_changed].next;

    while (des != NULL)
    {
        int d = des->destination;
        if (g[d].known == false)
        {
            if (ischange(g, d, node_changed, des))
            {
                g[d].distance = g[node_changed].distance + des->disctance;
                g[d].cost = g[node_changed].cost + des->cost;
                g[d].pre = node_changed;
            }
        }
        des = des->next;
    }
}
int find_min(graph g, int n)
{

    int min_new = n;
    for (int i = 0; i < n; i++)
    {
        if (g[i].known == false)
        {
            if (min_new == n)
                min_new = i;
            if (g[i].distance < g[min_new].distance || (g[min_new].distance == g[i].distance && g[min_new].cost > g[i].cost))
            {
                min_new = i;
            }
        }
    }
    return min_new;
}
void djk(graph g, int s, int d, int n)
{
    g[s].known = true;
    g[s].distance = 0;
    g[s].cost = 0;
    int min = s;
    while (g[d].known == false)
    {
        update_dis(g, min);
        min = find_min(g, n);
        g[min].known = true;
    }
}

main()
{
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    graph g = initial_graph(n);
    for (int i = 0; i < m; i++)
    {
        int start, des, dis, cost;
        cin >> start >> des >> dis >> cost;
        graph_insert(g, start, des, dis, cost);
    }
    djk(g, s, d, n);
    stack<int> stack1;
    int work = d;
    while (work != s)
    {
        stack1.push(work);
        work = g[work].pre;
    }
    stack1.push(s);
    while (!stack1.empty())
    {
        cout << stack1.top() << " ";
        stack1.pop();
    }
    cout << g[d].distance << " " << g[d].cost;

    return 0;
}