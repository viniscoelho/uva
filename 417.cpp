#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define mp make_pair

using namespace std;

typedef pair<string, string> ss;
typedef map<string, string> mss;
typedef map<string, int> msi;

int main()
{
    ios::sync_with_stdio(false);
    map<string, int> library;
    int tam = 1, count = 1, p = 0;
    bool ok[] = { true, true, true, true };
    for (char i = 'a'; i <= 'z'; ++i) {
        if (tam == 5 && ok[3]) {
            i = 'a';
            ok[3] = false;
        }
        for (char j = 'a'; j <= 'z'; ++j) {
            if (tam == 4 && ok[2]) {
                j = 'a';
                ok[2] = false;
            }
            for (char k = 'a'; k <= 'z'; ++k) {
                if (tam == 3 && ok[1]) {
                    k = 'a';
                    ok[1] = false;
                }
                for (char l = 'a'; l <= 'z'; ++l) {
                    if (tam == 2 && ok[0]) {
                        l = 'a';
                        ok[0] = false;
                    }
                    for (char m = 'a'; m <= 'z'; ++m) {
                        string resp = "";
                        if (tam == 1) {
                            resp += m;
                            library.insert(mp(resp, count++));
                        }
                        if (tam == 2 && m > l) {
                            resp += l;
                            resp += m;
                            library.insert(mp(resp, count++));
                        }
                        if (tam == 3 && m > l && l > k) {
                            resp += k;
                            resp += l;
                            resp += m;
                            library.insert(mp(resp, count++));
                        }
                        if (tam == 4 && m > l && l > k && k > j) {
                            resp += j;
                            resp += k;
                            resp += l;
                            resp += m;
                            library.insert(mp(resp, count++));
                        }
                        if (tam == 5 && m > l && l > k && k > j && j > i) {
                            resp += i;
                            resp += j;
                            resp += k;
                            resp += l;
                            resp += m;
                            library.insert(mp(resp, count++));
                        }
                    }
                    if (tam == 1 && l == 'a')
                        tam++;
                }
                if (tam == 2 && k == 'a')
                    tam++;
            }
            if (tam == 3 && j == 'a')
                tam++;
        }
        if (tam == 4 && i == 'a')
            tam++;
    }
    string str;
    while (getline(cin, str)) {
        cout << library[str] << endl;
    }
    return 0;
}
