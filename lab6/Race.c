//  Matthew Cohen
//  02-24-2019
//  CIS 2107
//  Lab 6 - Race
//
//  The purpose of this program is to gain practice with using functions 
//  with pointers.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RAND_MIN 1
#define RAND_MAXX 10

void moveTort(int *pos);
void moveHare(int *pos);
void printTort(int *pos);
void printAnimals(int *tortPos, int *harePos);
int checkForWin(int *tortPos, int *harePos);

int main(void)
{
	srand((unsigned)time(NULL));
	puts("ON YOUR MARK, GET SET");
	printf("%s %20s\n", "BANG", "!!!");
	
	int tortPos = 1;
	int harePos = 1;
	int isRunning = 1;
	
	int *tortPtr = &tortPos;
	int *harePtr = &harePos;

	while (isRunning)
	{
		moveTort(tortPtr);
		moveHare(harePtr);
		
		if (tortPos >= 70 && harePos >= 70)
		{
			puts("TIE!!");
			isRunning = 0;
		}
		else if (tortPos >= 70)
		{
			puts("TORTOISE WINS!!! YAY!!!");
			isRunning = 0;
		}
		else if (harePos > 70)
		{
			puts("Yuch");
			isRunning = 0;
		}
		if (isRunning)
			printAnimals(tortPtr, harePtr);\
	}
	
	
	return 0;
}

void moveTort(int *pos)
{
	// rand() % (RAND_MAXS + 1) + RAND_MIN
	int moveAmount = (rand() % RAND_MAXX) + RAND_MIN;
	//printf("tort move: %d \n", moveAmount);
	
	if (moveAmount >= 1 && moveAmount <= 5)
	{
		// fast plod move with 50% sleep time
		if (*pos + 3 > 70)
			*pos = 70;
		else
			*pos += 3;
		usleep(500 * 1000);
	} else if (moveAmount >= 6 && moveAmount <= 7)
	{
		// slip with 20% sleep time
		if (*pos - 6 < 1)
			*pos = 1;
		else
			*pos -= 6;
		usleep(200 * 1000);
	} else
	{
		// slow pod with 30% sleep time
		if (*pos + 1 > 70)
			*pos = 70;
		else
			*pos += 1;
		usleep(300 * 1000);
	}
	
}

void moveHare(int *pos)
{
	int moveAmount = rand() % RAND_MAXX + RAND_MIN;
	
	switch (moveAmount)
	{
		case 1:
		case 2:
			// don't move
			usleep(200 * 1000);
			break;
		case 3:
		case 4:
			// big hop
			if (*pos + 9 > 70)
				*pos = 70;
			else
				*pos += 9;
			usleep(200 * 1000);
			break;
		case 5:
		case 6:
			// big slip
			if (*pos - 12 < 1)
				*pos = 1;
			else
				*pos -= 12;
			usleep(100 * 1000);
			break;
		case 7:
		case 8:
			// small hop
			if (*pos + 1 > 70)
				*pos = 70;
			else
				*pos += 1;

			usleep(300 * 1000);
			break;
		case 9:
		case 10:
			// small slip
			if (*pos - 2 < 1)
				*pos = 1;
			else
				*pos -= 2;
			usleep(200 * 1000);
			break;
		default:
			printf("unknown number: %d ", moveAmount);
	}
}

void printAnimals(int *tortPos, int *harePos)
{
	for (int i = 1; i <= 70; ++i)
	{
		//printf("i: %d ", i);
		if (i == *tortPos && i == *harePos)
		{
			printf("OUCH ");
			break;
		}
		if (i == *tortPos)
			printf("T ");
		if (i == *harePos)
			printf("H ");
		
		printf(" ");
	}
	printf("\n");
}