#include <stdio.h>
#include <stdint.h>

/*
 * BITMASKING TUTORIAL
 * ===================
 * 
 * Bitmasking is a technique that uses bitwise operations to manipulate
 * individual bits within a number. It's extremely useful for:
 * - Setting specific bits
 * - Clearing specific bits 
 * - Toggling specific bits
 * - Checking if specific bits are set
 * - Extracting groups of bits
 * - Optimizing algorithms (like radix sort!)
 */

void print_binary(int num, int bits)
{
    printf("Binary of %d: ", num);
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0 && i > 0) printf(" ");  // Add space every 4 bits
    }
    printf(" (0x%X)\n", num);
}

void demo_basic_bitwise_operations(void)
{
    printf("\n=== BASIC BITWISE OPERATIONS ===\n");
    
    int a = 12;  // 1100 in binary
    int b = 10;  // 1010 in binary
    
    printf("a = %d, b = %d\n", a, b);
    print_binary(a, 8);
    print_binary(b, 8);
    
    printf("\nBitwise AND (&): Only 1 if both bits are 1\n");
    printf("a & b = %d\n", a & b);
    print_binary(a & b, 8);
    
    printf("\nBitwise OR (|): 1 if either bit is 1\n");
    printf("a | b = %d\n", a | b);
    print_binary(a | b, 8);
    
    printf("\nBitwise XOR (^): 1 if bits are different\n");
    printf("a ^ b = %d\n", a ^ b);
    print_binary(a ^ b, 8);
    
    printf("\nBitwise NOT (~): Flips all bits\n");
    printf("~a = %d\n", ~a);
    print_binary(~a & 0xFF, 8);  // Mask to show only 8 bits
    
    printf("\nLeft shift (<<): Moves bits left (multiplies by 2^n)\n");
    printf("a << 2 = %d\n", a << 2);
    print_binary(a << 2, 8);
    
    printf("\nRight shift (>>): Moves bits right (divides by 2^n)\n");
    printf("a >> 1 = %d\n", a >> 1);
    print_binary(a >> 1, 8);
}

void demo_bitmask_techniques(void)
{
    printf("\n=== BITMASK TECHNIQUES ===\n");
    
    int number = 42;  // 101010 in binary
    printf("Working with number: %d\n", number);
    print_binary(number, 8);
    
    // 1. Check if a specific bit is set
    printf("\n1. Checking if bit is set:\n");
    for (int bit = 0; bit < 6; bit++) {
        int mask = 1 << bit;  // Create mask with only bit 'bit' set
        int is_set = (number & mask) != 0;
        printf("Bit %d: %s (mask: ", bit, is_set ? "SET" : "NOT SET");
        print_binary(mask, 8);
    }
    
    // 2. Set a specific bit
    printf("\n2. Setting bit 2:\n");
    int bit_to_set = 2;
    int mask_set = 1 << bit_to_set;
    int result_set = number | mask_set;
    printf("Original: "); print_binary(number, 8);
    printf("Mask:     "); print_binary(mask_set, 8);
    printf("Result:   "); print_binary(result_set, 8);
    
    // 3. Clear a specific bit
    printf("\n3. Clearing bit 3:\n");
    int bit_to_clear = 3;
    int mask_clear = ~(1 << bit_to_clear);
    int result_clear = number & mask_clear;
    printf("Original: "); print_binary(number, 8);
    printf("Mask:     "); print_binary(mask_clear & 0xFF, 8);
    printf("Result:   "); print_binary(result_clear, 8);
    
    // 4. Toggle a specific bit
    printf("\n4. Toggling bit 1:\n");
    int bit_to_toggle = 1;
    int mask_toggle = 1 << bit_to_toggle;
    int result_toggle = number ^ mask_toggle;
    printf("Original: "); print_binary(number, 8);
    printf("Mask:     "); print_binary(mask_toggle, 8);
    printf("Result:   "); print_binary(result_toggle, 8);
}

void demo_extract_bits(void)
{
    printf("\n=== EXTRACTING BITS ===\n");
    
    int number = 0xABCD;  // 1010 1011 1100 1101
    printf("Working with number: %d (0x%X)\n", number, number);
    print_binary(number, 16);
    
    // Extract lower 4 bits
    int lower_4 = number & 0x0F;  // Mask: 0000 1111
    printf("\nLower 4 bits: %d (0x%X)\n", lower_4, lower_4);
    print_binary(lower_4, 4);
    
    // Extract upper 4 bits
    int upper_4 = (number >> 12) & 0x0F;  // Shift right 12, then mask
    printf("\nUpper 4 bits: %d (0x%X)\n", upper_4, upper_4);
    print_binary(upper_4, 4);
    
    // Extract middle 8 bits
    int middle_8 = (number >> 4) & 0xFF;  // Shift right 4, then mask 8 bits
    printf("\nMiddle 8 bits: %d (0x%X)\n", middle_8, middle_8);
    print_binary(middle_8, 8);
}

