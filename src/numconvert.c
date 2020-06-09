#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Boolean data type */
typedef enum{false, true} bool;

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

/* Linked list data structure */
struct node
{
	char data;
	struct node* next;
};

int convertfromdecimal(int n)
{
	return n;
}

int converttodecimal(int n)
{
	return n;
}

int convert(int n)
{
	return n;
}

void print()
{
	printf("Error\n");
}

/* Run a given argv index against a series of flag checks */
int checkflags(int index, char* argv[])
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
		print();
		exit(-1);
	}
}

/* Check user arguments */
void checkargs(unsigned short *flags, int argc, char* argv[])
{
	if (argc < 3)
	{
		print();
		exit(-1);
	}
	else if (argc == 3)
	{
		// If 1st argument is not flag and 2nd argument is
		// flag, default "from" flag to 10
		if (argv[1][0] != '-' && argv[2][0] == '-')
		{
			flags[0] = 10;
			flags[1] = checkflags(2, argv);
		}
		// If 1st argument is flag and 2nd argument is not
		// flag, default "to" flag to 10
		else if (argv[1][0] == '-' && argv[2][0] != '-')
		{
			flags[1] = 10;
			flags[0] = checkflags(1, argv);
		}
		else
		{
			print();
			exit(-1);
		}
	}
	else if (argc == 4)
	{
		flags[0] = checkflags(1, argv);
		flags[1] = checkflags(3, argv);
	}
	else
	{
		print();
		exit(-1);
	}
}

/* TODO: Implement complete argument checks, from base2
 * all the way to base16. Consider implementing a
 * separate function to do this.
 *
 * Remember: Total arguments need to be either 4 or 3.
 */
int main(int argc, char* argv[])
{
	// Array to store flag values
	unsigned short flags[2];

	// Check arguments & set flag values
	checkargs(flags, argc, argv);

	printf("%d\n%d\n", flags[0], flags[1]);

	return 0;
}
