#include "push_swap.h"
#include <stdio.h>

/*
 * BITMASKING FUNCTIONS FOR PUSH_SWAP
 * ===================================
 * 
 * This file implements binary conversion and bitmasking utilities
 * specifically useful for radix sort in the push_swap project.
 */

// Get the number of bits needed to represent a number
int get_bit_count(int num)
{
    int bits = 0;
    if (num == 0) return 1;
    
    while (num > 0) {
        bits++;
        num >>= 1;  // Right shift is like dividing by 2
    }
    return bits;
}

// Get the maximum number of bits needed for any number in the stack
int get_max_bits(t_node *stack)
{
    int max_bits = 0;
    t_node *current = stack;
    
    while (current) {
        int bits = get_bit_count(current->data);
        if (bits > max_bits) {
            max_bits = bits;
        }
        current = current->next;
    }
    return max_bits;
}

// Check if a specific bit is set in a number (0-indexed from right)
int is_bit_set(int num, int bit_position)
{
    return (num >> bit_position) & 1;
}

// Convert number to binary and store in array (LSB at index 0)
void number_to_binary_array(int num, int *binary_array, int array_size)
{
    for (int i = 0; i < array_size; i++) {
        binary_array[i] = (num >> i) & 1;
    }
}

// Print binary representation of a number
void print_binary_representation(int num, int bits)
{
    printf("Number %d in binary (%d bits): ", num, bits);
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0 && i > 0) printf(" ");
    }
    printf("\n");
}

// Extract a specific bit from a number using bitmasking
int extract_bit(int num, int bit_position)
{
    int mask = 1 << bit_position;  // Create mask with only target bit set
    return (num & mask) ? 1 : 0;   // Apply mask and return 0 or 1
}

// Extract multiple bits from a number (useful for optimized radix sort)
int extract_bit_range(int num, int start_bit, int num_bits)
{
    // Create mask with num_bits ones: (1 << num_bits) - 1
    int mask = (1 << num_bits) - 1;
    // Shift number right to align bits, then apply mask
    return (num >> start_bit) & mask;
}

// Count number of set bits in a number (population count)
int count_set_bits(int num)
{
    int count = 0;
    while (num) {
        count += num & 1;  // Add 1 if lowest bit is set
        num >>= 1;         // Shift right to check next bit
    }
    return count;
}

// Fast bit counting using Brian Kernighan's algorithm
int count_set_bits_fast(int num)
{
    int count = 0;
    while (num) {
        num &= (num - 1);  // Clear the lowest set bit
        count++;
    }
    return count;
}

// Check if number is a power of 2 using bitmasking
int is_power_of_2(int num)
{
    return (num > 0) && ((num & (num - 1)) == 0);
}

// Find the position of the lowest set bit (useful for optimization)
int find_lowest_set_bit(int num)
{
    if (num == 0) return -1;
    
    int position = 0;
    while (!(num & 1)) {
        position++;
        num >>= 1;
    }
    return position;
}

// Create a mask with n bits set to 1
int create_mask(int num_bits)
{
    if (num_bits >= 32) return -1;  // All bits set
    return (1 << num_bits) - 1;
}

// Radix sort helper: get digit at specific bit position
int get_bit_digit(int num, int bit_position)
{
    return (num >> bit_position) & 1;
}

// Demonstrate bitmasking for the specific use case of push_swap radix sort
void demonstrate_radix_bitmasking(t_node *stack)
{
    if (!stack) {
        printf("Stack is empty\n");
        return;
    }
    
    printf("\n=== BITMASKING FOR RADIX SORT ===\n");
    
    // Find maximum bits needed
    int max_bits = get_max_bits(stack);
    printf("Maximum bits needed: %d\n", max_bits);
    
    // Show binary representation of each number in stack
    printf("\nBinary representations:\n");
    t_node *current = stack;
    while (current) {
        print_binary_representation(current->data, max_bits);
        current = current->next;
    }
    
    // Show how radix sort would process each bit position
    printf("\nRadix sort bit extraction:\n");
    for (int bit = 0; bit < max_bits; bit++) {
        printf("\nBit position %d:\n", bit);
        current = stack;
        while (current) {
            int bit_value = get_bit_digit(current->data, bit);
            printf("  Number %3d: bit %d = %d\n", current->data, bit, bit_value);
            current = current->next;
        }
    }
}

// Function to convert index to binary for stack operations
void convert_index_to_binary(int index, int max_bits)
{
    printf("Converting index %d to %d-bit binary:\n", index, max_bits);
    
    // Method 1: Using division/modulo (traditional approach)
    printf("Method 1 (division): ");
    int temp = index;
    int binary[32];  // Assuming max 32 bits
    int i = 0;
    
    if (temp == 0) {
        binary[0] = 0;
        i = 1;
    } else {
        while (temp > 0) {
            binary[i] = temp % 2;
            temp = temp / 2;
            i++;
        }
    }
    
    // Print in correct order (MSB first)
    for (int j = max_bits - 1; j >= 0; j--) {
        if (j < i) {
            printf("%d", binary[j]);
        } else {
            printf("0");
        }
    }
    printf("\n");
    
    // Method 2: Using bitmasking (faster approach)
    printf("Method 2 (bitmasking): ");
    for (int bit = max_bits - 1; bit >= 0; bit--) {
        printf("%d", (index >> bit) & 1);
    }
    printf("\n");
    
    // Show the bitmasking operations
    printf("Bitmasking breakdown:\n");
    for (int bit = 0; bit < max_bits; bit++) {
        int mask = 1 << bit;
        int result = (index & mask) ? 1 : 0;
        printf("  Bit %d: (index & (1 << %d)) = (%d & %d) = %d\n", 
               bit, bit, index, mask, result);
    }
}
