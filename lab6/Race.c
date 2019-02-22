#include <stdio.h>
#include <time.h>
#include <windows.h>

#define RAND_MIN 1
#define RAND_MAXX 10

void moveTort(int *pos);
void moveHare(int *pos);
void printTort(int *pos);
void printAnimals(int *tortPos, int *harePos);

int main(void)
{
	srand((unsigned)time(NULL));
	puts("ON YOUR MARK, GET SET");
	printf("%s %20s\n", "BANG", "!!!");
	
	int tortPos = 1;
	int harePos = 1;
	
	int *tortPtr = &tortPos;
	int *harePtr = &harePos;
	
	while (tortPos <= 70)
	{
		//printTort(tortPtr);
		printAnimals(tortPtr, harePtr);
		moveTort(tortPtr);
		moveHare(harePtr);
	}
	
	
	return 0;
}

void moveTort(int *pos)
{
	unsigned int moveAmount = rand() % (RAND_MAXX + 1) + RAND_MIN;
	
	
	if (moveAmount >= 1 && moveAmount <= 5)
	{
		// fast plod move with 50% sleep time
		*pos += 3;
		//sleep(500);
		Sleep(500);
	} else if (moveAmount >= 6 && moveAmount <= 7)
	{
		// slip with 20% sleep time
		if (*pos - 6 < 1)
			*pos = 0;
		else
			*pos -= 6;
		//sleep(200);
		Sleep(200);
	} else
	{
		// slow pod with 30% sleep time
		*pos += 1;
		//sleep(300);
		Sleep(300);
	}
	
}

void moveHare(int *pos)
{
	unsigned int moveAmount = rand() % (RAND_MAX + 1) + RAND_MIN;
	
	switch (moveAmount)
	{
		case 1:
		case 2:
			// don't move
			Sleep(200);
			break;
		case 3:
		case 4:
			// small slip
			if (*pos - 2 < 1)
				*pos = 0;
			else
				*pos -= 2;
			//sleep(200)
			Sleep(200);
			break;
		case 5:
		case 6:
			// small hop
			*pos += 1;
			//sleep(300)
			Sleep(300);
			break;
		case 7:
		case 8:
			// big slip
			if (*pos - 12 < 1)
				*pos = 0;
			else
				*pos -= 12;
			//sleep(100)
			Sleep(100);
			break;
		case 9:
		case 10:
			// big hop
			*pos += 9;
			Sleep(200);
			break;
	}
}

void printAnimals(int *tortPos, int *harePos)
{
	if (*tortPos < *harePos)
	{
		
		
	} else
	{
		// print H first
		for (int i = 0; i < 70; ++i)
		{
			if (i == *tortPos)
				printf("T ");
			else if (i == *harePos)
				printf("H ");
			
			printf(" ");
		}
	}
	for (int i = 0; i < 70; ++i)
	{
		if (i == *tortPos)
			printf("T ");
		else if (i == *harePos)
			printf("H ");
		
		printf(" ");
	}
	printf("\n");
}

void printTort(int *pos)
{
	for (int i = 0; i < *pos - 1; ++i)
	{
		printf(" ");
	}
	printf("T\n");
}