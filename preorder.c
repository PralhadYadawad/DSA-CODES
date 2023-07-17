
#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insertNode(struct Node* root, int data) {
    // If the tree is empty, create a new node and set it as the root
    if (root == NULL) {
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to perform a preorder traversal of the binary tree
void preorderTraversal(struct Node* root, FILE* file) {
    if (root != NULL) {
        fprintf(file, "%d ", root->data);
        preorderTraversal(root->left, file);
        preorderTraversal(root->right, file);
    }
}

int main() {
    // Open the file in read mode
    FILE* inputFile = fopen("random_numbers.txt", "r");

    // Check if the input file was opened successfully
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    // Initialize the root of the binary tree
    struct Node* root = NULL;

    // Read numbers from the input file and insert them into the binary tree
    int number;
    while (fscanf(inputFile, "%d", &number) == 1) {
        root = insertNode(root, number);
    }

    // Close the input file
    fclose(inputFile);

    // Open the output file in write mode
    FILE* outputFile = fopen("preorder_traversal.txt", "w");

    // Check if the output file was opened successfully
    if (outputFile == NULL) {
        printf("Failed to open the output file.\n");
        return 1;
    }

    // Perform a preorder traversal on the binary tree and store the traversal in the output file
    preorderTraversal(root, outputFile);

    // Close the output file
    fclose(outputFile);

    printf("Preorder traversal has been stored in the file 'preorder_traversal.txt'.\n");

    return 0;
}






