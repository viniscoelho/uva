#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, b, a) for (int i = b; i >= a; --i)
#define REP(i, N) for (int i = 0; i < N; ++i)
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef long long int64;
typedef unsigned long long uint64;

string buffer;

int main()
{
    ios::sync_with_stdio(false);
    int num, n = 0;
    cin >> num;
    cin.ignore();
    getline(cin, buffer);
    while (num--) {
        if (n > 0)
            cout << "\n";
        map<string, double> trees;
        map<string, double>::iterator mit;
        pair<map<string, double>::iterator, bool> ret;
        double cont = 0.;
        while (getline(cin, buffer) && buffer.size()) {
            ret = trees.insert(mp(buffer, 1.));
            if (!ret.second)
                trees[buffer]++;
            cont++;
        }
        for (mit = trees.begin(); mit != trees.end(); ++mit)
            cout << mit->first << " " << fixed << setprecision(4) << ((mit->second) / cont) * 100 << "\n";
        n++;
    }
    return 0;
}
