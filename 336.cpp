#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tr1/unordered_map>
#include <vector>
#define mp make_pair
#define pb push_back
#define MAX 70
#define INF 1000000000000000LL

using namespace std;
using namespace tr1;

typedef long long int64;
typedef pair<int, int> ii;
const double EPS = 1e-10;

int E, visited[MAX], ok = 1;
vector<list<int>> graph(MAX);

int BFS(int u, int ttl)
{
    list<int>::iterator it;
    int maior = 0;
    queue<ii> bfs;
    bfs.push(mp(u, 0));
    visited[u] = ok;
    while (!bfs.empty()) {
        ii atual = bfs.front();
        bfs.pop();
        for (it = graph[atual.first].begin(); it != graph[atual.first].end(); it++)
            if (visited[*it] != ok && atual.second + 1 <= ttl) {
                bfs.push(mp(*it, atual.second + 1));
                maior++;
                visited[*it] = ok;
            }
    }
    return maior;
}

int main()
{
    ios::sync_with_stdio(false);
    int t = 1;
    while (cin >> E && E) {
        int de, para, ttl, n = 0;
        unordered_map<int, int> nodes;
        pair<unordered_map<int, int>::iterator, bool> ret;
        for (int i = 0; i < MAX; ++i)
            graph[i].clear();
        for (int i = 0; i < E; ++i) {
            cin >> de >> para;
            ret = nodes.insert(mp(de, n));
            if (ret.second)
                n++;
            ret = nodes.insert(mp(para, n));
            if (ret.second)
                n++;
            graph[nodes[de]].pb(nodes[para]);
            graph[nodes[para]].pb(nodes[de]);
        }
        while (cin >> de >> ttl && de + ttl) {
            cout << "Case " << t++ << ": ";
            cout << nodes.size() - 1 - BFS(nodes[de], ttl) << " nodes not reachable from node " << de << " with TTL = " << ttl << ".\n";
            ok++;
        }
    }
    return 0;
}
