#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <iomanip>
#include <tr1/unordered_map>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define MAX 1010
#define REP(i, N) for( long i = 0; i < N; ++i )
#define FOR(i, A, B) for( long i = A; i <= B; ++i )
#define REPIT(it, V) for( list<int>::iterator it = V.begin(); it != V.end(); ++it )

using namespace std;
using namespace tr1;

typedef pair<int, int> ii;
typedef pair<int, ii> ii3;
typedef long long int64;
typedef long double Ld;

int main(){
	long a, b, d, t = 1;
	scanf("%ld", &d);
	while ( d-- ){
		long sum = 0;
		scanf("%ld %ld", &a, &b);
		if ( !(a % 2) ) a++;
		FOR(i, a, b) if ( i % 2 ) sum += i;
		printf("Case %ld: %ld\n", t++, sum);
	}
	return 0;
}

