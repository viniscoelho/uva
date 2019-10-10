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
#define MAXN 1000000000000
#define N 1000000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define pb push_back
#define mp make_pair

using namespace std;
using namespace tr1;

typedef long long int64;
typedef unsigned long long uint64;
typedef vector<int64> vi;

typedef pair<int, int> prime_pot;

const unsigned MAX = 2000100 / 60, MAX_S = sqrt(MAX / 60);

unsigned w[16] = { 1, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 49, 53, 59 };
unsigned short composite[MAX];
vi primes;

void sieve()
{
    unsigned mod[16][16], di[16][16], num;
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++) {
            di[i][j] = (w[i] * w[j]) / 60;
            mod[i][j] = lower_bound(w, w + 16, (w[i] * w[j]) % 60) - w;
        }
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);

    for (unsigned i = 0; i < MAX; i++)
        for (int j = (i == 0); j < 16; j++) {
            if (composite[i] & (1 << j))
                continue;
            primes.push_back(num = 60 * i + w[j]);
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
    sieve();
    vector<int64> almost;
    for (int i = 0; i < primes.size(); ++i)
        for (int64 j = primes[i] * primes[i]; j <= MAXN; j *= primes[i])
            almost.pb(j);
    sort(almost.begin(), almost.end());
    int64 num, a, b;
    cin >> num;
    while (num--) {
        cin >> a >> b;
        int64 resp = 0;
        vi::iterator it;
        for (int64 i = 0; i < almost.size(); ++i)
            if (almost[i] >= a && almost[i] <= b)
                resp++;
        cout << resp << "\n";
    }
    return 0;
}
