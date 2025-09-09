#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * PRACTICAL BITMASKING DEMO FOR PUSH_SWAP
 * ========================================
 * 
 * This program demonstrates bitmasking concepts specifically in the 
 * context of the push_swap project and radix sort algorithm.
 */

// Create a simple test stack for demonstration
t_node *create_demo_stack(void)
{
    int test_values[] = {42, 17, 3, 89, 156, 7, 234, 99};
    int size = sizeof(test_values) / sizeof(test_values[0]);
    t_node *stack = NULL;
    
    // Add values to stack (reverse order so they appear in correct order)
    for (int i = size - 1; i >= 0; i--) {
        add_to_stack(&stack, test_values[i]);
    }
    
    return stack;
}

// Print stack contents
void print_stack(t_node *stack, const char *name)
{
    printf("\nStack %s contents:\n", name);
    t_node *current = stack;
    int position = 0;
    
    while (current) {
        printf("Position %d: %d\n", position, current->data);
        current = current->next;
        position++;
    }
}

// Free stack memory
void free_stack(t_node *stack)
{
    while (stack) {
        t_node *temp = stack;
        stack = stack->next;
        free(temp);
    }
}

// Demonstrate basic bitmasking operations on stack values
void demo_basic_operations(t_node *stack)
{
    printf("\n=== BASIC BITMASKING OPERATIONS ON STACK ===\n");
    
    t_node *current = stack;
    while (current) {
        int num = current->data;
        int bits_needed = get_bit_count(num);
        
        printf("\nNumber: %d\n", num);
        print_binary_representation(num, 8);
        printf("Bits needed: %d\n", bits_needed);
        printf("Set bits count: %d\n", count_set_bits(num));
        printf("Is power of 2: %s\n", is_power_of_2(num) ? "Yes" : "No");
        
        // Show specific bit checks
        printf("Bit checks: ");
        for (int bit = 0; bit < 8; bit++) {
            printf("bit%d=%d ", bit, is_bit_set(num, bit));
        }
        printf("\n");
        
        current = current->next;
    }
}

// Demonstrate bit extraction techniques
void demo_bit_extraction(t_node *stack)
{
    printf("\n=== BIT EXTRACTION TECHNIQUES ===\n");
    
    t_node *current = stack;
    while (current) {
        int num = current->data;
        
        printf("\nNumber: %d\n", num);
        print_binary_representation(num, 8);
        
        // Extract different bit ranges
        printf("Lower 4 bits: %d (binary: ", extract_bit_range(num, 0, 4));
        for (int i = 3; i >= 0; i--) {
            printf("%d", extract_bit(num, i));
        }
        printf(")\n");
        
        printf("Upper 4 bits: %d (binary: ", extract_bit_range(num, 4, 4));
        for (int i = 7; i >= 4; i--) {
            printf("%d", extract_bit(num, i));
        }
        printf(")\n");
        
        current = current->next;
    }
}

// Simulate radix sort bit-by-bit analysis
void demo_radix_sort_analysis(t_node *stack)
{
    printf("\n=== RADIX SORT BITMASKING ANALYSIS ===\n");
    
    int max_bits = get_max_bits(stack);
    printf("Maximum bits needed for any number in stack: %d\n", max_bits);
    
    // Analyze each bit position for radix sort
    for (int bit_pos = 0; bit_pos < max_bits; bit_pos++) {
        printf("\n--- Bit position %d ---\n", bit_pos);
        
        int count_0 = 0, count_1 = 0;
        t_node *current = stack;
        
        printf("Numbers with bit %d = 0: ", bit_pos);
        current = stack;
        while (current) {
            if (!is_bit_set(current->data, bit_pos)) {
                printf("%d ", current->data);
                count_0++;
            }
            current = current->next;
        }
        printf("(count: %d)\n", count_0);
        
        printf("Numbers with bit %d = 1: ", bit_pos);
        current = stack;
        while (current) {
            if (is_bit_set(current->data, bit_pos)) {
                printf("%d ", current->data);
                count_1++;
            }
            current = current->next;
        }
        printf("(count: %d)\n", count_1);
        
        printf("Distribution: %d zeros, %d ones\n", count_0, count_1);
    }
}

