#include <stdio.h>
 int main() { 
 char StudentName[50]; 
 int StudentID;
 float marks;
 char grade;
 printf("Enter student name: ");
 scanf("%49s", StudentName);
 printf("Enter student ID: ");
 scanf("%d", &StudentID);
 printf("Enter marks: ");
 scanf("%f", &marks);
 if (marks >= 80) {
    grade = 'A';
    }
    else if (marks >= 70) {
    grade = 'B';
    }
    else if (marks >= 60) {
    grade = 'C';
    }
    else if (marks >= 50) {
    grade = 'D';
    }
    else if (marks >= 40) {
    grade = 'E';
    }
    else {
    grade = 'F';
    }
    return 0;
}