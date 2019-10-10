#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#define pb push_back
#define mp make_pair
#define MAXV 3000010

using namespace std;

typedef pair<int, int> prime_pot;
typedef long long int64;

const unsigned MAX = 2000100 / 60, MAX_S = sqrt(MAX / 60);

unsigned w[16] = { 1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59 };
unsigned short composite[MAX];
vector<bool> primes(MAXV, false);

void sieve()
{
    unsigned mod[16][16], di[16][16], num;
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++) {
            di[i][j] = (w[i] * w[j]) / 60;
            mod[i][j] = lower_bound(w, w + 16, (w[i] * w[j]) % 60) - w;
        }
    primes[2] = primes[3] = primes[5] = true;

    for (unsigned i = 0; i < MAX; i++)
        for (int j = (i == 0); j < 16; j++) {
            if (composite[i] & (1 << j))
                continue;
            primes[num = 60 * i + w[j]] = true;
            if (i > MAX_S)
                continue;
            for (unsigned k = i, done = false; !done; k++)
                for (int l = (k == 0); l < 16 && !done; l++) {
                    unsigned mult = k * num + i * w[l] + di[j][l];
                    if (mult >= MAX)
                        done = true;
                    else
                        composite[mult] |= 1 << mod[j][l];
                }
        }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    sieve();
    while (cin >> n && n) {
        bool flag = false;
        for (int i = 2; i < n; ++i)
            if (primes[i] && primes[n - i]) {
                cout << n << " = " << i << " + " << n - i << "\n";
                flag = true;
                break;
            }
        if (!flag)
            cout << "Goldbach's conjecture is wrong.\n";
    }
    return 0;
}
