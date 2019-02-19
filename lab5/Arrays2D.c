
#include <stdio.h>

int max(int r, int c, int arr[r][c]);
int rowSum(int rowToSum, int r, int c, int arr[r][c]);
int columnSum(int columnToSum, int r, int c, int arr[r][c]);
int isSquare(int r, int c);
void displayOutputs(int r, int c, int arr[r][c]);

int main(void)
{
  int rows, cols;
  puts("Let's create a 2Dim array!");

  printf("\n\tHow many rows? ");
  scanf("%d", &rows);

  printf("\tHow many columns? ");
  scanf("%d", &cols);

  puts("");

  int arr[rows][cols];

  // fill the array with user inputs
  for (unsigned int i = 0; i < rows; ++i)
  {
    for (unsigned int j = 0; j < cols; ++j)
    {
      printf("\tenter [%d][%d] : ", i, j);
      scanf("%d", &arr[i][j]);
    }
  }

  puts(""); 

  if (rows >= 2)
  {
    printf("Sum of row 1 = %d\n", rowSum(0, rows, cols, arr));
    printf("Sum of row 2 = %d\n", rowSum(1, rows, cols, arr));
  }
  else
  {
    printf("Sum of row 1 = %d\n", rowSum(0, rows, cols, arr));
  }
  puts("");

  if (cols >= 3)
  {
    printf("Sum of column 1 = %d\n", columnSum(0, rows, cols, arr));
    printf("Sum of column 2 = %d\n", columnSum(1, rows, cols, arr));
    printf("Sum of column 3 = %d\n", columnSum(2, rows, cols, arr));
  }
  else
  {
    printf("Sum of column 1 = %d\n", columnSum(0, rows, cols, arr));
  }

  puts("");

  if(isSquare(rows, cols))
    puts("This is a sqaure array.");
  else
    puts("This is not a sqaure array.");

  puts("");

  puts("Here is your 2Dim array:");
  displayOutputs(rows, cols, arr);

  return 0;
}

// find the max number in the 2D array
int max(int r, int c, int arr[r][c])
{
  int maxSoFar = 0;

  for(size_t i = 0; i < r; ++i)
  {
    for(size_t j = 0; j < c; ++j)
    {
      if (arr[i][j] > maxSoFar)
      {
        maxSoFar = arr[i][j];
      }
    }
    
  }

  return maxSoFar;
}

// find the sum in a row
int rowSum(int rowToSum, int r, int c, int arr[r][c])
{
  if (rowToSum >= r || rowToSum < 0)
  {
    puts("Invalid row.");
    return 0;
  }

  unsigned int sum = 0;

  for (unsigned int i = 0; i < c; ++i)
  {
    sum += arr[rowToSum][i];
  }

  return sum;
}

// find the sum in a column
int columnSum(int columnToSum, int r, int c, int arr[r][c])
{
  if (columnToSum >= c || columnToSum < 0)
  {
    puts("Invalid column.");
    return 0;
  }

  unsigned int sum = 0;

  for (unsigned int i = 0; i < r; ++i)
  {
    sum += arr[i][columnToSum];
  }

  return sum;
}

// check if the array is square
int isSquare(int r, int c)
{
  return r == c ? 1 : 0;
}

// prints out the 2D array
void displayOutputs(int r, int c, int arr[r][c])
{
  for (unsigned int i = 0; i < r; ++i)
  {
    printf("[");
    for (unsigned int j = 0; j < c; ++j)
    {
      if (j == c - 1)
        printf("%d", arr[i][j]);
      else
        printf("%d, ", arr[i][j]);
    }
    printf("]\n");
  }
}