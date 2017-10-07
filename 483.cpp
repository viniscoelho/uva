#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string resp;
    while ( getline( cin, resp ) ){
		int count = 0;
		string out;
		stringstream ss(resp), sss(resp);
		while ( ss >> out ) count++;
		while ( sss >> out ){
			for ( int i = out.size()-1; i >= 0; --i )
				cout << out[i];
			if ( count > 1 ){
				cout << " ";
				count--;
			}
		}
		cout << "\n";
    }
    return 0;
}
