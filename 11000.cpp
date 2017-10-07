#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <cstring>
#include <cstdio>
#define MAX 500
#define color 2
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, bool> ib;
typedef vector<int> vi;
typedef unsigned long long int64;

const int INF = 0x3f3f3f3f;

int64 n, m, fib[MAX];

int main(){
	ios::sync_with_stdio(false);
	fib[0] = 0, fib[1] = 1, fib[2] = 1;
	for ( int i = 3; i < 100; i++ )
		fib[i] = fib[i-1] + fib[i-2];
    while ( cin >> n && n != -1 ){
		cout << fib[n+2]-1 << " " << fib[n+3]-1 << "\n";
    }
       
    return 0;
}
