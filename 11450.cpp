#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;

//note: perform a bfs for the flood and another for the people

int M, N, C;
int memo[220][2], price[25][25];

struct node {
    int x, y, steps;
    node(int x = 0, int y = 0, int steps = 0)
        : x(x)
        , y(y)
        , steps(steps)
    {
    }
};

//complexity: O(M*C*K)
//top-down (aka recursive)
/*int solve(int money, int g)
{
    if ( money < 0 ) return -INF;
    if ( g == C ) return M-money;
    if ( memo[money][g] != -1 ) return memo[money][g]; //is this state visited?
    int ans = -INF;
    for ( int i = 1; i <= price[g][0]; i++ )
        ans = max(ans, solve(money - price[g][i], g+1)); //try all possible solutions
    return memo[money][g] = ans; //assign the value

}
*/

//solution with two columns (bitmask), alternating the columns from prev to actual, saving space
int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    int i, f = 1; //a cheat so I don't have to initialize memo again
    while (N--) {
        cin >> M >> C;
        for (int g = 0; g < C; g++) {
            cin >> price[g][0]; //value of K
            for (int j = 1; j <= price[g][0]; j++)
                cin >> price[g][j];
        }
        memset(memo, 0, sizeof memo);

        int b = 1;
        for (int g = 1; g <= price[0][0]; g++) //first garment
            memo[M - price[0][g]][0] = 1; //g start at 1 because 0 has K's value

        for (int g = 1; g < C; g++) //garment
        {
            for (int money = 0; money < M; money++) //money
                if (memo[money][b ^ (1 << 0)]) //is this state visited?
                    for (int k = 1; k <= price[g][0]; k++)
                        if (money - price[g][k] >= 0) //check if the money-price[g][k] isn't negative
                            memo[money - price[g][k]][b] = 1; //then value on the current column is true

            for (int k = 0; k <= M; k++) //now, the previous column is set to false so it can be the current on the next iteration
                memo[k][b ^ (1 << 0)] = 0;
            b ^= (1 << 0);
        }

        for (i = 0; i <= M && !memo[i][b ^ (1 << 0)]; i++)
            ; //the answer is in the last column

        if (i == M + 1)
            cout << "no solution\n";
        else
            cout << M - i << "\n";
        //f++;
    }

    return 0;
}