#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Map decimal value to higher-base character value */
char map(int n)
{
	if (n == 0)
		return '0';
	else if (n == 1)
		return '1';
	else if (n == 2)
		return '2';
	else if (n == 3)
		return '3';
	else if (n == 4)
		return '4';
	else if (n == 5)
		return '5';
	else if (n == 6)
		return '6';
	else if (n == 7)
		return '7';
	else if (n == 8)
		return '8';
	else if (n == 9)
		return '9';
	else if (n == 10)
		return 'A';
	else if (n == 11)
		return 'B';
	else if (n == 12)
		return 'C';
	else if (n == 13)
		return 'D';
	else if (n == 14)
		return 'E';
	else if (n == 15)
		return 'F';
}

/* Replace string with its backwards equivalent */
void reverse(char *string, int size)
{
	char temp[size];

	for (int i=size-1; i >= 0; i--)
		temp[size-i-1] = string[i];

	strcpy(string, temp);
}

void convertfromdecimal(int fromvalue, char *tovalue, unsigned short base)
{
	do
	{
		// Store remainder value in temporary string
		char remainder;

		// Append value to remainder
		remainder = map(fromvalue % base);
		// Append remainder value to toValue string
		strcat(tovalue, &remainder);
		fromvalue /= base;
	} while (fromvalue != 0);

	// Reverse string, which stores digits backwards
	reverse(tovalue, strlen(tovalue));
}

/*
 * TODO: Hi! Implement me pls! c:
 */
void converttodecimal(char *fromvalue, char *tovalue, unsigned short base)
{
}

void printhelpdisplay()
{
	printf("Error\n");
}

/* Run a given argv index against a series of flag checks */
int flagcheck(int index, char* argv[])
{
	if (strcmp(argv[index], "-b2") == 0)
		return 2;
	else if (strcmp(argv[index], "-b3") == 0)
		return 3;
	else if (strcmp(argv[index], "-b4") == 0)
		return 4;
	else if (strcmp(argv[index], "-b5") == 0)
		return 5;
	else if (strcmp(argv[index], "-b6") == 0)
		return 6;
	else if (strcmp(argv[index], "-b7") == 0)
		return 7;
	else if (strcmp(argv[index], "-b8") == 0)
		return 8;
	else if (strcmp(argv[index], "-b9") == 0)
		return 9;
	else if (strcmp(argv[index], "-b10") == 0)
		return 10;
	else if (strcmp(argv[index], "-b11") == 0)
		return 11;
	else if (strcmp(argv[index], "-b12") == 0)
		return 12;
	else if (strcmp(argv[index], "-b13") == 0)
		return 13;
	else if (strcmp(argv[index], "-b14") == 0)
		return 14;
	else if (strcmp(argv[index], "-b15") == 0)
		return 15;
	else if (strcmp(argv[index], "-b16") == 0)
		return 16;
	else
	{
		printhelpdisplay();
		exit(-1);
	}
}

/* Check user arguments */
void checkargs(unsigned short *flags, char **fromvalue, int
		argc, char* argv[])
{
	if (argc < 3)
	{
		printhelpdisplay();
		exit(-1);
	}
	else if (argc == 3)
	{
		// If 1st argument is not flag and 2nd argument is
		// flag, default "from" flag to 10
		if (argv[1][0] != '-' && argv[2][0] == '-')
		{
			flags[0] = 10;
			flags[1] = flagcheck(2, argv);
			*fromvalue = argv[1];
		}
		// If 1st argument is flag and 2nd argument is not
		// flag, default "to" flag to 10
		else if (argv[1][0] == '-' && argv[2][0] != '-')
		{
			flags[1] = 10;
			flags[0] = flagcheck(1, argv);
			*fromvalue = argv[2];
		}
		else
		{
			printhelpdisplay();
			exit(-1);
		}
	}
	else if (argc == 4)
	{
		flags[0] = flagcheck(1, argv);
		flags[1] = flagcheck(3, argv);
		*fromvalue = argv[2];
	}
	else
	{
		printhelpdisplay();
		exit(-1);
	}
}

int main(int argc, char* argv[])
{
	// Array to store flag values-- the first index is the
	// base of the number to be converted; the second index
	// is the base of the converted number; the third index
	// is the value of the number to be converted
	unsigned short flags[3];
	// Strings to store values of original and converted
	// numbers
	char *fromvalue;
	char tovalue[18];
	// Check arguments & set flag / number values
	checkargs(flags, &fromvalue, argc, argv);

	// Run program according to flag values set by user
	if (flags[0] == 10)
	{
		convertfromdecimal(atoi(fromvalue), tovalue,
				flags[1]);
		printf("%s\n", tovalue);
	}
	else if (flags[1] == 10)
	{
		converttodecimal(fromvalue, tovalue, flags[0]);
	}
	else
	{
		converttodecimal(fromvalue, tovalue, flags[0]);
		convertfromdecimal(atoi(tovalue), tovalue, flags[1]);
	}

	return 0;
}
