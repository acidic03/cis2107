// Matthew Cohen
//
//
//
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_MIN 0
#define RAND_MAXS 100
#define DEFAULT_SIZE 40


void fillArray(int arr[], int size);
void findWithRange(int arr[], int low, int high, int size);
void reverseArray(int arr[], int size);
void reverseArrayInRange(int arr[], int low, int high, int size);
void printArray(int arr[], int size);
void findSequence(int arr[], int size);

int main(void) {
	// Setup rand
	srand((unsigned)time(NULL));
	
	int arr[DEFAULT_SIZE];
	
	fillArray(arr, DEFAULT_SIZE);

	puts("\nOrginal Array");
	printArray(arr, DEFAULT_SIZE);

	puts("\nFind max number from index 10 to 19");
	findWithRange(arr, 10, 19, DEFAULT_SIZE);

	puts("\nReverse array");
	reverseArray(arr, DEFAULT_SIZE);
	printArray(arr, DEFAULT_SIZE);

	puts("\nReverse in range from index 0 to 5");
	reverseArrayInRange(arr, 0, 5, DEFAULT_SIZE);
	printArray(arr, DEFAULT_SIZE);
	
	puts("\nFind sequence");
	findSequence(arr, DEFAULT_SIZE);
	  
	return 0;
}


void fillArray(int arr[], int size) {

	for(unsigned int i = 0; i < size; ++i) {
		arr[i] = rand() % (RAND_MAXS + 1) + RAND_MIN;
	}
}

void findWithRange(int arr[], int low, int high, int size) {
  if(high > size || low < 0) {
    puts("Out of range");
    return;
  }

  unsigned int maxSoFar = 0;

  for(unsigned int i = low; i <= high; ++i) {
    if(arr[i] > maxSoFar) 
      maxSoFar = arr[i];
    
  }

  printf("Max = %d\n", maxSoFar);
}


void reverseArray(int arr[], int size) {
	unsigned int temp;
	// Swaps the first with the last and move inward
	for(unsigned int i = 0; i < size / 2; ++i) {
		temp = arr[i];
		arr[i] = arr[size-1-i];
		arr[size-1-i] = temp;
	}
}

void reverseArrayInRange(int arr[], int low, int high, int size) {
	if(low < 0 || high > size || high < low) {
		puts("In valid range");
		return;
	}
	
	unsigned int temp;
	// Swaps the values in the range and move inward
	for(unsigned int i = low; i <= high; ++i) {
		temp = arr[i];
		arr[i] = arr[high];
		arr[high--] = temp;
		
	}
	
}

void printArray(int arr[], int size) {
	
	for(unsigned int i = 0; i < size; ++i) {
		// Limit to 10 values per row
		if(i % 10 == 0 && i != 0)
			puts("");
		
		printf("%4d ", arr[i]);
	}

	puts("");
}

void findSequence(int arr[], int size) {
	int num1, num2;
	int foundFirstMatch = 0;
	
	printf("Enter two numbers: ");
	scanf("%d %d", &num1, &num2);
	
	for(unsigned int i = 0; i < size; ++i) {
		if(foundFirstMatch) {
			// Now looking for second number
			if(arr[i] == num2) {
				// Found the second number 
				// exit loop
				printf("sequence found at index %d\n", (i-1));
				return;
			} else {
				// Next number wasn't a match so reset to look for num1 again
				foundFirstMatch = 0;
			}
		} else {
			// Found first number, start looking for the second one now
			if(arr[i] == num1)
				foundFirstMatch = 1;

		}
	}

	puts("sequence not found");
}