#include <cstdio>
#include <cstdlib>

int main()
{
    int i, j, n, q, x, y, k = 0;
    scanf("%d", &n);
    int chimps[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &chimps[i]);
    scanf("%d", &q);
    for (i = 0; i < q; ++i) {
        scanf("%d", &y);
        int mini = -1;
        if (y < chimps[0]) {
            printf("X %d\n", chimps[0]);
            continue;
        }
        for (j = 0; j < n && chimps[j] < y; ++j)
            mini = chimps[j];
        if (mini == -1)
            printf("X ");
        else
            printf("%d ", mini);
        if (j >= n)
            printf("X\n");
        else {
            while (j < n && chimps[j] <= y)
                j++;
            if (j < n)
                printf("%d\n", chimps[j]);
            else
                printf("X\n");
        }
    }
    return 0;
}
