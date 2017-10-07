#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
#define mp make_pair

using namespace std;

typedef struct no {
	int pai, rank, peso;
	bool visitado;
}Tno;

vector<Tno> pset;
typedef pair<int, int> ii;

void inicializa ( int n ){
	pset.resize(n);
	for ( int i = 0; i < n; i++ ){
		pset[i].pai = i;
		pset[i].rank = 0;
		pset[i].peso = 0;
		pset[i].visitado = false;
	}
}

void link ( int x, int y ){
	if ( pset[x].rank > pset[y].rank ) pset[y].pai = x;
	else{
		pset[x].pai = y;
		if ( pset[x].rank == pset[y].rank ) pset[y].rank++;
	}
}	

int findSet ( int x ){
    if ( pset[x].pai != x )
	   pset[x].pai = findSet ( pset[x].pai );
    return ( pset[x].pai );	
}

void unionSet ( int x, int y ){
	link ( findSet(x), findSet(y) );
}

int pegaPai ( int x ){
	while ( pset[x].pai != x )
		x = pset[x].pai;
	return x;
}

int main(){
    ios::sync_with_stdio(false);
    int p, v, a, t;
	cin >> t;
    while ( t-- ){
		cin >> v >> a;
		inicializa(v);
		for ( int i = 0; i < v; ++i ){
			cin >> p;
			pset[i].peso = p;
		}
		int b, c;
		queue <int> amigos, friends;
		for ( int i = 0; i < a; ++i ){
			cin >> b >> c;
			unionSet( b, c );
			amigos.push( b );
			amigos.push( c );
		}
		friends = amigos;
		while ( !amigos.empty() ){
			int x = amigos.front();
			amigos.pop();
			if ( !pset[x].visitado ){
				int y = pegaPai(x);
				pset[y].peso += pset[x].peso;
				pset[x].peso = 0;
				pset[x].visitado = pset[y].visitado = true;
			}
		}
		bool flag = false;
		while ( !friends.empty() ){
			int x = friends.front();
			friends.pop();
			if ( pset[pset[x].pai].peso != 0 ){
				cout << "IMPOSSIBLE\n";
				flag = true;
				break;
			}
		}
		if ( !flag ) cout << "POSSIBLE\n";
    }
    return 0;
}
