#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> ii3;

int main()
{
    ios::sync_with_stdio(false);
    int s = 1, n, t, num;
    while (cin >> n && n) {
        cout << "Scenario #" << s++ << "\n";
        unordered_map<int, ii> bib;
        vector<ii3> teams;
        string comm;
        for (int i = 0; i < n; ++i) {
            cin >> t;
            teams.pb(mp(t, mp(INF, 0)));
            for (int k = 0; k < t; ++k) {
                cin >> num;
                bib[num] = mp(i, t);
            }
        }
        int prior = INF;
        priority_queue<ii3> pq;
        while (cin >> comm && comm != "STOP") {
            if (comm == "ENQUEUE") {
                cin >> num;
                int team = bib[num].first;
                if (teams[team].first == bib[num].second) {
                    pq.push(mp(prior, mp(teams[team].second.first--, num)));
                    teams[team].second.second = prior--;
                    teams[team].first--;
                } else {
                    pq.push(mp(teams[team].second.second, mp(teams[team].second.first--, num)));
                    teams[team].first--;
                }
            } else {
                ii3 a = pq.top();
                pq.pop();
                int team = bib[a.second.second].first;
                teams[team].first++;
                cout << a.second.second << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
