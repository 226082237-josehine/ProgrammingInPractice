
#include <stdio.h>
int Call_budget(){
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
            } else { printf("The budget is balanced.\n");} 
             return 0; 
     } 


int main() {
    char municipality[50]; 
    char mayor[50]; 
    int population;
    int gender;
    int budget_choice;
    printf("Municipal Financial Management System\n\n");
     printf("Enter Municipality Name: ");
     scanf("%49s", municipality); 
     printf("Enter Mayor: "); 
     scanf("%49s", mayor);
     printf("Enter Population: ");
     scanf("%d", &population); printf("\n---------------------------------\n");
     printf("Municipality : %s\n", municipality);
     printf("Mayor        : %s\n", mayor);
     printf("Population   : %d\n", population);
     printf("Gender       : %d \n", gender);

     printf("Press 1 if you want to calculate the budget");
     scanf("%d", &budget_choice);
     if (budget_choice == 1) {
            Call_budget();
      }
      return 0;
    }
