#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define MAX 1010
#define REP(i, V) for (long i = 0; i < V; ++i)
#define REPIT(it, V) for (list<int>::iterator it = V.begin(); it != V.end(); ++it)

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> ii3;
typedef long long int64;
typedef long double Ld;

int main()
{
    long d;
    while (scanf("%ld", &d) && d) {
        double money[d], sum = 0.;
        REP(i, d)
        {
            scanf("%lf", &money[i]);
            sum += money[i];
        }
        sum /= double(d);
        double r1 = 0., r2 = 0.;
        REP(i, d)
        if (money[i] > sum)
            r1 += floor((money[i] - sum) * 100) / 100.;
        else
            r2 += floor((sum - money[i]) * 100) / 100.;
        if (r2 > r1)
            printf("$%.2lf\n", r2);
        else
            printf("$%.2lf\n", r1);
    }
    return 0;
}
