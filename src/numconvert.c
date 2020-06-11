#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Characters which represent numbers */
typedef enum
{
	A = 10,
	B = 11,
	C = 12,
	D = 13,
	E = 14,
	F = 15,
} digit;

/* TODO: Implement parsing for characters A-F, which will
 * correspond with digit values from 10-11.
 */
void convertfromdecimal(int fromvalue, char **tovalue, unsigned short base)
{
	int temp = fromvalue;
	char newvalue[18];

	do
	{
		// Store remainder value in temporary string
		char remainder[2];
		sprintf(remainder, "%d", (temp % base));
		// Append remainder value to newvalue string		
		strcat(newvalue, remainder);
		temp /= base;
	} while (temp != 0);

	printf("%s\n", newvalue);
}

void converttodecimal(char *fromvalue, char **tovalue, unsigned short base)
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

/* TODO: Implement actual program functionality. Can expect
 * difficulties when attempting to parse letters in >b10
 * number systems.
 */
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
	char *tovalue;
	// Check arguments & set flag / number values
	checkargs(flags, &fromvalue, argc, argv);

	// Run program according to flag values set by user
	if (flags[0] == 10)
	{
		convertfromdecimal(atoi(fromvalue), &tovalue,
				flags[1]);
	}
	else if (flags[1] == 10)
	{
		converttodecimal(fromvalue, &tovalue, flags[0]);
	}
	else
	{
		converttodecimal(fromvalue, &tovalue, flags[0]);
		convertfromdecimal(atoi(tovalue), &tovalue, flags[1]);
	}

	return 0;
}
