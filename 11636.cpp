#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int x, i = 1;
    for ( cin >> x; x > 0; cin >> x ){
        int c = 1, cont = 0;
        while ( c < x ){
			c *= 2;
			cont++;
        }
        cout << "Case " << i++ << ": " << cont << "\n";
    }
    return 0;
}
