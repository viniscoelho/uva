#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define pb push_back
#define mp make_pair

using namespace std;
using namespace tr1;

typedef long long int64;
typedef pair<int, int> ii;

char *p, a, word[1010];

int main()
{
    while (scanf(" %[^\n]s", &word) && strcmp(word, "*")) {
        p = strtok(word, " ");
        int ans = 0, cont = 0, f = false;
        while (p != NULL) {
            if (!cont)
                cont++, a = tolower(*p);
            else if (cont == 1 && tolower(*p) == a)
                ans++, cont++;
            else if (tolower(*p) != a) {
                printf("N\n");
                f = !f;
                break;
            }
            p = strtok(NULL, " ");
        }
        if (!f)
            printf("Y\n");
    }
    return 0;
}
