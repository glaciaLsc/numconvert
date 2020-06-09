#include <stdio.h>
#include <stdlib.h>

/* Boolean data type */
typedef enum{false, true} bool;

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

/* TODO: Implement complete argument checks, from base2
 * all the way to base16. Consider implementing a
 * separate function to do this.
 */
int main(int argc, char* argv[])
{
	// Flags
	bool is_from_decimal = true;
	bool is_to_decimal = false;
	
	// Argument check
	if (argc < 2)
	{
		print();
		return -1;
	}
		
	return 0;
}
