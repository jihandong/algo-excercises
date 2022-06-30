#include <stdio.h>
#include <stdlib.h>
#include <cstring>

struct Number {
    int n;
    int v[10];
};

struct Number T[3];
struct Number N[3];
int X[100000];

void show(int n)
{
    for (int k = 0; k < 3; k++) {
        printf("[");
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < N[k].v[i]; j++) {
                printf("%d", i);
            }
        }
        printf("]");
    }
    if (n > 0)
        printf(" <= %d\n", n);
    else
        printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
        return 0;
    for (int i = 1; i < argc; i++)
        X[i] = atoi(argv[i]);

    for (int i = 1; i < argc; i++) {
        show(X[i]);
        memset(T, 0, sizeof(T));
        for (int j = 0; j < 3; j++) {
            if (N[j].n) {
                int id = (j + X[i]) % 3;
                memcpy(&T[id], &N[j], sizeof(struct Number));
                T[id].n++;
                T[id].v[X[i]]++;
            }
        }
        for (int j = 0; j < 3; j++) {
            if (!T[j].n) {
                memcpy(&T[j], &N[j], sizeof(struct Number));
            }
        }
        memcpy(N, T, sizeof(T));
        int id = X[i] % 3;
        if (!N[id].n) {
            N[id].n++;
            N[id].v[X[i]]++;
        }
    }

    show(-1);
}
