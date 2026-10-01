#include <stdio.h>

#define MAX 5
int stack[MAX];
int top = -1;

void clearbuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) ;
}

// FIXED: Added missing function declaration and header
void push() {
    int item;
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter the element: ");
        if (scanf("%d", &item) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            clearbuffer(); // Clear the input buffer
            return; // Exit the function early
        }
        top++;
        stack[top] = item;
        printf("%d element pushed successfully\n", item);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped element\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void demonstrate() {
    if (top == MAX - 1) {
        printf("overflow condition\n");
    } else {
        printf("no overflow condition\n");
    }
    if (top == -1) {
        printf("underflow condition\n");
    } else {
        printf("no underflow condition\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");      // FIXED: Updated menu options
        printf("4. Demonstrate\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        
        switch (choice) {
            case 1: 
                push(); 
                break;
            case 2: 
                pop(); 
                break;
            case 3: 
                display(); 
                break;
            case 4: 
                demonstrate(); 
                break;
            case 5: 
                return 0;
            default: 
                printf("Invalid choice\n");
        }
    }
    return 0;
}
