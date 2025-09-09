#include "push_swap.h"
#include <stdio.h>

/*
 * MINIMAL ERROR HANDLING FOR BITMASKING DEMO
 * ===========================================
 * 
 * This file provides minimal error handling functions to make
 * the bitmasking demo work without requiring full error_exit.c
 */

// Simple error function for malloc failures
void error_malloc(t_node **a)
{
    (void)a;  // Avoid unused parameter warning
    printf("Error: Memory allocation failed\n");
    exit(1);
}

// Simple error function for array issues
void error_array(int *array, int size)
{
    (void)array;  // Avoid unused parameter warning
    (void)size;   // Avoid unused parameter warning
    printf("Error: Array processing failed\n");
    exit(1);
}

// Other error functions that might be needed
void error_int(t_node **a)
{
    (void)a;
    printf("Error: Integer overflow\n");
    exit(1);
}

void error_digit(t_node **a)
{
    (void)a;
    printf("Error: Invalid digit\n");
    exit(1);
}

void error_double(t_node **a)
{
    (void)a;
    printf("Error: Duplicate number\n");
    exit(1);
}