// Demonstrate bitmask patterns useful for optimization
void demo_optimization_patterns(t_node *stack)
{
    printf("\n=== OPTIMIZATION PATTERNS ===\n");
    
    t_node *current = stack;
    while (current) {
        int num = current->data;
        
        printf("\nNumber: %d\n", num);
        
        // Fast power of 2 check
        printf("Power of 2 check: %s\n", 
               is_power_of_2(num) ? "YES" : "NO");
        
        // Find lowest set bit (useful for some algorithms)
        int lowest_bit = find_lowest_set_bit(num);
        printf("Lowest set bit position: %d\n", lowest_bit);
        
        // Fast bit counting
        printf("Set bits (fast count): %d\n", count_set_bits_fast(num));
        
        // Isolate rightmost set bit
        int rightmost = num & -num;
        printf("Rightmost set bit value: %d\n", rightmost);
        
        current = current->next;
    }
}

// Demonstrate index-to-binary conversion (useful for stack indexing)
void demo_index_conversion(t_node *stack)
{
    printf("\n=== INDEX TO BINARY CONVERSION ===\n");
    
    int stack_size = count_stack_size(stack);
    int bits_needed = get_bit_count(stack_size - 1);
    
    printf("Stack size: %d\n", stack_size);
    printf("Bits needed for indexing: %d\n", bits_needed);
    
    // Show binary representation of each index
    for (int i = 0; i < stack_size; i++) {
        printf("\nIndex %d:\n", i);
        convert_index_to_binary(i, bits_needed);
    }
}

// Practical example: Simple bit-based sorting decision
void demo_sorting_decisions(t_node *stack)
{
    printf("\n=== BIT-BASED SORTING DECISIONS ===\n");
    
    int max_bits = get_max_bits(stack);
    
    for (int bit_pos = 0; bit_pos < max_bits; bit_pos++) {
        printf("\n--- Processing bit position %d ---\n", bit_pos);
        
        // Simulate push_swap operations based on bit values
        printf("If implementing radix sort:\n");
        printf("1. For each number in stack A:\n");
        printf("2. Check bit %d using: (number >> %d) & 1\n", bit_pos, bit_pos);
        printf("3. If bit is 0: keep in stack A\n");
        printf("4. If bit is 1: push to stack B\n");
        printf("5. After processing all: push all from B back to A\n");
        
        printf("\nActual bit values for this position:\n");
        t_node *current = stack;
        while (current) {
            int bit_val = get_bit_digit(current->data, bit_pos);
            printf("Number %3d: bit %d = %d -> %s\n", 
                   current->data, bit_pos, bit_val,
                   bit_val ? "push to B" : "keep in A");
            current = current->next;
        }
    }
}

int main(void)
{
    printf("BITMASKING TUTORIAL - PUSH_SWAP CONTEXT\n");
    printf("=======================================\n");
    
    // Create demonstration stack
    t_node *demo_stack = create_demo_stack();
    
    if (!demo_stack) {
        printf("Failed to create demo stack\n");
        return 1;
    }
    
    // Print initial stack
    print_stack(demo_stack, "Demo");
    
    // Run all demonstrations
    demo_basic_operations(demo_stack);
    demo_bit_extraction(demo_stack);
    demo_radix_sort_analysis(demo_stack);
    demo_optimization_patterns(demo_stack);
    demo_index_conversion(demo_stack);
    demo_sorting_decisions(demo_stack);
    
    // Show the comprehensive bitmasking analysis
    demonstrate_radix_bitmasking(demo_stack);
    
    printf("\n=== BITMASKING CHEAT SHEET ===\n");
    printf("Essential operations for push_swap:\n");
    printf("• Check bit n:           (num >> n) & 1\n");
    printf("• Set bit n:             num |= (1 << n)\n");
    printf("• Clear bit n:           num &= ~(1 << n)\n");
    printf("• Toggle bit n:          num ^= (1 << n)\n");
    printf("• Extract lower k bits:  num & ((1 << k) - 1)\n");
    printf("• Count set bits:        while(n) { count += n & 1; n >>= 1; }\n");
    printf("• Fast bit count:        while(n) { n &= n-1; count++; }\n");
    printf("• Is power of 2:         (n > 0) && ((n & (n-1)) == 0)\n");
    printf("• Isolate rightmost bit: n & -n\n");
    
    printf("\nRadix sort with bitmasking:\n");
    printf("1. Find max bits needed: log2(max_number) + 1\n");
    printf("2. For each bit position (0 to max_bits-1):\n");
    printf("   a. Extract bit: (number >> bit_pos) & 1\n");
    printf("   b. Sort based on bit value (0s first, then 1s)\n");
    printf("   c. Use push_swap operations to rearrange\n");
    printf("3. After processing all bits: array is sorted!\n");
    
    // Clean up
    free_stack(demo_stack);
    
    printf("\nTo run the comprehensive tutorial: ./bitmasking_tutorial\n");
    printf("To test these functions: integrate them into your push_swap!\n");
    
    return 0;
}