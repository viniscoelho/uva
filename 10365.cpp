#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, b, h, resp = 1000000, p;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; ++j) {
                if (!(n % (i * j))) {
                    h = n / (i * j);
                    p = 2 * i * j + 2 * i * h + 2 * j * h;
                    resp = min(resp, p);
                }
            }
        }
        cout << resp << "\n";
    }
    return 0;
}
