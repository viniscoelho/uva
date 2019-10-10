#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int64;

int main()
{
    int64 a, b;
    while (scanf("%lld %lld", &a, &b) != EOF)
        printf("%lld\n", abs(a - b));
    return 0;
}
