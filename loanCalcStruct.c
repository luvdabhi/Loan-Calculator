#include<stdio.h>
#include<math.h>

void output_amortized(float loan_amount, float intrest_rate, int term_years) {
    int i, j;
    int payments;
    float loanAmount;
    float anIntRate;
    float monIntRate;
    float monthPayment;
    float balance;
    float monthPrinciple;
    float monthPaidInt;

    balance = loan_amount;

    monIntRate = ((intrest_rate / (100 * 12)));

    payments = term_years;
    monthPayment = (loan_amount * monIntRate * (pow(1 + monIntRate, payments) / (pow(1 + monIntRate, payments) - 1)));
    monthPaidInt = balance * monIntRate;

    monthPrinciple = monthPayment - monthPaidInt;

    balance = balance - monthPrinciple;

    printf("\n\nMonthly payment should be :%.2f\n\n", monthPayment);
    printf("============================AMORTIZATION SCHEDUAL==========================\n");
    printf("#\tPayment\t\tIntrest\t\tPrinciple\t\tBalance\n");

    for (i = 0; i < payments; i++) {
        printf("%d%9c%.2f%9c%.2f%16c%.2f%14c%.2f\n", (i + 1), '$', monthPayment, '$', monthPaidInt, '$', monthPrinciple, '$', balance);
        monthPaidInt = balance * monIntRate;

        monthPrinciple = monthPayment - monthPaidInt;

        balance = balance - monthPrinciple;
    }
}
int main() {
    float principle, rate;
    int termYear;
    printf("Enter the loan amount: $");
    scanf("%f", &principle);
    printf("Enter the intrest rate :%");
    scanf("%f", &rate);
    printf("Enter the loan duration in years: ");
    scanf("%d", &termYear);

    output_amortized(principle, rate, termYear);
}


