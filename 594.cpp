#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;

int little_to_big( int val ){
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF ); 
    return (val << 16) | ((val >> 16) & 0xFFFF);
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	while ( cin >> n )
		cout << n << " converts to " << little_to_big(n) << "\n";
	return 0;
}
