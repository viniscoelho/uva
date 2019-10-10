#include <algorithm>
#include <cmath>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define mp make_pair
#define pb push_back
#define MAXV 5000
#define COLOR 0

using namespace std;

typedef vector<int> vi;

int counter, m, n, MAX;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        vi resp;
        cin >> n;
        int s = n, soma = 0, ans;
        while (n--) {
            cin >> m;
            resp.pb(m);
            soma += m;
        }
        soma /= s;
        sort(resp.begin(), resp.end());
        ans = 2 * (soma - resp[0]) + 2 * (resp[resp.size() - 1] - soma);
        cout << ans << "\n";
    }
    return 0;
}
