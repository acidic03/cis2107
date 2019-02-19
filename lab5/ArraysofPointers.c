#include <stdio.h>

void printMenu(void);
void printArray(size_t row, size_t col, int arr[row][col]);
void minimum(size_t row, size_t col, int arr[row][col]);
void maximum(size_t row, size_t col, int arr[row][col]);
void average(size_t row, size_t col, int arr[row][col]);


int main(void)
{
    puts("Arrays of Pointers");

    // array of 4 pointers
    void (*processGrades[4])(size_t row, size_t col, int arr[row][col]) = {printArray, minimum, maximum, average};
    // number of rows and cols the user enters
    int rows, cols;

    printf("\n\tHow many rows? ");
    scanf("%d", &rows);

    printf("\tHow many columns? ");
    scanf("%d", &cols);

    // the main array
    int studentGrades[rows][cols];
    puts("");

    // fill array with user inputs
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("\tenter [%d][%d]: ", i, j);
            // enter input into array
            scanf("%d", &studentGrades[i][j]);
        }
    }

    puts("");
    
    int choice;
    while (1)
    {
        printMenu();
        printf("Enter a choice: ");
        scanf("%d", &choice);

        if (choice == 4)
        {
            break;
        }

        (*processGrades[choice])(rows, cols, studentGrades);
    }
    

    //(*functs[2])(rows, cols, processGrades);

    

    return 0;
}

void printMenu()
{
    //puts("\nEnter a choice:");

    puts("\t0  Print the array of grades");
    puts("\t1  Find the minimum grade");
    puts("\t2  Find the maximum grade");
    puts("\t3  Print the average on all tests for each student");
    puts("\t4  End Program");
    puts("");
}

void printArray(size_t row, size_t col, int arr[row][col])
{
    puts("");
    for (size_t i = 0; i < row; ++i) {
        printf("[");
        for (size_t j = 0; j < col; ++j) {
            // Last number in row
            if (j == col - 1)
            {
                printf("%d", arr[i][j]);
                continue;
            }
            printf("%d, ", arr[i][j]);
        }
        puts("]");
    }
    puts("");
}

void minimum(size_t row, size_t col, int arr[row][col])
{
    int minSoFar = arr[0][0];

    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            if (arr[i][j] < minSoFar)
            {
                minSoFar = arr[i][j];
            }
        }
    }

    printf("\n\tThe minimum is %d\n", minSoFar);
    puts("");
}

void maximum(size_t row, size_t col, int arr[row][col])
{
    int maxSoFar = arr[0][0];

    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            if (arr[i][j] > maxSoFar)
            {
                maxSoFar = arr[i][j];
            }
        }
    }

    printf("\n\tThe maximum is %d\n", maxSoFar);
    puts("");
}

void average(size_t row, size_t col, int arr[row][col])
{
    float sum = 0.0f;

    puts("\nAverages:");
    for (size_t i = 0; i < row; ++i) {
        printf("\tstudent %d: ", i+1);

        for (size_t j = 0; j < col; ++j) {
            sum += arr[i][j];
        }
        printf("%.2f\n", sum / (float)(col));
        sum = 0.0f;
    }
    puts("");
}