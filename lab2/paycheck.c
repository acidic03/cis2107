#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int employeeNumber;
    float hourlySalary;
    float weeklyTime;
    float overtimeHours = 0.0f;
    float regularPay;
    float overtimePay;
    float netPay;

    // Print the welcome message to the screen
    puts("Welcome to \"TEMPLE HUMAN RESOURCES\"");
    
    // Get input
    printf("\n\t%s","Enter Employee Number: ");
    scanf("%d", &employeeNumber);

    // Check input
    if(employeeNumber <= 0) {
        puts("\n\tThis is not a valid Employee Number.\n\tPlease run the program again");
        puts("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(0);
    }

    printf("\t%s","Enter Hourly Salary: ");
    scanf("%f", &hourlySalary);
    // Check input
    if(hourlySalary <= 0) {
        puts("\n\tThis is not a valid hourly salary amount.\n\tPlease run the program again");
        puts("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(0);
    }

    printf("\t%s","Enter Weekly Time: ");
    scanf("%f", &weeklyTime);
    // Check input
    if(weeklyTime <= 0) {
        puts("\n\tThis is not a weekly time.\n\tPlease run the programe again");
        puts("\nThank you for using \"TEMPLE HUMAN RESOURCES\"");
        exit(0);
    }

    puts("\t================================");

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

    printf("\t%s: %d\n", "Employee #", employeeNumber);
    printf("\t%s: $%1.1f\n", "Hourly Salary", hourlySalary);
    printf("\t%s: $%1.1f\n", "Weekly Time", weeklyTime);
    printf("\t%s: $%1.1f\n", "Regular Pay", regularPay);
    printf("\t%s: $%1.1f\n", "Overtime Pay", overtimePay);
    printf("\t%s: $%1.1f\n", "Net Pay", netPay);


    puts("\t================================");


    puts("Thank you for using \"TEMPLE HUMAN RESOURCES\"");
    
    return 0;
}
