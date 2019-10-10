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
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define pb push_back
#define mp make_pair

using namespace std;
using namespace tr1;

typedef long long int64;

int main()
{
    ios::sync_with_stdio(false);
    int64 t;
    while (cin >> t) {
        int64 p, q;
        double num = (1 + sqrt(1 + 8 * t)) / 2;
        if (ceil(num) != floor(num))
            p = floor(num);
        else
            p = num - 1;
        if (t == 1)
            cout << "1/1\n";
        else {
            q = (p * (p - 1)) / 2;
            int64 n = p, d = 1;
            while (q + 1 < t)
                n--, d++, q++;
            cout << n << "/" << d << "\n";
        }
    }
    return 0;
}
