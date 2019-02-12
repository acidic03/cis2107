//  Matthew Cohen
//  02-03-2019
//  CIS 2107
//  Lab 3 - ATM
//
//  The purpose of this program is to gain practice with functions 
//  through the implementation of an ATM machine.

#include <stdlib.h>
#include <stdio.h>

#define PIN 3014
#define BALANCE 5000

// Global vars
int withdrawAmountRemaining = 1000;
int depositAmountRemaining = 10000;
float currentBalance = BALANCE;
unsigned int numOfTransactions;

// Prototypes
int auth(int pin);
void printMenu(void);
void preformOperation(int operation);
void getBalance(void);
void withdraw(int amount);
void deposit(int amount);
void printReceipt(int answer);


int main(void) {
    unsigned int operation;
    unsigned int pin;
    unsigned int currentAuthTries = 0;
    unsigned int authenticated = 0;
    
    
    // Welcome message
    puts("\n\t\t\tWelcome to \"Temple\" ATM\n");
    
    // enter pin
    // Sets a limit of 3 tries before program ends
    while(!authenticated && ++currentAuthTries <= 3) {
        printf("\t%s", "Enter your pin: ");
        scanf("%d", &pin);
        
        authenticated = auth(pin);
        if(authenticated) {
            puts("\n\tChecking Account # 2187421");
            puts("\tWelcome Nana.");
        } else {
            puts("\tInvalid pin.");
            if(currentAuthTries == 3) {
                puts("\n\tToo many tires.");
                exit(0);
            }
        }
    }
    
    // choose operation
    printMenu();
    
    while(1) {
        printf("\n\n\t%s", "What can I do for you today (integers only)? ");
        scanf("%d", &operation);
        
        // perform operation
        preformOperation(operation);
    }

    return 0;
}

// Is used to authenticate the user
int auth(int pin) {
    // Check if pin was correct
    if(pin == PIN)
        return 1;
    // Wrong pin
    return 0;
}

void printMenu() {
    puts("\n\tAvailable commands are:");
    printf("\n\t%d %s\n", 1, "Balance");
    printf("\t%d %s\n", 2, "Withdraw");
    printf("\t%d %s\n", 3, "Deposit");
    printf("\t%d %s\n", 4, "Help");
    printf("\t%d %s\n", 5, "Exit");
}

void preformOperation(int operation) {
    float amount;
    switch(operation) {
            case 1:
                // Balance info
                getBalance();
                break;
            case 2:
                // Withdraw
                // Three are three attempts allowed

                for (unsigned int i = 0; i < 3; ++i) {
                    printf("\tHow much would you like to withdraw? ");
                    scanf("%f", &amount);
                    
                    if(amount > 0 && amount == (int)amount) {
                        withdraw(amount);
                        break;
                    }
                    // Check if user is trying to withdraw an amount with coins
                    if(amount <= 0 || amount != (int)amount) {
                        puts("\tInvalid amount.");
                    } 
                    // A max of three attempts allowed
                    if(i == 2) {
                        puts("\tToo many attempts");
                        preformOperation(5);
                    }
                }
                break;
            case 3:
                // Deposit
                // There are three attempts allowed
                for (unsigned int i = 0; i < 3; ++i) {
                    printf("\tHow much would you like to deposit? ");
                    scanf("%f", &amount);
                    
                    if(amount <= 0 || amount != (int)amount) {
                        puts("\tInvalid amount.");
                    }
                    
                    if(amount > 0 && amount == (int)amount) {
                        deposit((int)amount);
                        break;
                    }

                    // A max of three attempts allowed
                    if(i == 2) {
                        puts("\tToo many attempts");
                        preformOperation(5);
                    }
                }
                
                break;
            case 4:
                // Help menu
                printMenu();
                break;
            case 5:
                // Exit
                printf("\n\tYour total number of transactions are: %d", numOfTransactions);
                puts("\n\tThank you for using \"Temple\" ATM!");
                exit(0);
            default:
                puts("\tI'm sorry. I can not currently preform that.");
                printMenu();
        }
}

void getBalance(void) {
    printf("\tYour current balance is: $%.2f", currentBalance);
    ++numOfTransactions;
    
    // Ask for recepit
    unsigned int receiveReceipt;
    printf("\n\tWould you like a receipt? (1 for yes, 0 for no) ");
    scanf("%d", &receiveReceipt);
    printReceipt(receiveReceipt);
}

void withdraw(int amount) {
    if(amount <= 0) {
        printf("\n\tInvalid amount $%d", amount);
        return;
    }

    if(amount > currentBalance) {
        puts("\tInsufficient funds.");
        return;
    }
    
    if(amount%20 != 0) {
        puts("\tAmount must be in multiples of $20.");
        return;
    }
    
    // Valid amount
    // Check if daily limit was reached, if not allow withdraw amount
    if(withdrawAmountRemaining - amount < 0) {
        puts("\tDaily withdraw limit reached.");
        
    } else {
        currentBalance -= amount;
        withdrawAmountRemaining -= amount;
        printf("\n\t$%d has been withdrawn from your account.", amount);
        printf("\n\tYour current balance is: $%.2f", currentBalance);
        
        // Give recepit to the user by default
        printReceipt(1);
        ++numOfTransactions;
    }
}

void deposit(int amount) {
    if(amount <= 0) {
        printf("\n\tInvalid amount $%d", amount);
        return;
    }

    // Check if daily limit was reached, if not allow deposit of amount;
    if(depositAmountRemaining - amount < 0) {
        puts("\n\tDaily deposit limit reached.");
    } else {
        currentBalance += amount;
        depositAmountRemaining -= amount;
        ++numOfTransactions;
        printf("\n\tYour current balance is: $%.2f", currentBalance);
        
        // Ask for recepit
        unsigned int receiveReceipt;
        printf("\n\tWould you like a receipt? (1 for yes, 0 for no) ");
        scanf("%d", &receiveReceipt);
        printReceipt(receiveReceipt);
    }
}

void printReceipt(int answer) {
    if(answer)
        puts("\n\tReceipt printing...");
}