/*
	Resolucao:
		Primeiramente, verificar se a soma dos diametros das duas
		circunferencias excede o maior dos lados; caso sim, ja sao
		descartadas. Entao realizar uma aplicacao de geometria: determinar
		as coordenadas do centro da circunferencia maior e da circunferencia menor,
		posicionando ambas nos cantos. Se a soma dos raios de cada uma exceder
		essa distancia, nao e possivel coloca-las.
*/

#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back

using namespace std;

typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;

int main(){
    ios::sync_with_stdio(false);
    double m, n, r1, r2;
    while ( cin >> m >> n >> r1 >> r2 && m + n + r1 + r2 )
    {
        double s_max = max(m, n), s_min = min(m, n);
        double r_max = max(r1, r2), r_min = min(r1, r2);
		double xa = r_max, ya = s_min - r_max;
		double xb = s_max - r_min, yb = r_min;
		double d = sqrt( (xb-xa)*(xb-xa) + (yb-ya)*(yb-ya) );
        if ( s_max >= (2*r1 + 2*r2) && s_min < 2*r_max ) cout << "N\n";
		else if ( s_max < (2*r1 + 2*r2) && s_min < 2*r_max ) cout << "N\n";
		else if ( d >= r1+r2 ) cout << "S\n";
		else cout << "N\n";
    }
    return 0;
}
