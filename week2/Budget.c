#include <stdio.h> 
int main(){
     double revenue; 
     double expenses;
     double balance;
     printf("Enter total revenue: ");
      scanf("%lf", &revenue);
       printf("Enter total expenses: ");
       scanf("%lf", &expenses);
        balance = revenue - expenses;
        printf("\nRevenue: %.2f\n", revenue); 
        printf("Expenses: %.2f\n", expenses);
        printf("Budget balance: %.2f\n", balance);
         if (balance > 0)
         { printf("Surplus: %.2f\n", balance);
         } else
        if (balance < 0)
        { printf("Deficit: %.2f\n", -balance); 
        } else
        { printf("The budget is balanced.\n"); 
        } 
        return 0; 
     } 