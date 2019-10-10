/*
	Resolucao:
		Verificar se e possivel chegar de qualquer ponto
		para todos os pontos.
*/

#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#define MAX 2010

using namespace std;

typedef pair<int, int> ii;

int main()
{
    ios::sync_with_stdio(false);
    double x, y, t;
    while (cin >> x >> y) {
        cout << fixed << setprecision(0) << pow(y, 1 / x) << "\n";
    }
    return 0;
}
