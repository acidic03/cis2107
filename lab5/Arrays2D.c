
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

  printf("\tHow many rows? ");
  scanf("%d", &rows);

  printf("\n\tHow many columns? ");
  scanf("%d", &cols);

  puts("");

  int arr[rows][cols];

  // fill the array with user inputs
  for (unsigned int i = 0; i < rows; ++i)
  {
    for (unsigned int j = 0; j < cols; ++j)
    {
      printf("\n\tenter [%d][%d] : ", i, j);
      scanf("%d", &arr[i][j]);
    }
  }

  puts(""); 

  printf("Sum of row 1 = %d\n", rowSum(0, rows, cols, arr));
  printf("Sum of row 2 = %d\n", rowSum(1, rows, cols, arr));

  puts("");

  printf("Sum of column 1 = %d\n", columnSum(0, rows, cols, arr));
  printf("Sum of column 2 = %d\n", columnSum(1, rows, cols, arr));

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


int rowSum(int rowToSum, int r, int c, int arr[r][c])
{
  if (rowToSum >= r)
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

int columnSum(int columnToSum, int r, int c, int arr[r][c])
{
  if (columnToSum >= c)
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

int isSquare(int r, int c)
{
  return r == c ? 1 : 0;
}

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