#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    long long t, n, b, m, y;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> b;
        long long sum = 0;
        for (int j = 0; j < b; ++j) {
            long long resp = 1;
            cin >> y;
            for (int k = 0; k < y; ++k) {
                cin >> m;
                resp = (resp * m) % n;
            }
            sum = (sum + resp) % n;
        }
        cout << sum << "\n";
    }
    return 0;
}
