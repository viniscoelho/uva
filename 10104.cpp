#include <iostream>

using namespace std;

typedef pair<long long, long long> ll;

ll find_bezout(long long x, long long y)
{
    if (y == 0)
        return ll(1, 0);
    ll u = find_bezout(y, x % y);
    return ll(u.second, u.first - (x / y) * u.second);
}

int main()
{
    ios::sync_with_stdio(false);
    long long x, y, d;
    while (cin >> x >> y) {
        ll b = find_bezout(x, y);
        d = x * b.first + y * b.second;
        cout << b.first << " " << b.second << " " << d << endl;
    }
    return 0;
}
