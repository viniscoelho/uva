#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int64;

int main(){
    ios::sync_with_stdio(false);
    int64 a, b, p, q;
    while ( cin >> p >> q ){
        a = max(p, q), b = min(p, q);
        cout << p << " " << q << " ";
        int64 maximum = 1;
        for ( int i = b; i <= a; ++i ){
            int64 aux = i, count = 0;
            while ( true ){
                if ( aux == 1 ){
                    count++;
                    break;
                }
                if ( aux % 2 == 0 ) aux /= 2;
                else aux = 3*aux + 1;
                count++;
            }
            maximum = max( maximum, count );
        }
        cout << maximum << "\n";
    }
    return 0;
}
