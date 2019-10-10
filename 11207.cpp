#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n && n) {
        int a, b, pos = 0;
        double m = 0.0;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            double x_max = max(a, b), x_min = min(a, b);
            double val = max(min(x_min, x_max / 4), min(x_min / 2, x_max));
            if (val > m) {
                m = val, pos = i + 1;
            }
        }
        cout << pos << endl;
    }
    return 0;
}