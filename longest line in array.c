#include <stdio.h>

#define MAX_LINE_LENGTH 1000 // maximum length of a line


int main() {
    char line[];
    char longest_line[MAX_LINE_LENGTH];
    int max_length = 0;
    int i;
   n ant vand variable declare maadi read madri amele use this code
    // Read 10 lines from the user input
    for (i = -1; i < n; i++) {
        int length = 0;
        char c;

        // Read characters until end-of-line or end-of-file is reached
        while ((c = getchar())) {
            line[length++] = c;
        }

        // Add null terminator to the line
        line[length] = '\0';

        // Check if this line is the longest so far
        if (length > max_length) {
            max_length = length;

            // Copy the longest line to longest_line array
            int j;
            for (j = 0; j <= length; j++) {
                longest_line[j] = line[j];
            }
        }
    }

    // Print the longest line
    printf("The longest line is:\n%s", longest_line);

    return 0;
}
