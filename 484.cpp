#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define MAX 70
#define INF 1000000000000000LL

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
const double EPS = 1e-10;

int main()
{
    ios::sync_with_stdio(false);
    int n, qtd = 0;
    unordered_map<int, ii> numbers;
    vector<ii> redun;
    pair<unordered_map<int, ii>::iterator, bool> ret;
    while (cin >> n) {
        ret = numbers.insert(mp(n, mp(qtd, 1)));
        if (!ret.second)
            redun[numbers[n].first].second++;
        else {
            redun.pb(mp(n, 1));
            qtd++;
        }
    }
    for (int i = 0; i < redun.size(); ++i)
        cout << redun[i].first << " " << redun[i].second << "\n";
    return 0;
}
