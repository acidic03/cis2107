#include <stdio.h>

void printMenu(void);
void printArray(size_t row, size_t col, int arr[row][col]);
void minimum(size_t row, size_t col, int arr[row][col]);
void maximum(size_t row, size_t col, int arr[row][col]);
void average(size_t row, size_t col, int arr[row][col]);


int main(void)
{
    // int processGrades[]
    int rows, cols;

    printMenu();

    printf("\n\tHow many rows? ");
    scanf("%d", &rows);

    printf("\tHow many columns? ");
    scanf("%d", &cols);

    int processGrades[rows][cols];
    puts("");

    // Fill array with user inputs
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("\tenter [%d][%d]: ", i, j);
            // enter input into array
            scanf("%d", &processGrades[i][j]);
        }
    }

    puts("");
    printArray(rows, cols, processGrades);

    return 0;
}

void printMenu()
{
    puts("\nEnter a choice:");

    puts("\t0  Print the array of grades");
    puts("\t1  Find the minimum grade");
    puts("\t2  Find the maximum grade");
    puts("\t3  Print the average on all tests for each student");
    puts("\t4  End Program");
}

void printArray(size_t row, size_t col, int arr[row][col])
{
    for (int i = 0; i < row; ++i) {
        printf("[");
        for (int j = 0; j < col; ++j) {
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
}

void minimum(size_t row, size_t col, int arr[row][col])
{
    int minSoFar = arr[0][0];

    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (arr[i][j] < minSoFar)
                minSoFar = arr[i][j];
        }
    }

    printf("Minimum is %d\n", minSoFar);
}

void maximum(size_t row, size_t col, int arr[row][col])
{
    int maxSoFar = arr[0][0];

    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            if (arr[i][j] > maxSoFar)
                maxSoFar = arr[i][j];
        }
    }

    printf("Maximum is %d\n", maxSoFar);
}

void average(size_t row, size_t col, int arr[row][col])
{
    unsigned int count = 0, sum = 0;

    for (int i = 1; i < row; ++i) {
        for (int j = 1; j < col; ++j) {
            sum += arr[i][j];
            ++count;
        }
    }

    printf("The average is %d\n", (sum/count));
}