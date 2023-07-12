#include <string.h>
#include <stdio.h>

int	numeral_to_int(char numeral);
int	get_next_value(const char *roman_number, int i);

unsigned decode_roman(const char *roman_number)
{
	unsigned	converted_value;
	int			length;
	int			current_value;
	int 		next_value;

	length = (int)strlen(roman_number);
	converted_value = 0;
	for (int i = 0; i < length; i++)
	{
		current_value = numeral_to_int(roman_number[i]);
		next_value = get_next_value(roman_number, i);
		if (!next_value || next_value <= current_value)
			converted_value += current_value;
		else
		{
			converted_value += (next_value - current_value);
			i++;
		}
	}
	return (converted_value);
}

int	get_next_value(const char *roman_number, int i)
{
	if (i < strlen(roman_number))
		return (numeral_to_int(roman_number[i + 1]));
	return (0);
}

int	numeral_to_int(char numeral)
{
	if (numeral == 'I')
		return (1);
	if (numeral == 'V')
		return (5);
	if (numeral == 'X')
		return (10);
	if (numeral == 'L')
		return (50);
	if (numeral == 'C')
		return (100);
	if (numeral == 'D')
		return (500);
	if (numeral == 'M')
		return (1000);
	return (0);
}
//
//int	main(int n, char **argument)
//{
//	unsigned	result;
//
//	if (n < 2)
//		return (0);
//	for (int i = 1; argument[i]; i++)
//	{
//		result = decode_roman(argument[i]);
//		printf("%s as an int is: %u\n", argument[i], result);
//	}
//	return (0);
//}
