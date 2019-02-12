#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // Print the welcome message to the screen
    puts("Welcome to \"TEMPLE HUMAN RESOURCES\"");

    int employeeNumber;
    float hourlySalary;
    float weeklyTime;
    float overtimeHours = 0.0f;
    float regularPay;
    float overtimePay;
    float netPay;

    
    // Get input
    printf("%s","\nEnter Employee Number: ");
    scanf("%d", &employeeNumber);

    // Check input
    if(employeeNumber <= 0) {
        puts("\nThis is not a valid Employee Number.\nPlease run the program again");
        exit(0);
    }

    printf("%s","Enter Hourly Salary: ");
    scanf("%f", &hourlySalary);
    // Check input
    if(hourlySalary <= 0) {
        puts("\nThis is not a valid hourly salary amount.\nPlease run the program again");
        exit(0);
    }

    printf("%s","Enter Weekly Time: ");
    scanf("%f", &weeklyTime);
    // Check input
    if(weeklyTime <= 0) {
        puts("\nThis is not a weekly time.\nPlease run the programe again");
        exit(0);
    }

    puts("================================");

    // Check for overtime
    if(weeklyTime > 40)
        overtimeHours = weeklyTime - 40;
    
    // Find regular pay
    if(overtimeHours > 0)
        regularPay = (weeklyTime - overtimeHours) * hourlySalary;
    else
        regularPay = weeklyTime * hourlySalary;

    // Find overtime pay
    if(overtimeHours > 0){
        overtimePay = (overtimeHours * hourlySalary) * 1.5f;
    }

    // Get the net pay
    netPay = regularPay + overtimePay;

    printf("Employee #: %d\n", employeeNumber);
    printf("Hourly Salary: $%1.1f\n", hourlySalary);
    printf("Weekly Time: $%1.1f\n", weeklyTime);
    printf("Regular Pay: $%1.1f\n", regularPay);
    printf("Overtime Pay: $%1.1f\n", overtimePay);
    printf("Net Pay: $%1.1f\n", netPay);

    puts("================================");


    puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"");
    
    return 0;
}