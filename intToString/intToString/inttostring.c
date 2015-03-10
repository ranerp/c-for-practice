#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "inttostring.h"

const char* NUMBERS_PTR[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
				   "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "nineteen"};

const char* TENS_PTR[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

const char* POWERS_PTR[] = { "", "thousand", "million", "billion" };

const char NEGATIVE[] = "minus";

const char HUNDRED[] = "hundred";

const char FILL[] = " ";

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
	strcpy(answerPtr, "");
	
	printf("Enter an integer to convert it to string\n");
	scanf("%d", &integer);

	if (integer < 0)
	{
		integer *= -1;
		addstr(&answerPtr, NEGATIVE);
		addstr(&answerPtr, FILL);
	}

	double base_ten = (double)floor(log10(integer));
	int i = (int)ceil(base_ten / 3);
	int base = fmax(pow(1000, i), 1000);

	while (base > 1)
	{		
		int hundreth = integer % base;
		int tenth = hundreth % (base / 10);
		int oneth = tenth % (base / 100);

		int thousand = integer / base;
		int hundred = hundreth / (base / 10);
		int ten = tenth / (base / 100);
		int one = oneth / (base / 1000);

		integer -= one * (base / 1000) + ten * (base / 100) + hundred * (base / 10) + thousand * base;

		if (thousand > 0)
		{
			add_number(&answerPtr, thousand);
			addstr(&answerPtr, FILL);

			addstr(&answerPtr, POWERS_PTR[i]);
			addstr(&answerPtr, FILL);
		}

		add_hundred(&answerPtr, hundred);
		addstr(&answerPtr, FILL);

		if (ten == 1)
		{
			add_number(&answerPtr, 10 + one);
			addstr(&answerPtr, FILL);
		}
		else
		{
			add_tens(&answerPtr, ten);
			addstr(&answerPtr, FILL);

			add_number(&answerPtr, one);
			addstr(&answerPtr, FILL);
		}
		
		if (ten != 0  || one != 0 || hundred != 0)
		{

			addstr(&answerPtr, POWERS_PTR[i - 1]);
			addstr(&answerPtr, FILL);
		}

		base /= 1000;
		i--;
	}

	printf("ANSWER: %s\n", answerPtr);

	getch();

	free(answerPtr);
	return 0;
}

void add_hundred(char **destination, int integer)
{
	int ptr = fmin(integer, 9);
	if (integer > 0)
	{
		addstr(destination, NUMBERS_PTR[ptr]);
		addstr(destination, FILL);
		addstr(destination, HUNDRED);
	}
}

void add_tens(char **destination, int integer)
{
	int ptr = fmin(integer, 18);
	addstr(destination, TENS_PTR[ptr]);
}

void add_number(char **destination, int integer)
{
	int ptr = fmin(integer, 18);
	addstr(destination, NUMBERS_PTR[ptr]);
}

void addstr(char **destination, char *source)
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
		printf("Could not reallocate memory to concatenate string");
	}
}

