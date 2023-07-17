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

