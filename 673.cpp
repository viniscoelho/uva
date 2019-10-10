#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char stack[1000];

int main()
{
    ios::sync_with_stdio(false);
    int i, j, n;
    cin >> n;
    cin.ignore();
    for (i = 0; i < n; ++i) {
        string resp;
        getline(cin, resp);
        int topo = 0, flag = 0;
        for (j = 0; j < resp.size(); ++j) {
            if (topo == 0) {
                stack[topo] = resp[j];
                topo++;
            } else if (stack[topo - 1] == '(' && resp[j] == ')')
                topo--;
            else if (stack[topo - 1] == '[' && resp[j] == ']')
                topo--;
            else if (stack[topo - 1] == '(' && resp[j] == ']') {
                flag = 1;
                break;
            } else if (stack[topo - 1] == '[' && resp[j] == ')') {
                flag = 1;
                break;
            } else {
                stack[topo] = resp[j];
                topo++;
            }
        }
        if (flag)
            cout << "No\n";
        else if (topo != 0)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}
