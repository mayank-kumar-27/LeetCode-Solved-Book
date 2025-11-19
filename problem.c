#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Function: removeStars
 * ---------------------
 * Removes characters based on asterisk positions
 * Each asterisk removes the closest non-asterisk character to its left
 * 
 * s: input string containing lowercase letters and asterisks
 * 
 * Returns: dynamically allocated string with result (caller must free)
 * 
 * Algorithm:
 * - Use a stack-based approach
 * - Push non-asterisk characters onto stack
 * - When encountering asterisk, pop one character from stack
 * - Final stack contains the result
 * 
 * Time Complexity: O(n) where n is length of string
 * Space Complexity: O(n) for the stack
 */
char* removeStars(char* s) {
    int len = strlen(s);
    
    // Allocate memory for result (worst case: no asterisks)
    char* stack = (char*)malloc((len + 1) * sizeof(char));
    if (stack == NULL) {
        return NULL;
    }
    
    int top = 0; // Stack pointer (also represents current length)
    
    // Process each character
    for (int i = 0; i < len; i++) {
        if (s[i] == '*') {
            // Remove the last character from stack (if exists)
            if (top > 0) {
                top--;
            }
        } else {
            // Push character onto stack
            stack[top] = s[i];
            top++;
        }
    }
    
    // Null-terminate the result
    stack[top] = '\0';
    
    return stack;
}

int main() {
    // Allocate buffer for input string
    char* s = (char*)malloc(100001 * sizeof(char));
    
    if (s == NULL) {
        return 1;
    }
    
    // Read the input string
    if (scanf("%s", s) != 1) {
        free(s);
        return 1;
    }
    
    // Process the string
    char* result = removeStars(s);
    
    if (result == NULL) {
        free(s);
        return 1;
    }
    
    // Print the result
    printf("%s\n", result);
    
    // Free allocated memory
    free(result);
    free(s);
    
    return 0;
}

