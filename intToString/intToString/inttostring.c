#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "inttostring.h"

const char* numbersPtr[] = { "", "one", "two", "three", "four", "five", "six", "seven", "height", "nine", "ten",
				   "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "nineteen"};

const char* tensPtr[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

const char* powersPtr[] = { "", "thousand", "million", "billion" };

const char negative[] = "minus";

const char hundred[] = "hundred";

char fill[] = " ";

int main()
{
	int integer;
	char *answerPtr;

	answerPtr = malloc(2 * sizeof(char));
	if (answerPtr == NULL)
	{
		printf("Error allocating memory\n");
		return 1;
	}

	strcpy(answerPtr, "z");
	
	printf("Enter an integer to convert it to string\n");
	scanf("%d", &integer);

	printf("%s", answerPtr);

	getch();

	free(answerPtr);
	return 0;
}

int addstr(char **destination, char *source)
{
	size_t len = strlen(*destination) + strlen(source) + sizeof(char);

	char *temp = realloc(*destination, len);
	if (temp != NULL)
	{
		*destination = temp;		
		strcat(*destination, source);
	}
	else
	{
		printf("Could not reallocate memory to add string");
	}
}

