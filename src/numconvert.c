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

/* Linked list data structure */
struct node
{
	char data;
	struct node* next;
	struct node* prev;
};

void append(struct node** headref, char value)
{
	struct node* newnode = (struct node *)malloc(sizeof(struct node));
	struct node* current = *headref;

	newnode->data = value;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (*headref == NULL)
	{
		*headref = newnode;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		
		newnode->prev = current;
		current->next = newnode;
	}
}

char* convertfromdecimal(char* n)
{
	return n;
}

char* converttodecimal(char* n)
{
	return n;
}

char* convert(char* n)
{
	return n;
}

void print(struct node* headref)
{
	while (headref->next != NULL)
		headref = headref->next;
	while (headref != NULL)
	{
		printf("%c\n", headref->data);
		headref = headref->prev;
	}
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
void checkargs(unsigned short *flags, int argc, char* argv[])
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
		}
		// If 1st argument is flag and 2nd argument is not
		// flag, default "to" flag to 10
		else if (argv[1][0] == '-' && argv[2][0] != '-')
		{
			flags[1] = 10;
			flags[0] = flagcheck(1, argv);
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
 *
 * Linked list functionality is complete-- now it's time for
 * arithmetic functions.
 *
 * Functions need to include flags in paramaters, as well as
 * headref
 */
int main(int argc, char* argv[])
{
	// Array to store flag values
	unsigned short flags[2];
	// Check arguments & set flag values
	checkargs(flags, argc, argv);

	// Run program according to flag values set by user
	struct node* head = NULL;

	return 0;
}
