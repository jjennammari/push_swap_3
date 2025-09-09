# Bitmasking Tutorial for Push_Swap

## What is Bitmasking?

Bitmasking is a programming technique that uses bitwise operations to manipulate individual bits within numbers. It's incredibly powerful for optimization, algorithm implementation, and low-level programming tasks.

## Why Learn Bitmasking for Push_Swap?

In the push_swap project, you're implementing sorting algorithms. Bitmasking is particularly useful for:
- **Radix Sort**: The most efficient algorithm for push_swap uses binary representation
- **Index Manipulation**: Converting array indices to binary for optimized sorting
- **Performance Optimization**: Bitwise operations are extremely fast
- **Understanding Binary Systems**: Essential for computer science

## Core Bitwise Operations

### 1. Basic Operations
```c
int a = 12;  // 1100 in binary
int b = 10;  // 1010 in binary

// AND (&): Both bits must be 1
a & b;  // 1000 = 8

// OR (|): Either bit can be 1  
a | b;  // 1110 = 14

// XOR (^): Bits must be different
a ^ b;  // 0110 = 6

// NOT (~): Flip all bits
~a;     // ...11110011 = -13

// Left Shift (<<): Move bits left (multiply by 2^n)
a << 2; // 110000 = 48

// Right Shift (>>): Move bits right (divide by 2^n)
a >> 1; // 0110 = 6
```

### 2. Essential Bitmask Techniques

#### Check if a Bit is Set
```c
int is_bit_set(int num, int bit_position) {
    return (num >> bit_position) & 1;
    // or: return (num & (1 << bit_position)) != 0;
}
```

#### Set a Specific Bit
```c
int set_bit(int num, int bit_position) {
    return num | (1 << bit_position);
}
```

#### Clear a Specific Bit
```c
int clear_bit(int num, int bit_position) {
    return num & ~(1 << bit_position);
}
```

#### Toggle a Specific Bit
```c
int toggle_bit(int num, int bit_position) {
    return num ^ (1 << bit_position);
}
```

## Bitmasking in Radix Sort

Radix sort is perfect for push_swap because it can sort in O(d × n) time, where d is the number of digits (bits) and n is the number of elements.

### Converting Numbers to Binary for Sorting

Instead of sorting the actual numbers, you:
1. Convert each number to its binary representation
2. Sort bit by bit, starting from the least significant bit (rightmost)
3. Use push_swap operations to rearrange based on bit values

### Example: Sorting [4, 2, 7, 1]

```
Numbers:  4   2   7   1
Binary:  100 010 111 001

Bit 0 (rightmost):
0: 4(100), 2(010) -> keep in stack A
1: 7(111), 1(001) -> push to stack B
Result after processing: [4, 2, 1, 7]

Bit 1:
0: 4(100), 1(001) -> keep in stack A  
1: 2(010), 7(111) -> push to stack B
Result after processing: [4, 1, 2, 7]

Bit 2 (leftmost):
0: 1(001), 2(010) -> keep in stack A
1: 4(100), 7(111) -> push to stack B  
Final result: [1, 2, 4, 7] ✓ SORTED!
```

### Implementation Strategy

```c
// Get the bit at position 'bit_pos' from 'number'
int get_bit(int number, int bit_pos) {
    return (number >> bit_pos) & 1;
}

// Radix sort algorithm outline:
for (int bit_pos = 0; bit_pos < max_bits; bit_pos++) {
    // Process each number in stack A
    while (stack_a_not_empty) {
        int current_number = top_of_stack_a;
        int bit_value = get_bit(current_number, bit_pos);
        
        if (bit_value == 0) {
            // Keep in stack A (rotate to bottom)
            ra(stack_a);
        } else {
            // Push to stack B
            pb(stack_a, stack_b);
        }
    }
    
    // Push everything back from B to A
    while (stack_b_not_empty) {
        pa(stack_a, stack_b);
    }
}
```

## Practical Bitmasking Examples

### 1. Count Set Bits (Population Count)
```c
int count_bits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;  // Add 1 if lowest bit is set
        num >>= 1;         // Shift right to check next bit
    }
    return count;
}

// Brian Kernighan's faster algorithm:
int count_bits_fast(int num) {
    int count = 0;
    while (num) {
        num &= (num - 1);  // Clear the lowest set bit
        count++;
    }
    return count;
}
```

### 2. Check if Power of 2
```c
int is_power_of_2(int num) {
    return (num > 0) && ((num & (num - 1)) == 0);
}
```

### 3. Extract Bit Ranges
```c
// Extract 'num_bits' starting from 'start_bit'
int extract_bits(int num, int start_bit, int num_bits) {
    int mask = (1 << num_bits) - 1;  // Create mask with num_bits ones
    return (num >> start_bit) & mask;
}
```

## Index-to-Binary Conversion

When working with array indices in push_swap:

```c
void convert_index_to_binary(int index, int max_bits) {
    printf("Index %d in binary: ", index);
    
    // Print from most significant bit to least
    for (int bit = max_bits - 1; bit >= 0; bit--) {
        printf("%d", (index >> bit) & 1);
    }
    printf("\n");
}
```

## Advanced Patterns

### 1. Isolate Rightmost Set Bit
```c
int rightmost_bit = num & -num;
```

### 2. Turn Off Rightmost Set Bit
```c
num = num & (num - 1);
```

### 3. Create Masks
```c
int mask_n_bits = (1 << n) - 1;  // n ones: 111...1 (n times)
int mask_range = mask_n_bits << start_position;  // Shift to position
```

## Performance Benefits

Bitwise operations are among the fastest operations a CPU can perform:
- **Addition/Subtraction**: ~1-4 cycles
- **Multiplication/Division**: ~10-30 cycles  
- **Bitwise Operations**: ~1 cycle

For push_swap with large datasets, this speed difference is significant!

## Common Mistakes to Avoid

1. **Signed vs Unsigned**: Be careful with negative numbers and right shifts
2. **Operator Precedence**: Use parentheses: `(num >> bit) & 1` not `num >> bit & 1`
3. **Bit Position**: Remember bits are 0-indexed from the right
4. **Integer Overflow**: Shifting by more than 31 bits (on 32-bit systems) is undefined

## Testing Your Understanding

Try implementing these functions:

1. `get_max_bits(t_node *stack)` - Find maximum bits needed for any number in stack
2. `radix_sort_by_bit(t_node **a, t_node **b, int bit_pos)` - Sort by one bit position
3. `binary_to_decimal(char *binary_str)` - Convert binary string to number
4. `print_stack_binary(t_node *stack)` - Print all stack values in binary

## Files in This Tutorial

- `bitmasking_tutorial.c` - Comprehensive standalone tutorial
- `bitmasking_demo.c` - Push_swap context demonstrations  
- `convert_to_binary.c` - Practical bitmasking functions for push_swap
- `push_swap.h` - Updated header with bitmasking function declarations
- `Makefile` - Easy compilation and testing

## Running the Examples

```bash
# Build and run comprehensive tutorial
make tutorial
./bitmasking_tutorial

# Build and run push_swap context demo
make demo  
./bitmasking_demo

# Clean up
make clean
```

## Next Steps

1. Study the tutorial output carefully
2. Implement radix sort using these bitmasking techniques
3. Test with different input sizes to see performance improvements
4. Experiment with different bit manipulation patterns

Remember: Bitmasking might seem complex at first, but it's one of the most powerful techniques in programming. Master it, and you'll have a significant advantage in algorithm implementation and optimization!