#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, p = 1;
    for (cin >> n; n != 0; cin >> n) {
        cout << "Scenario #" << p++ << "\n";
        double frog[n][n], resp[n][2];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++)
                if (i == j)
                    frog[i][j] = 0;
                else
                    frog[i][j] = frog[j][i] = LONG_MAX;
        }
        for (int i = 0; i < n; ++i)
            cin >> resp[i][0] >> resp[i][1];
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                frog[j][i] = frog[i][j] = sqrt(pow(resp[j][0] - resp[i][0], 2) + pow(resp[j][1] - resp[i][1], 2));
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    frog[i][j] = min(frog[i][j], max(frog[i][k], frog[k][j]));
        cout << "Frog Distance = ";
        cout << fixed << setprecision(3) << frog[0][1] << "\n\n";
    }
    return 0;
}
