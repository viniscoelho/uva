#include <stdio.h>
#include <stdlib.h>

char fbt[1048576];
int* results[21];

void drop()
{
    register int depth, max, maxDepth, i;
    for (depth = 2; depth < 21; depth++) {
        max = (1 << depth) - 1;
        maxDepth = 1 << (depth - 1);
        for (i = 0; i < max; i++)
            fbt[i] = 0;
        int pos;
        for (i = 0; i < maxDepth; i++) {
            pos = 1;
            while (pos < maxDepth)
                pos = 2 * pos + !(fbt[pos] = fbt[pos] ^ 1);
            results[depth][i] = pos;
        }
    }
}

int main()
{
    int i, j, c;
    for (i = 2; i <= 20; i++)
        results[i] = (int*)malloc(((1 << (i - 1))) * sizeof(int));
    drop();
    scanf("%d", &c);
    while (c--) {
        scanf("%d %d", &i, &j);
        printf("%d\n", results[i][(j - 1) % (1 << (i - 1))]);
    }
    return 0;
}
