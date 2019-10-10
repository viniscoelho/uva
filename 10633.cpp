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
#define MAXN 1000000000000
#define N 1000000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define pb push_back
#define mp make_pair

using namespace std;
using namespace tr1;

typedef long long int64;
typedef unsigned long long uint64;
typedef vector<int64> vi;

int main()
{
    ios::sync_with_stdio(false);
    uint64 n;
    while (cin >> n && n) {
        if (!(n % 9))
            cout << (n * 10) / 9 - 1 << " " << (n * 10) / 9 << "\n";
        else
            cout << (n * 10) / 9 << "\n";
    }
    return 0;
}
