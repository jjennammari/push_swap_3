/*
 * BITMASKING EXERCISES FOR PUSH_SWAP
 * ===================================
 * 
 * Practice exercises to master bitmasking concepts.
 * Try implementing these functions yourself before looking at solutions!
 */

#include "push_swap.h"
#include <stdio.h>

// EXERCISE 1: Implement a function to check if a number is a power of 2
// Hint: Use the fact that powers of 2 have only one bit set
int exercise_is_power_of_2(int num) {
    // TODO: Implement using bitmasking
    // Solution: return (num > 0) && ((num & (num - 1)) == 0);
    (void)num;  // Suppress unused parameter warning
    return 0;  // Replace with your implementation
}

// EXERCISE 2: Count the number of set bits in a number
// Try both the naive approach and Brian Kernighan's algorithm
int exercise_count_set_bits(int num) {
    // TODO: Implement bit counting
    // Naive approach: loop through each bit
    // Fast approach: use num &= (num - 1) to clear lowest set bit
    (void)num;  // Suppress unused parameter warning
    return 0;  // Replace with your implementation
}

// EXERCISE 3: Extract a specific bit range from a number
// For example, extract bits 2-5 from 0b11010110 should give 0b0101
int exercise_extract_bit_range(int num, int start_bit, int num_bits) {
    // TODO: Create a mask and extract the bits
    // Steps: 1) Create mask with num_bits ones
    //        2) Shift number right by start_bit positions
    //        3) Apply mask using AND operation
    (void)num; (void)start_bit; (void)num_bits;  // Suppress warnings
    return 0;  // Replace with your implementation
}

// EXERCISE 4: Implement radix sort helper - get digit at bit position
int exercise_get_bit_digit(int num, int bit_position) {
    // TODO: Extract single bit at given position
    // This is the core operation for radix sort
    (void)num; (void)bit_position;  // Suppress warnings
    return 0;  // Replace with your implementation
}

// EXERCISE 5: Find the position of the lowest set bit
// For example, 0b11010000 should return 4 (0-indexed from right)
int exercise_find_lowest_set_bit(int num) {
    // TODO: Find position of rightmost 1 bit
    // Hint: You can use num & -num to isolate the rightmost bit
    (void)num;  // Suppress warning
    return -1;  // Replace with your implementation (return -1 for 0)
}

// EXERCISE 6: Create a bitmask with n consecutive bits set
// For example, n=4 should return 0b1111 = 15
int exercise_create_mask(int num_bits) {
    // TODO: Create mask with num_bits consecutive 1s
    // Hint: Use left shift and subtraction
    (void)num_bits;  // Suppress warning
    return 0;  // Replace with your implementation
}

// EXERCISE 7: Reverse the bits in a number
// For example, 0b1011 should become 0b1101
int exercise_reverse_bits(int num, int bit_width) {
    // TODO: Reverse the order of bits
    // This is more challenging - extract each bit and build result
    (void)num; (void)bit_width;  // Suppress warnings
    return 0;  // Replace with your implementation
}

// EXERCISE 8: Check if two numbers differ by exactly one bit
// This is useful for optimization in some algorithms
int exercise_differ_by_one_bit(int a, int b) {
    // TODO: Use XOR and power-of-2 check
    // If a and b differ by one bit, a ^ b will be a power of 2
    (void)a; (void)b;  // Suppress warnings
    return 0;  // Replace with your implementation
}

// SOLUTIONS (uncomment to see answers)
/*
int solution_is_power_of_2(int num) {
    return (num > 0) && ((num & (num - 1)) == 0);
}

int solution_count_set_bits(int num) {
    int count = 0;
    while (num) {
        num &= (num - 1);  // Clear lowest set bit
        count++;
    }
    return count;
}

int solution_extract_bit_range(int num, int start_bit, int num_bits) {
    int mask = (1 << num_bits) - 1;  // Create mask with num_bits ones
    return (num >> start_bit) & mask;
}

int solution_get_bit_digit(int num, int bit_position) {
    return (num >> bit_position) & 1;
}

int solution_find_lowest_set_bit(int num) {
    if (num == 0) return -1;
    int position = 0;
    while (!(num & 1)) {
        position++;
        num >>= 1;
    }
    return position;
}

int solution_create_mask(int num_bits) {
    if (num_bits >= 32) return -1;  // All bits set
    return (1 << num_bits) - 1;
}

int solution_reverse_bits(int num, int bit_width) {
    int result = 0;
    for (int i = 0; i < bit_width; i++) {
        result = (result << 1) | (num & 1);
        num >>= 1;
    }
    return result;
}

int solution_differ_by_one_bit(int a, int b) {
    int xor_result = a ^ b;
    return exercise_is_power_of_2(xor_result);
}
*/

