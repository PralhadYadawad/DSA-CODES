/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRandoms(int lower, int upper,
							int count)
{
	int i;
	for (i = 0; i < count; i++) {
		int num = (rand() %
		(upper - lower + 1)) + lower;
		printf("%d ", num);
	}
}


int main()
{
	int lower = 0, upper = 70, count = 10;


	srand(time(0));

	printRandoms(lower, upper, count);

	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int     main(void)
{
    char    str[10];
    FILE    *fptr;
    int     i;
    int     num;
    char    num2;
    i = 0;

    fptr = fopen("map.fdf", "w");
    if (fptr == NULL)
    {
        printf("ERROR Creating File!");
        exit(1);
    }
    while (str[i] != '\0')
    {
        num = rand() % 10;
        num2 = num + '0';
        str[i] = num2;
        i += 1;
    }
    puts(str);
    fprintf(fptr,"%s", str);
    fclose(fptr);
    return (0);
}
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Open the file in write mode
    FILE *file = fopen("random_numbers.txt", "w");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Seed the random number generator with current time
    srand(time(NULL));

    // Generate and store 10 random numbers in the file
    for (int i = 0; i < 10; i++) {
        int random_number = rand();
        fprintf(file, "%d\n", random_number);
    }

    // Close the file
    fclose(file);

    printf("Random numbers have been generated and stored in the file.\n");

    return 0;
}