void demo_counting_bits(void)
{
    printf("\n=== COUNTING BITS ===\n");
    
    int numbers[] = {7, 15, 31, 42, 100, 255};
    int count = sizeof(numbers) / sizeof(numbers[0]);
    
    for (int i = 0; i < count; i++) {
        int num = numbers[i];
        int set_bits = 0;
        
        // Count set bits using bit manipulation
        int temp = num;
        while (temp) {
            set_bits += temp & 1;  // Add 1 if lowest bit is set
            temp >>= 1;            // Shift right to check next bit
        }
        
        printf("Number %3d: ", num);
        print_binary(num, 8);
        printf("          Set bits: %d\n", set_bits);
    }
    
    printf("\nBrian Kernighan's algorithm (faster bit counting):\n");
    for (int i = 0; i < count; i++) {
        int num = numbers[i];
        int set_bits = 0;
        int temp = num;
        
        // This algorithm clears the lowest set bit in each iteration
        while (temp) {
            temp &= (temp - 1);  // Clear the lowest set bit
            set_bits++;
        }
        
        printf("Number %3d has %d set bits\n", num, set_bits);
    }
}

void demo_radix_sort_bitmasking(void)
{
    printf("\n=== BITMASKING IN RADIX SORT ===\n");
    printf("This shows how bitmasking helps in radix sort implementation\n");
    
    int numbers[] = {170, 45, 75, 90, 2, 802, 24, 66};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("\nOriginal numbers:\n");
    for (int i = 0; i < size; i++) {
        printf("%3d: ", numbers[i]);
        print_binary(numbers[i], 10);
    }
    
    printf("\nExtracting bits for radix sort:\n");
    
    // Show how to extract specific bit positions for sorting
    for (int bit_pos = 0; bit_pos < 10; bit_pos++) {
        printf("\nBit position %d:\n", bit_pos);
        for (int i = 0; i < size; i++) {
            int bit_value = (numbers[i] >> bit_pos) & 1;
            printf("Number %3d: bit %d = %d\n", numbers[i], bit_pos, bit_value);
        }
    }
    
    printf("\nFor radix sort, you would:\n");
    printf("1. For each bit position (0 to max_bits-1):\n");
    printf("2. Extract that bit from each number using: (number >> bit_pos) & 1\n");
    printf("3. Separate numbers into two groups: bit=0 and bit=1\n");
    printf("4. Concatenate groups: bit=0 first, then bit=1\n");
    printf("5. Repeat for next bit position\n");
}

void demo_common_bitmask_patterns(void)
{
    printf("\n=== COMMON BITMASK PATTERNS ===\n");
    
    printf("1. Powers of 2 detection:\n");
    int test_nums[] = {1, 2, 3, 4, 5, 8, 16, 17, 32};
    for (int i = 0; i < 9; i++) {
        int num = test_nums[i];
        int is_power_of_2 = (num > 0) && ((num & (num - 1)) == 0);
        printf("   %2d is %sa power of 2\n", num, is_power_of_2 ? "" : "NOT ");
    }
    
    printf("\n2. Isolating the rightmost set bit:\n");
    for (int i = 0; i < 5; i++) {
        int num = test_nums[i + 2];
        int rightmost_bit = num & -num;  // Isolate rightmost set bit
        printf("   Number: "); print_binary(num, 8);
        printf("   Rightmost set bit: "); print_binary(rightmost_bit, 8);
    }
    
    printf("\n3. Creating masks for bit ranges:\n");
    printf("   Mask for bits 2-5: ");
    int mask_range = ((1 << 4) - 1) << 2;  // Create 4 ones, shift left 2
    print_binary(mask_range, 8);
    
    printf("   Extracting bits 2-5 from 0xAB:\n");
    int value = 0xAB;
    int extracted = (value & mask_range) >> 2;
    printf("   Original: "); print_binary(value, 8);
    printf("   Mask:     "); print_binary(mask_range, 8);
    printf("   Result:   "); print_binary(extracted, 4);
}

int main(void)
{
    printf("COMPREHENSIVE BITMASKING TUTORIAL\n");
    printf("=================================\n");
    
    demo_basic_bitwise_operations();
    demo_bitmask_techniques();
    demo_extract_bits();
    demo_counting_bits();
    demo_radix_sort_bitmasking();
    demo_common_bitmask_patterns();
    
    printf("\n=== SUMMARY ===\n");
    printf("Key bitmasking operations:\n");
    printf("• Check bit:    (num & (1 << bit)) != 0\n");
    printf("• Set bit:      num |= (1 << bit)\n");
    printf("• Clear bit:    num &= ~(1 << bit)\n");
    printf("• Toggle bit:   num ^= (1 << bit)\n");
    printf("• Extract bits: (num >> shift) & mask\n");
    printf("• Count bits:   Use num &= (num - 1) in loop\n");
    printf("\nThese techniques are essential for:\n");
    printf("• Radix sort implementation\n");
    printf("• Efficient data structures\n");
    printf("• Optimization algorithms\n");
    printf("• Low-level programming\n");
    
    return 0;
}