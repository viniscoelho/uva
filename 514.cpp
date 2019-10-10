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

string buffer;

int main()
{
    ios::sync_with_stdio(false);
    int num, n;
    while (cin >> num && num) {
        vi perm(num);
        while (cin >> perm[0] && perm[0]) {
            stack<int> temp;
            for (int i = 1; i < num; ++i)
                cin >> perm[i];
            int pos = 1;
            for (int i = 0; i < num; ++i) {
                while (pos <= perm[i])
                    temp.push(pos++);
                if (!temp.empty() && temp.top() == perm[i])
                    temp.pop();
                else
                    break;
            }
            if (!temp.empty())
                cout << "No\n";
            else
                cout << "Yes\n";
        }
        cout << "\n";
    }
    return 0;
}
