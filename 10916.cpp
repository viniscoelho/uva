/*
	Resolucao:
		Como o expoente pode ser muito grande, assim como o numero
		basta verificar qual o logaritmo e o maior, pois:
		log(a^b) = b*log(a)
		Para o fatorial, basta verificar a seguinte propriedade:
		log(n!) = log(n * n-1 * n-2... * 1) = log(n) + log (n-1) + ...
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tr1/unordered_map>
#include <utility>
#include <vector>
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
using namespace tr1;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    unordered_map<int, int> bib;
    int qtd = 2;
    for (int i = 0; i <= 200; ++i) {
        if (!(i % 10))
            qtd *= 2;
        bib.insert(mp(i, qtd));
    }
    while (cin >> t && t) {
        int qtd = 0;
        double l = double(bib[t - 1960]) * log(2), resp = 0.;
        for (double i = 2; resp < l; ++i) {
            resp += log(i);
            qtd++;
        }
        cout << qtd << "\n";
    }
    return 0;
}
