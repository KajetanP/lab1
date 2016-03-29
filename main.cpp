#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);
void drawCharSquare(char **square, int n);

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	srand(atoi(argv[2]));
	drawCharSquare(charSquare(n), n);	
}

char **charSquare(int n)
{
	// CREATION
	char **square = new char*[n];
	for(int i = 0 ; i < n ; i++)
	{
		square[i] = new char[n];
	}

	// FILLING
	for(int i = 0 ; i < n * n ; i++)
	{
		*((char*)square + i) = rand() % 26 + 97;
	}

	return square;
}

void drawCharSquare(char **square, int n)
{
	// DRAWING
	for(int i = 0 ; i < n * n ; i++)
	{
		((i + 1) % n) ? printf("%c", *((char*)square + i)) : printf("%c \n", *((char*)square + i));
	}

	// DESTRUCTION
	for(int i = 0 ; i < n ; i++)
	{
		delete [] square[i];
	}
	delete [] square;
}