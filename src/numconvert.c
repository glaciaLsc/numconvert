/* Copyright (C) 2020  Garrett A Justice 
<garrettjustice@protonmail.com>

This program is free software: you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see
<https://www.gnu.org/licenses/> */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char
maptochar(int n)
{
	switch(n) {
	case 0:
		return '0';
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 10:
		return 'A';
	case 11:
		return 'B';
	case 12:
		return 'C';
	case 13:
		return 'D';
	case 14:
		return 'E';
	case 15:
		return 'F';
	}
}

int
maptoint(char c)
{
	switch(c) {
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'a': case 'A':
		return 10;
	case 'b': case 'B':
		return 11;
	case 'c': case 'C':
		return 12;
	case 'd': case 'D':
		return 13;
	case 'e': case 'E':
		return 14;
	case 'f': case 'F':
		return 15;
	}
}

void
reverse_string(char *str, int size)
{
	char tmp[size+1];

	for (int i=size-1; i >= 0; i--)
		tmp[size-i-1] = str[i];
	tmp[size] = '\0';

	strcpy(str, tmp);
}

void
convertfromdecimal(unsigned int input_number, char *output_number, 
		int output_base_value)
{
	do {
		// Store remainder value in temporary char
		char rmdr = maptochar(input_number % output_base_value);
		char tmp[] = {rmdr, '\0'};

		// Append remainder value to output number string
		strcat(output_number, tmp);
		// Update input number value
		input_number /= output_base_value;
	} while (input_number != 0);

	
	// Reverse string, which stores digits backwards
	reverse_string(output_number, strlen(output_number));
}

void
converttodecimal(char *input_number, char *output_number, int input_base_value)
{
	unsigned int tmp = 0;
	
	// Increment tmp with value of digit * base^column
	for (int i=0; i < strlen(input_number); i++)
		tmp += (maptoint(input_number[i]) * 
				powf(input_base_value, strlen(input_number)-i-1));

	sprintf(output_number, "%u", tmp);
}

unsigned int
returndecimal(char *input_number, int input_base_value)
{
	unsigned int n = 0;

	// Increment n with value of digit * base^column
	for (int i=0; i < strlen(input_number); i++)
		n += (maptoint(input_number[i]) * 
				powf(input_base_value, strlen(input_number)-i-1));

	return n;
}

void
print_help_display()
{
	printf("Usage: numconvert [NUMBER] -b[2-16] (decimal number to other base)\n");
	printf("   or  numconvert -b[2-16] [NUMBER] (other base to decimal)\n");
	printf("   or  numconvert -b[2-16] [NUMBER] -b[2-16] (base to other base)\n");
}

void
print_error_display()
{
	printf("ERROR: Improper syntax\n\n");
	printf("Type -h or --help for a list of available commands and formats\n");
}

short
flagcheck(char *arg)
{
	if (strcmp(arg, "-b2") == 0)
		return 2;
	else if (strcmp(arg, "-b3") == 0)
		return 3;
	else if (strcmp(arg, "-b4") == 0)
		return 4;
	else if (strcmp(arg, "-b5") == 0)
		return 5;
	else if (strcmp(arg, "-b6") == 0)
		return 6;
	else if (strcmp(arg, "-b7") == 0)
		return 7;
	else if (strcmp(arg, "-b8") == 0)
		return 8;
	else if (strcmp(arg, "-b9") == 0)
		return 9;
	else if (strcmp(arg, "-b10") == 0)
		return 10;
	else if (strcmp(arg, "-b11") == 0)
		return 11;
	else if (strcmp(arg, "-b12") == 0)
		return 12;
	else if (strcmp(arg, "-b13") == 0)
		return 13;
	else if (strcmp(arg, "-b14") == 0)
		return 14;
	else if (strcmp(arg, "-b15") == 0)
		return 15;
	else if (strcmp(arg, "-b16") == 0)
		return 16;
	else if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
		print_help_display();
		exit(0);
	}
	else {
		print_error_display();
		exit(-1);
	}
}

void 
parse_args(int *input_base_value, int *output_base_value, 
		char **input_number, int argc, char* argv[])
{
	switch (argc) {
	case 1:
		print_error_display();
		exit(-1);
	case 2:
		// Check for help flag, which will terminate program
		// with help display
		if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
			print_help_display();
			exit(0);
		}
		else {
			print_error_display();
			exit(-1);
		}
	case 3:
		// If 1st argument is not flag and 2nd argument is
		// flag, set input base value to 10
		if (argv[1][0] != '-' && argv[2][0] == '-') {
			*input_base_value = 10;
			*output_base_value = flagcheck(argv[2]);
			*input_number = argv[1];
		}
		// If 1st argument is flag and 2nd argument is not
		// flag, set output base value to 10
		else if (argv[1][0] == '-' && argv[2][0] != '-') {
			*output_base_value = 10;
			*input_base_value = flagcheck(argv[1]);
			*input_number = argv[2];
		}
		else {
			print_error_display();
			exit(-1);
		}
		return;
	case 4:
		*input_base_value = flagcheck(argv[1]);
		*output_base_value = flagcheck(argv[3]);
		*input_number = argv[2];
		return;
	default:
		print_error_display();
		exit(-1);
	}
}

int 
main(int argc, char* argv[])
{
	int input_base_value, output_base_value;
	char *input_number;
	char output_number[128] = "";

	// Check arguments & set base / number values
	parse_args(&input_base_value, &output_base_value, &input_number, argc, argv);

	// Run program according to flag values set by user
	if (input_base_value == 10) {
		convertfromdecimal(atoi(input_number), output_number, output_base_value);
		printf("%s\n", output_number);
	} 
	else if (output_base_value == 10) {
		converttodecimal(input_number, output_number, input_base_value);
		printf("%s\n", output_number);
	} 
	else {
		unsigned int intermediate_number = returndecimal(input_number,
				input_base_value);
		convertfromdecimal(intermediate_number, output_number, output_base_value);
		printf("%s\n", output_number);
	}

	return 0;
}

