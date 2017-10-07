#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <map>
#include <bitset>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;

const int INF = 0x3f3f3f3f;

int num;

int64 race[1010], zeros[1010];

int main(){
    ios::sync_with_stdio(false);
	race[0] = 1, race[1] = 1, race[2] = 3, race[3] = 13;
	for ( int i = 0; i < 1005; i++ ) zeros[i] = 1;
	zeros[0] = 1, zeros[1] = 4, zeros[2] = 6, zeros[3] = 4;
    for ( int i = 4; i <= 1000; i++ ) {
        int64 resp = 0;
        for ( int j = 0; j < i; ++j ){
            resp += (zeros[j] * race[j]) % 10056;
			resp %= 10056;
		}
        race[i] = resp;

        for ( int j = i; j >= 1; j-- ){
            zeros[j] += zeros[j-1];
			zeros[j] %= 10056;
		}
    }
	int n, t = 1;
	cin >> n;
	while ( n-- ){
		cin >> num;
		cout << "Case " << t++ << ": " << race[num] << "\n";
	}
    return 0;
}
