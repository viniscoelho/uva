#include <bits/stdc++.h>
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

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;

vector<list<ii>> graph(MAX);

int V, E, visited[MAX];

int main()
{
    ios::sync_with_stdio(false);
    int de, para, tempo, t;
    while (cin >> t) {
        int jolly[t];
        for (int i = 0; i < t; ++i)
            cin >> jolly[i];
        unordered_map<int, int> bib;
        for (int i = 0; i < t - 1; ++i)
            if (abs(jolly[i] - jolly[i + 1]) >= 1 && abs(jolly[i] - jolly[i + 1]) <= t - 1)
                bib.insert(mp(abs(jolly[i] - jolly[i + 1]), 0));
        if (bib.size() == t - 1)
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";
    }
    return 0;
}
