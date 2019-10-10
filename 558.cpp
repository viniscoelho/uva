/*
	Resolucao:
		Verificar se o grafo possui um ciclo negativo.
		Isso pode ser verificado utilizando o algoritmo de Bellman-Ford.
*/

#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, b, a) for (int i = b; i >= a; --i)
#define REP(i, N) for (int i = 0; i < N; ++i)
#define REPIT(c, it) for (list<ii>::iterator it = c.begin(); it != c.end(); it++)
#define MAX 1010
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;

vector<list<ii>> graph(MAX);

int V, E, visited[MAX];

int main()
{
    ios::sync_with_stdio(false);
    int de, para, tempo, t;
    cin >> t;
    while (t--) {
        cin >> V >> E;
        for (int i = 0; i < V; ++i)
            graph[i].clear();
        for (int i = 0; i < E; ++i) {
            cin >> de >> para >> tempo;
            graph[de].pb(mp(para, tempo));
        }
        vector<int> dist(V, INF);
        dist[0] = 0; // INF = 2^31-1
        REP(i, V - 1) // relax all E edges V-1 times, O(V)
        REP(u, V) // these two loops = O(E)
        REPIT(graph[u], v) // relax these edges
        dist[v->first] = min(dist[v->first], dist[u] + v->second);

        bool flag = false;
        REP(u, V - 1) // one more pass to check
        REPIT(graph[u], v)
        if (dist[v->first] > dist[u] + v->second) {
            flag = true;
            break;
        }
        if (flag)
            cout << "possible\n";
        else
            cout << "not possible\n";
    }
    return 0;
}
