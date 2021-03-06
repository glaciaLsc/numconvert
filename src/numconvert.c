/*
 * Copyright (C) 2020  Garrett A Justice 
 * <garrettallenjustice@outlook.com>
 *
 * This program is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program.  If not, see
 * <https://www.gnu.org/licenses/>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Map decimal value to higher-base character representation
 * */
char maptochar(int n)
{
	switch(n)
	{
		case 0 :
			return '0';
		case 1 :
			return '1';
		case 2 :
			return '2';
		case 3 :
			return '3';
		case 4 :
			return '4';
		case 5 :
			return '5';
		case 6 :
			return '6';
		case 7 :
			return '7';
		case 8 :
			return '8';
		case 9 :
			return '9';
		case 10 :
			return 'A';
		case 11 :
			return 'B';
		case 12 :
			return 'C';
		case 13 :
			return 'D';
		case 14 :
			return 'E';
		case 15 :
			return 'F';
	}
}

/* Map character representations to corresponding integer
 * values */
int maptoint(char c)
{
	switch(c)
	{
		case '0' :
			return 0;
		case '1' :
			return 1;
		case '2' :
			return 2;
		case '3' :
			return 3;
		case '4' :
			return 4;
		case '5' :
			return 5;
		case '6' :
			return 6;
		case '7' :
			return 7;
		case '8' :
			return 8;
		case '9' :
			return 9;
		case 'a' :
			return 10;
		case 'A' :
			return 10;
		case 'b' :
			return 11;
		case 'B' :
			return 11;
		case 'c' :
			return 12;
		case 'C' :
			return 12;
		case 'd' :
			return 13;
		case 'D' :
			return 13;
		case 'e' :
			return 14;
		case 'E' :
			return 14;
		case 'f' :
			return 15;
		case 'F' :
			return 15;
	}
}

/* Replace string with its backwards equivalent */
void reverse(char *string, int size)
{
	char temp[size+1];

	for (int i=size-1; i >= 0; i--)
		temp[size-i-1] = string[i];
	temp[size] = '\0';

	strcpy(string, temp);
}

void convertfromdecimal(unsigned long fromvalue, char *tovalue, unsigned short base)
{
	do
	{
		// Store remainder value in temporary char
		char remainder = maptochar(fromvalue % base);
		char tempstr[] = {remainder, '\0'};

		// Append remainder value to toValue string
		strcat(tovalue, tempstr);
		// Update fromValue integer
		fromvalue /= base;
	} while (fromvalue != 0);

	
	// Reverse string, which stores digits backwards
	reverse(tovalue, strlen(tovalue));
}

void converttodecimal(char *fromvalue, char *tovalue, unsigned short base)
{
	unsigned long newvalue = 0;
	
	// Increment newValue with value of digit * base^column
	for (int i=0; i < strlen(fromvalue); i++)
		newvalue += (maptoint(fromvalue[i]) * pow(base,
					strlen(fromvalue)-i-1));

	sprintf(tovalue, "%ld", newvalue);
}

unsigned long returndecimal(char *fromvalue, unsigned short base)
{
	unsigned long newvalue = 0;

	// Increment newValue with value of digit * base^column
	for (int i=0; i < strlen(fromvalue); i++)
		newvalue += (maptoint(fromvalue[i]) * pow(base,
					strlen(fromvalue)-i-1));

	return newvalue;
}

void printhelpdisplay()
{
	printf("Usage: numconvert [NUMBER] -b[2-16] (decimal number to other base)\n");
	printf("   or  numconvert -b[2-16] [NUMBER] (other base to decimal)\n");
	printf("   or  numconvert -b[2-16] [NUMBER] -b[2-16] (base to other base)\n");
}

void printerrordisplay()
{
	printf("ERROR: Improper syntax\n\n");
	printf("Type -h or --help for a list of available commands and formats\n");
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
	else if (strcmp(argv[index], "-h") == 0 ||
			strcmp(argv[index], "--help") == 0)
	{
		printhelpdisplay();
		exit(0);
	}
	else
	{
		printerrordisplay();
		exit(-1);
	}
}

/* Check user arguments */
void checkargs(unsigned short *flags, char **fromvalue, int
		argc, char* argv[])
{
	if (argc < 2)
	{
		printerrordisplay();
		exit(-1);
	}
	else if (argc == 2)
	{
		// Check for help flag, which will terminate program
		// with help display
		if (argv[1][0] == '-')
			flags[0] = flagcheck(1, argv);

		printerrordisplay();
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
			printerrordisplay();
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
		printerrordisplay();
		exit(-1);
	}
}

int main(int argc, char* argv[])
{
	// Array to store flag values-- the first index is the
	// base of the number to be converted; the second index
	// is the base of the converted number
	unsigned short flags[2];
	// Strings to store values of original and converted
	// numbers
	char *fromvalue;
	char tovalue[128];
	// Check arguments & set flag / number values
	checkargs(flags, &fromvalue, argc, argv);

	// Run program according to flag values set by user
	if (flags[0] == 10)
	{
		convertfromdecimal(atol(fromvalue), tovalue,
				flags[1]);
		printf("%s\n", tovalue);
	}
	else if (flags[1] == 10)
	{
		converttodecimal(fromvalue, tovalue, flags[0]);
		printf("%s\n", tovalue);
	}
	else
	{
		unsigned long midvalue = returndecimal(fromvalue, flags[0]);
		convertfromdecimal(midvalue, tovalue, flags[1]);
		printf("%s\n", tovalue);
	}

	return 0;
}
