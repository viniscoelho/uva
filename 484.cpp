#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <climits>
#include <algorithm>
#include <tr1/unordered_map>
#define mp make_pair
#define pb push_back
#define MAX 70
#define INF 1000000000000000LL

using namespace std;
using namespace tr1;

typedef long long int64;
typedef pair<int, int> ii;
const double EPS = 1e-10;

int main(){
	ios::sync_with_stdio(false);
	int n, qtd = 0;
	unordered_map<int, ii> numbers;
	vector<ii> redun;
	pair<unordered_map<int, ii>::iterator, bool> ret;
	while ( cin >> n ){
		ret = numbers.insert( mp( n, mp( qtd, 1 ) ) );
		if ( !ret.second ) redun[numbers[n].first].second++;
		else{
			redun.pb( mp(n, 1) );
			qtd++;
		}
	}
	for ( int i = 0; i < redun.size(); ++i ) cout << redun[i].first << " " << redun[i].second << "\n";
    return 0;
}
