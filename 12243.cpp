#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, b, a) for (int i = b; i >= a; --i)
#define REP(i, N) for (int i = 0; i < N; ++i)
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define pb push_back
#define mp make_pair

using namespace std;

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
