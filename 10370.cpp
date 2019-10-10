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

typedef vector<int> vi;
typedef long long int64;
typedef unsigned long long uint64;

int main()
{
    ios::sync_with_stdio(false);
    int num, n;
    cin >> num;
    while (num--) {
        cin >> n;
        double grade[n], a = 0., m = 0.;
        REP(i, n)
        {
            cin >> grade[i];
            m += grade[i];
        }
        m /= double(n);
        REP(i, n)
        if (grade[i] > m) a++;
        cout << fixed << setprecision(3) << (a / double(n)) * 100 << "%\n";
    }
    return 0;
}
