#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#endif

#define CLR_PINK    "\033[35m"
#define CLR_RESET   "\033[0m"

void displayMenu(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf(CLR_PINK "  --------------------------------------------------\n" CLR_RESET);
    printf(CLR_PINK "  |      MUNICIPAL FINANCIAL MANAGEMENT SYSTEM     |\n" CLR_RESET);
    printf(CLR_PINK "  --------------------------------------------------\n" CLR_RESET);
    printf(CLR_PINK "  | " CLR_RESET "1. Employee Management                       " CLR_PINK "|\n" CLR_RESET);
    printf(CLR_PINK "  | " CLR_RESET "2. Budget Management                         " CLR_PINK "|\n" CLR_RESET);
    printf(CLR_PINK "  | " CLR_RESET "3. Supplier Management                       " CLR_PINK "|\n" CLR_RESET);
    printf(CLR_PINK "  | " CLR_RESET "4. Asset Management                          " CLR_PINK "|\n" CLR_RESET);
    printf(CLR_PINK "  | " CLR_RESET "5. System Reports                            " CLR_PINK "|\n" CLR_RESET);
    printf(CLR_PINK "  | " CLR_RESET "6. Exit                                      " CLR_PINK "|\n" CLR_RESET);
    printf(CLR_PINK "  --------------------------------------------------\n" CLR_RESET);
    printf("\n  Enter choice (1-6): ");
}

int main(void) {
    #ifdef _WIN32
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hOut != INVALID_HANDLE_VALUE) {
            DWORD dwMode = 0;
            if (GetConsoleMode(hOut, &dwMode)) {
                dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
                SetConsoleMode(hOut, dwMode);
            }
        }
    #endif

    char muniName[100] = "";
    char mayorName[100] = "";
    int population = 0;
    double totalRevenue = 0.0;
    double totalExpenses = 0.0;
    int choice = 0;

    printf("Municipal Financial Management System\n\n");
    printf("Enter Municipality Name: ");
    fgets(muniName, sizeof(muniName), stdin);
    muniName[strcspn(muniName, "\n")] = 0; 

    printf("Enter Mayor: ");
    fgets(mayorName, sizeof(mayorName), stdin);
    mayorName[strcspn(mayorName, "\n")] = 0; 

    printf("Enter Population: ");
    if (scanf("%d", &population) != 1) population = 0;
    while (getchar() != '\n'); 

    while (1) {
        displayMenu();
        
        if (scanf("%d", &choice) != 1) {
            printf("\n  Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            printf("\n  Press Enter to try again...");
            getchar();
            continue;
        }
        while (getchar() != '\n'); 

        switch(choice) {
            case 1:
                printf("\n" CLR_PINK "  [EMPLOYEE MANAGEMENT]" CLR_RESET "\n");
                printf("  ------------------------------------\n");
                printf("  Muni: %s | Mayor: %s | Pop: %d\n", muniName, mayorName, population);
                break;

            case 2:
                printf("\n" CLR_PINK "  [BUDGET MANAGEMENT]" CLR_RESET "\n");
                printf("  ------------------------------------\n");
                printf("  Enter total revenue (N$): ");
                if (scanf("%lf", &totalRevenue) != 1) totalRevenue = 0.0;
                
                printf("  Enter total expenses (N$): ");
                if (scanf("%lf", &totalExpenses) != 1) totalExpenses = 0.0;
                while (getchar() != '\n'); 

                printf("\n" CLR_PINK "  -- Budget Summary --" CLR_RESET "\n");
                printf("  Revenue:  N$ %.2f\n", totalRevenue);
                printf("  Expenses: N$ %.2f\n", totalExpenses);
                printf("  Remaining: N$ %.2f\n", totalRevenue - totalExpenses);
                break;

            case 3:
                printf("\n  Routing to [Supplier Management]...\n");
                break;

            case 4:
                printf("\n  Routing to [Asset Management]...\n");
                break;

            case 5:
                printf("\n" CLR_PINK "  [SYSTEM REPORT DASHBOARD]" CLR_RESET "\n");
                printf("  ------------------------------------\n");
                printf("  Municipality: %s\n", muniName);
                printf("  Current Leader: Mayor %s\n", mayorName);
                printf("  Total Citizens: %d\n", population);
                printf("  Financial Status: Current Budget Remaining is N$ %.2f\n", totalRevenue - totalExpenses);
                break;

            case 6:
                printf("\n  Exiting system. Goodbye!\n\n");
                return 0;

            default:
                printf("\n  Choice out of bounds. Pick 1 to 6.\n");
                break;
        }
        
        printf("\n  Press Enter to return to the menu...");
        getchar(); 
    }
    return 0;
}
