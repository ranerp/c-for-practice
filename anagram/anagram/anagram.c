#include <stdio.h>

void gen_anagram(char *input, int start, int last);
void swap(char *one, char *two);

int main(void)
{
	char input[] = "ABCD";

	gen_anagram(input, 0, 3);

	getch();
	return 0;
}

/*
*  Recursive function
*  Work principle:
*     input: ABCD
*   A ->
*       B ->
*           C ->
*              D -> ABCD
*           D ->
*              C -> ABDC
*       C ->
*           B ->
*              D -> ACBD
*           D ->
*              B -> ACDB
*   
*/
void gen_anagram(char *input, int start, int last)
{
	if (start == last)
		printf("%s\n", input);
	else
	{
		for (int i = start; i <= last; i++)
		{
			swap((input + start), (input + i));
			gen_anagram(input, start + 1, last);
			swap((input + start), (input + i));
		}
	}
}

void swap(char *one, char *two)
{
	char temp = *one;
	*one = *two;
	*two = temp;
}