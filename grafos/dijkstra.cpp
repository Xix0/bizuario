/**********************************************************************************
* DIJKSTRA'S ALGORITHM (SHORTEST PATH TO A VERTEX)                                *
* Description: Given any graph (not necessarily a tree), the algorithm generates  *
* an array denoting the shortest distance from each vertex to the start point. It *
* starts considering all distances equal to infinity and then uses the given      *
* edges in a BFS to generate the array.                                           *
* Time complexity: O((V+E)logE)                                                   *
* Usage: dist[node]                                                               *
* Notation: m:           number of edges                                          *
*           (a, b, w):   edge between a and b with weight w                       *
*           s:           starting node                                            *
*           par[v]:      parent node of u, used to rebuild the shortest path      *
**********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10; // Maximum number of nodes
int dist[N];
vector <pair<int, int>> adj[N];
priority_queue <pair<int, int>> pq;
int a, b, w, m;
//int par[N];
#define cl(x, v) memset((x), (v), sizeof(x))

void dijkstra (int s) {
    // Be careful with directed graphs!
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &w);
        adj[a].push_back({b, w}); // Be careful!
        adj[b].push_back({a, w}); // Be careful!
    }

    cl(dist, 63);
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int ud = -pq.top().first;
        int u = pq.top().second; pq.pop();
        if (dist[u] < ud) continue;
        for (auto x : adj[u]) {
            int v = x.first;
            int w = x.second;
            if (dist[v] > dist[u] + w) {
                //par[v] = u; //pra recuperar caminho
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
}