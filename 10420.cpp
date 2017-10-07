#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#define mp make_pair

using namespace std;

typedef pair<string, string> ss;
typedef map<string, string> mss;
typedef map<string, int> msi;

int main(){
    ios::sync_with_stdio(false);
    int n;
    while ( cin >> n ){
          cin.ignore();
          string country, love;
          mss gio;
          msi resp;
          pair< mss::iterator, bool > ret;
          int count = 0;
          for ( int i = 0; i < n; ++i ){
              cin >> country;
              getline(cin, love);
              ret = gio.insert( mp(love, country) );
              if ( ret.second )
                 resp[country]++;
          }
          for ( msi::iterator it = resp.begin(); it != resp.end(); it++ )
              cout << (*it).first << " " << (*it).second << endl;
    }
    return 0;
}
