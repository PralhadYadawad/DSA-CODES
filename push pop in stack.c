#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int element);
int pop();
void display();

int main() {
    int choice, element;
    char inputFileName[100], outputFileName[100];
    FILE *inputFile, *outputFile;

    printf("Enter the input file name: ");
    scanf("%s", inputFileName);
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    printf("Enter the output file name: ");
    scanf("%s", outputFileName);
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        fclose(inputFile);
        return 1;
    }

    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fscanf(inputFile, "%d", &element);
                push(element);
                fprintf(outputFile, "Pushed element: %d\n", element);
                break;
            case 2:
                element = pop();
                if (element != -1)
                    fprintf(outputFile, "Popped element: %d\n", element);
                break;
            case 3:
                display();
                fprintf(outputFile, "Stack elements:\n");
                for (int i = top; i >= 0; i--) {
                    fprintf(outputFile, "%d\n", stack[i]);
                }
                break;
            case 4:
                printf("Exiting...\n");
                fclose(inputFile);
                fclose(outputFile);
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}

void push(int element) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push element.\n");
    } else {
        stack[++top] = element;
        printf("Element %d pushed to stack.\n", element);
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop element.\n");
        return -1;
    } else {
        int element = stack[top--];
        return element;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
