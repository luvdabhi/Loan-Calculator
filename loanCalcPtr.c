#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double loanAmount, interestRatePerYear;
    int n, i;
    double A, r;
    double INT_l[1000], B_l[1000], P_l[1000];
    double* INT = INT_l;
    double* B = B_l;
    double* P = P_l;

    printf("Enter amount of loan : $ ");
    scanf("%lf", &loanAmount);
    printf("Enter interest rate per year : %% ");
    scanf("%lf", &interestRatePerYear);
    printf("Enter number of payments : ");
    scanf("%d", &n);

    r = interestRatePerYear / 1200;
    A = loanAmount * ((r * pow(1 + r, n)) / (pow(1 + r, n) - 1));
    B[0] = loanAmount;

    printf("\nMontly payment should be %lf\n", A - B[0] * r);
    for (i = 0; i < 24; i++)
        printf("=");
    printf("AMORTIZATION SCHEDULE");
    for (i = 0; i < 24; i++)
        printf("=");
    printf("\n");
    printf("# \t Payment \t Principal \t Interest \t Balance\n");
    for (i = 1; i <= n; i++) {
        INT[i] = B[i - 1] * r;
        P[i] = A - INT[i];
        B[i] = B[i - 1] - P[i];
        printf("%d \t $%0.2lf \t $%0.2lf \t $%0.2lf ", i, A, P[i], INT[i]);
        if (INT[i] / 10.0 < 1.0)
            printf("\t\t $%0.2lf", B[i]);
        else
            printf("\t $%0.2lf", B[i]);
        printf("\n");
    }
    return 0;
}
