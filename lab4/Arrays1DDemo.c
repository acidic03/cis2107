//	Matthew Cohen
//	2-10-2019
//	Lab 4 - Processing 1D Arrays
//	
//	The purpose of the lab is to become fimilar with
//	1D arrays in C by creating and manipulating its data.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_MIN 0
#define RAND_MAXS 100
#define DEFAULT_ARRAY_SIZE 40


void fillArray(int arr[], int size);
void findWithRange(int arr[], int low, int high, int size);
void reverseArray(int arr[], int size);
void reverseArrayInRange(int arr[], int low, int high, int size);
void printArray(int arr[], int size);
void findSequence(int arr[], int size);
int validRange(int low, int high, int maxSize);

int main(void) {
	// Setup rand
	srand((unsigned)time(NULL));
	
	int arr[DEFAULT_ARRAY_SIZE];
	
	fillArray(arr, DEFAULT_ARRAY_SIZE);

	puts("\nOrginal:");
	printArray(arr, DEFAULT_ARRAY_SIZE);

	findWithRange(arr, 2, 2, DEFAULT_ARRAY_SIZE);

	puts("\nReversed:");
	reverseArray(arr, DEFAULT_ARRAY_SIZE);
	printArray(arr, DEFAULT_ARRAY_SIZE);

	
	reverseArrayInRange(arr, 8, 8, DEFAULT_ARRAY_SIZE);
	printArray(arr, DEFAULT_ARRAY_SIZE);
	
	puts("\nFind sequence");
	findSequence(arr, DEFAULT_ARRAY_SIZE);
	  
	return 0;
}


void fillArray(int arr[], int size) {

	for(unsigned int i = 0; i < size; ++i) {
		arr[i] = rand() % (RAND_MAXS + 1) + RAND_MIN;
	}
}

void findWithRange(int arr[], int low, int high, int size) {
	// Make sure ranges make sense
	if(!validRange(low, high, size)) {
		puts("Invalid range");
    return;
	}

	printf("\nFinding max between %d and %d:\n", low, high);
  unsigned int maxSoFar = 0;

  for(unsigned int i = low; i <= high; ++i) {
    if(arr[i] > maxSoFar) 
      maxSoFar = arr[i];
  }

  printf("\n\tMax = %d\n", maxSoFar);
}

void reverseArray(int arr[], int size) {
	// Holds temp value to swap
	unsigned int temp;
	// Swaps the first with the last and move inward
	for(unsigned int i = 0; i < size / 2; ++i) {
		temp = arr[i];
		arr[i] = arr[size-1-i];
		arr[size-1-i] = temp;
	}
}

void reverseArrayInRange(int arr[], int low, int high, int size) {
	// Make sure ranges make sense
	if(!validRange(low, high, size)) {
		puts("Invalid range");
    return;
	}
	printf("\nReversing between %d and %d\n", low, high);
	// Holds temp value to swap
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
		
		printf("\t%4d ", arr[i]);
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

int validRange(int low, int high, int maxSize) {
	if(low < 0 || high < low || high < 0 || high > maxSize)
		return 0;
	
	return 1;
}