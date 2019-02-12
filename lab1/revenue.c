#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int quantity = 0;
    float itemPrice, total, discountRate = 0.0f;
    float discountAmount;

    // Welcome message
    puts("Welcome to \"Temple\" store");

    printf("\n\t%s: ", "Enter item price");
    scanf("%f", &itemPrice);

    // Check input
    if(itemPrice <= 0) {
        puts("This is not a valid item price.");
        puts("Please run the program again");
        exit(0);
    }

    printf("\t%s: ", "Enter quantity");
    scanf("%u", &quantity);

    // Check input
    if(quantity <= 0) {
        puts("This is not a valid item price.");
        puts("Please run the program again");
        exit(0);
    }

    printf("\n\t%s $%1.1f", "The item price is:", itemPrice);
    printf("\n\t%s %u %s", "The order is:", quantity, "item(s)");
    printf("\n\t%s $%1.1f", "The cost is:", (itemPrice * quantity));

    if(quantity >= 50 && quantity <= 99) {
        discountRate = 0.10f;
    } else if(quantity >= 100 && quantity <= 149) {
        discountRate = 0.15f;
    } else if(quantity >= 150) {
        discountRate = 0.25f;
    }

    printf("\n\t%s %1.1f%%", "The discount is:", (discountRate * 100));
    printf("\n\t%s $%1.1f", "The discount amount is:", (itemPrice * quantity) * discountRate);

    total = (itemPrice * quantity) - ((itemPrice * quantity) * discountRate);
    printf("\n\t%s $%1.1f\n\n", "The total is:", (itemPrice * quantity) - ((itemPrice * quantity) * discountRate));

    puts("Thank You for using \"Temple\" store");
}