// Test function to check your implementations
void test_exercises(void) {
    printf("BITMASKING EXERCISES TEST\n");
    printf("========================\n");
    
    // Test power of 2
    printf("Testing power of 2:\n");
    int test_nums[] = {1, 2, 3, 4, 8, 15, 16, 32, 33};
    for (int i = 0; i < 9; i++) {
        printf("  %d: %s\n", test_nums[i], 
               exercise_is_power_of_2(test_nums[i]) ? "YES" : "NO");
    }
    
    // Test bit counting
    printf("\nTesting bit counting:\n");
    for (int i = 0; i < 6; i++) {
        int num = test_nums[i];
        printf("  %d has %d set bits\n", num, exercise_count_set_bits(num));
    }
    
    // Test bit extraction
    printf("\nTesting bit extraction:\n");
    int test_val = 0xAB;  // 10101011
    printf("  Extract bits 2-5 from 0x%X: 0x%X\n", 
           test_val, exercise_extract_bit_range(test_val, 2, 4));
    
    // Test lowest set bit
    printf("\nTesting lowest set bit:\n");
    int test_lowest[] = {0, 1, 2, 6, 8, 12};
    for (int i = 0; i < 6; i++) {
        printf("  %d: position %d\n", test_lowest[i], 
               exercise_find_lowest_set_bit(test_lowest[i]));
    }
    
    printf("\nImplement the functions above and run again to see results!\n");
}

// Practical push_swap example
void radix_sort_example(void) {
    printf("\nRADIX SORT EXAMPLE\n");
    printf("==================\n");
    
    int numbers[] = {4, 2, 7, 1, 6, 3};
    int size = 6;
    int max_bits = 3;  // 7 requires 3 bits
    
    printf("Sorting array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    printf("\nBinary representations:\n");
    for (int i = 0; i < size; i++) {
        printf("  %d: ", numbers[i]);
        for (int bit = max_bits - 1; bit >= 0; bit--) {
            printf("%d", (numbers[i] >> bit) & 1);
        }
        printf("\n");
    }
    
    printf("\nRadix sort process:\n");
    for (int bit_pos = 0; bit_pos < max_bits; bit_pos++) {
        printf("\nProcessing bit position %d:\n", bit_pos);
        
        printf("  Numbers with bit %d = 0: ", bit_pos);
        for (int i = 0; i < size; i++) {
            if (!((numbers[i] >> bit_pos) & 1)) {
                printf("%d ", numbers[i]);
            }
        }
        printf("\n");
        
        printf("  Numbers with bit %d = 1: ", bit_pos);
        for (int i = 0; i < size; i++) {
            if ((numbers[i] >> bit_pos) & 1) {
                printf("%d ", numbers[i]);
            }
        }
        printf("\n");
    }
    
    printf("\nAfter proper radix sort implementation: 1 2 3 4 6 7\n");
    printf("Try implementing this in your push_swap using pb/pa operations!\n");
}

int main(void) {
    printf("BITMASKING PRACTICE EXERCISES\n");
    printf("=============================\n");
    printf("Complete the exercise functions above, then run this program.\n\n");
    
    test_exercises();
    radix_sort_example();
    
    printf("\nNext steps:\n");
    printf("1. Implement all exercise functions\n");
    printf("2. Study the radix sort example\n");
    printf("3. Apply these concepts to your push_swap project\n");
    printf("4. Run ./bitmasking_tutorial for comprehensive examples\n");
    printf("5. Run ./bitmasking_demo for push_swap context examples\n");
    
    return 0;
}