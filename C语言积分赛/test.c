#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double u[5000], v[5000];

int main() {
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n, m;
    scanf("%d %d", &n, &m);

    int nr = n % 3;
    if (nr == 0) {
        for (int i = 0; i < n; ++i) {
            int rm = i % 3;
            if (rm == 0) u[i] = 0.0;
            else if (rm == 1) u[i] = 1.0;
            else u[i] = 0.0;
        }
    } else if (nr == 1) {
        for (int i = 0; i < n; ++i) {
            int rm = i % 3;
            if (rm == 0) u[i] = 1.0;
            else if (rm == 1) u[i] = 0.0;
            else u[i] = 0.0;
        }
    } else {
        for (int i = 0; i < n; ++i) {
            int rm = i % 3;
            if (rm == 0 || rm == 1) u[i] = 0.5;
            else u[i] = 0.0;
        }
    }
    
    int mr = m % 3;
    if (mr == 0) {
        for (int j = 0; j < m; ++j) {
            int rm = j % 3;
            if (rm == 0) v[j] = 0.0;
            else if (rm == 1) v[j] = 1.0;
            else v[j] = 0.0;
        }
    } else if (mr == 1) {
        for (int j = 0; j < m; ++j) {
            int rm = j % 3;
            if (rm == 0) v[j] = 1.0;
            else if (rm == 1) v[j] = 0.0;
            else v[j] = 0.0;
        }
    } else { // mr == 2
        for (int j = 0; j < m; ++j) {
            int rm = j % 3;
            if (rm == 0 || rm == 1) v[j] = 0.5;
            else v[j] = 0.0;
        }
    }
    
    double S = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            scanf("%d", &a);
            S += u[i] * v[j] * a;
        }
    }
    
    printf("%.0lf\n", round(S));
    
    return 0;
}