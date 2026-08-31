#include <stdio.h> 
int main() { 
    char municipality[50]; 
    char mayor[50]; 
    int population;
    int gender;
    int Call_budget;
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

     printf("Press 1 if you want to calculate the budget?/n");
     scanf("%d", &Call_budget);
     if (Call_budget == 1) {
    budget ();
     }
     return 0;
}
    
     