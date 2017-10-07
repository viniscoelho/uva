/*
	Resolucao:
		Verificar qual a maior cadeia alimentar pode ser
		obtida. Basta aplicar o algoritmo de tarjan que retornara
		a maior componente fortemente conexa
*/

#include <iostream>
#include <cmath>
#include <string>
#include <tr1/unordered_map>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <queue>
#define mp make_pair
#define pb push_back
#define MAXV 5000
#define COLOR 0

using namespace std;
using namespace tr1;

typedef vector<int> vi;

vector< list<int> > graph(MAXV);
vi S;
int visited[MAXV], dfs_low[MAXV], dfs_num[MAXV];

int counter, m, n, MAX;

void tarjan( int u ){
	dfs_low[u] = dfs_num[u] = counter++;
	S.pb(u);
	visited[u] = 1;
	set<int> resp;
	list<int>::iterator i;
	for ( i = graph[u].begin(); i != graph[u].end(); ++i ){
		if ( dfs_num[*i] == COLOR ) tarjan(*i);
		if ( visited[*i] )
			dfs_low[u] = min( dfs_low[u], dfs_low[*i] );
	}
	if ( dfs_low[u] == dfs_num[u] ){
        while ( 1 ){
			int vertex = S.back(); S.pop_back();
			resp.insert(vertex); visited[vertex] = 0;
			if ( u == vertex ) break;
        }
		MAX = max( MAX, (int)resp.size() );
	}
}

int main(){
	ios::sync_with_stdio(false);
	string nature, a, b;
	bool flag = false;
    while ( cin >> m >> n && m + n ){
		cin.ignore();
		if ( flag )
			for ( int i = 0; i < m; ++i ){
				dfs_num[i] = COLOR;
				dfs_low[i] = visited[i] = COLOR;
				graph[i].clear();
			}
		counter = 0, MAX = 1;
		unordered_map<string, int> chain;
		int t = 0;
		for ( int i = 0; i < m; ++i ){
			cin >> nature;
			chain.insert( mp( nature, t ) );
			t++;
		}
		for ( int i = 0; i < n; ++i ){
			cin >> a >> b;
			graph[ chain[a] ].pb( chain[b] );
			graph[ chain[b] ].pb( chain[a] );
		}
		for ( int k = 0; k < m; k++ ){
			if ( dfs_num[k] == COLOR )
				tarjan(k);
		}
		cout << MAX << "\n";
		flag = true;
	}
	return 0;
}
