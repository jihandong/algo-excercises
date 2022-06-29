/* find part sum, which is 7x.
 */
#include <bits/stdc++.h>

int n;
int x[100000];
int F[7];

int main (int argc, char *argv[])
{
    // input
    if (argc < 2)
        return 0;
    n = argc - 1;
    for (int i = 1; i < argc; i++) {
        x[i - 1] = atoi(argv[i]);
    }

    int result;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        printf("[%d][%d][%d][%d][%d][%d][%d] <= %d\n",
            F[0], F[1], F[2], F[3], F[4], F[5], F[6], x[i]);
        int f[7] = {0};
        sum += x[i];
        for (int j = 0; j < 7; j++) {
            int tmp = F[j] + x[i];
            int index = tmp % 7;
            if (F[index] < tmp) {
                f[index] = tmp;
            }
        }
        for (int j = 0; j < 7; j++) {
            if (F[j] < f[j])
                F[j] = f[j];
        }
    }
    printf("[%d][%d][%d][%d][%d][%d][%d]\n",
        F[0], F[1], F[2], F[3], F[4], F[5], F[6]);

    // output
    printf("%d\n", F[0]);
    return 0;
}
