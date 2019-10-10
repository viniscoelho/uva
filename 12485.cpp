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
#define pb push_back
#define mp make_pair

using namespace std;
using namespace tr1;

typedef vector<int> vi;
typedef long long int64;
typedef unsigned long long uint64;

int coral[1000000];

int main()
{
    int t, valor;
    while (scanf("%d", &t) != EOF) {
        int soma = 0, maior = -1, resp = 1, pos;
        REP(i, t)
        {
            scanf("%d", &coral[i]);
            soma += coral[i];
        }
        if (soma % t)
            printf("-1\n");
        else {
            int qtd = 0;
            REP(i, t)
            if (coral[i] > soma / t) qtd += coral[i] - (soma / t);
            printf("%d\n", qtd + 1);
        }
    }
    return 0;
}
