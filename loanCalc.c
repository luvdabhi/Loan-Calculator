#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double loanAmount, interestRatePerYear;
    int n, i;
    double A, r;
    double INT, B, P;

    printf("Enter amount of loan : $ ");
    scanf("%lf", &loanAmount);
    printf("Enter interest rate per year : %% ");
    scanf("%lf", &interestRatePerYear);
    printf("Enter number of payments : ");
    scanf("%d", &n);

    r = interestRatePerYear / 1200;
    A = loanAmount * ((r * pow(1 + r, n)) / (pow(1 + r, n) - 1));
    B = loanAmount;

    printf("\nMontly payment should be %lf\n", A - B * r);

    for (i = 0; i < 24; i++)
        printf("=");
    printf("AMORTIZATION SCHEDULE");
    for (i = 0; i < 24; i++)
        printf("=");
    printf("\n");
    printf("# \t Payment \t Principal \t Interest \t Balance\n");
    for (i = 1; i <= n; i++) {
        INT = B * r;
        P = A - INT;
        B = B - P;
        printf("%d \t $%0.2lf \t $%0.2lf \t $%0.2lf ", i, A, P, INT);
        if (INT / 10.0 < 1.0)
            printf("\t\t $%0.2lf", B);
        else
            printf("\t $%0.2lf", B);
        printf("\n");
    }
    return 0;
}
