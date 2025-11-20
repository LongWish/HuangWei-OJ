#include <stdio.h>
#include <math.h>

int p, n, ansx, ansy;
double sqrtp, tmp, maxin;

double check(int x, int y){
    return (double)x / (double)y - sqrtp;
}

int main()
{
    while(scanf("%d%d", &p, &n) != EOF)
    {
        sqrtp = sqrt(p);

        maxin = -30000.0;
        for(int i = 1, st; i <= n; i++){
            st = (int)(1.0*i/sqrtp);
            for(int j = st + 1; j > st - 1 && j <= n; j--){
                tmp = check(i, j);
                // printf("%d/%d:%lf  ", i, j, tmp);
                if(tmp > 0) break;
                if(tmp > maxin){
                    maxin = tmp;
                    ansx = i;
                    ansy = j;
                    // printf("\n%lf\n ", maxin);
                }
            }
        }
        
        printf("%d/%d ", ansx, ansy);

        maxin = 30000.0;
        for(int i = 1, st; i <= n; i++){
            st = (int)(1.0*i/sqrtp);
            // printf("%d\n", st);
            for(int j = st; j < st + 2; j++){
                tmp = check(i, j);
                // printf("%d  %d", j, st);
                if(tmp < 0) break;
                if(tmp < maxin){
                    maxin = tmp;
                    ansx = i;
                    ansy = j;
                    // printf("\n%lf\n ", maxin);
                }
            }
        }
        
        printf("%d/%d\n", ansx, ansy);
        
    }
    
    return 0;
}