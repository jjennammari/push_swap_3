# Bitmasking Tutorial for Push_Swap

This repository now includes a comprehensive bitmasking education package to help you understand and master bitwise operations, particularly in the context of the push_swap project.

## 📚 What You'll Learn

- **Fundamental bitwise operations**: AND, OR, XOR, NOT, left/right shifts
- **Practical bitmasking techniques**: Set, clear, toggle, and check bits
- **Binary number manipulation**: Convert numbers to binary, extract bit ranges
- **Optimization patterns**: Fast bit counting, power-of-2 detection
- **Radix sort implementation**: Using bitmasking for efficient sorting
- **Real-world applications**: How bitmasking improves algorithm performance

## 🎯 Files Overview

### Core Tutorial Files
- **`bitmasking_tutorial.c`** - Comprehensive standalone tutorial with examples
- **`bitmasking_demo.c`** - Push_swap context demonstrations using actual stack operations
- **`bitmasking_exercises.c`** - Practice exercises with solutions (commented out)
- **`BITMASKING_GUIDE.md`** - Detailed written guide and reference

### Supporting Files
- **`convert_to_binary.c`** - Practical bitmasking functions for push_swap
- **`push_swap.h`** - Updated header with bitmasking function declarations
- **`error_minimal.c`** - Minimal error handling for demos
- **`Makefile`** - Easy compilation and testing

## 🚀 Quick Start

### 1. Build and Run the Tutorial
```bash
make tutorial
./bitmasking_tutorial
```

### 2. Try the Push_Swap Context Demo
```bash
make demo
./bitmasking_demo
```

### 3. Practice with Exercises
```bash
make exercises
./bitmasking_exercises
```

### 4. See All Available Options
```bash
make help
```

## 🔧 Makefile Targets

| Target | Description |
|--------|-------------|
| `tutorial` | Build standalone bitmasking tutorial |
| `demo` | Build push_swap context demo |
| `exercises` | Build practice exercises |
| `test_tutorial` | Build and run tutorial |
| `test_demo` | Build and run demo |
| `test_exercises` | Build and run exercises |
| `all` | Build everything |
| `clean` | Remove compiled files |
| `help` | Show all available targets |

## 📖 Learning Path

### Beginner: Start Here
1. Read `BITMASKING_GUIDE.md` for conceptual understanding
2. Run `./bitmasking_tutorial` to see comprehensive examples
3. Practice with `./bitmasking_exercises`

### Intermediate: Apply to Push_Swap
1. Run `./bitmasking_demo` to see push_swap specific examples
2. Study the radix sort implementation patterns
3. Integrate bitmasking functions into your push_swap project

### Advanced: Optimization
1. Implement radix sort using the provided bitmasking functions
2. Optimize your push_swap algorithm with bit manipulation
3. Experiment with advanced patterns like bit counting algorithms

## 🧠 Key Concepts Covered

### Basic Operations
```c
// Check if bit n is set
(num >> n) & 1

// Set bit n
num |= (1 << n)

// Clear bit n
num &= ~(1 << n)

// Toggle bit n
num ^= (1 << n)
```

### Radix Sort with Bitmasking
```c
// Extract bit at position for sorting
int bit_value = (number >> bit_position) & 1;

// Process each bit position
for (int bit = 0; bit < max_bits; bit++) {
    // Separate numbers based on bit value
    // Use push_swap operations: pb, pa, ra, rb
}
```

### Optimization Patterns
```c
// Fast power-of-2 check
(num > 0) && ((num & (num - 1)) == 0)

// Fast bit counting (Brian Kernighan's algorithm)
while (num) {
    num &= (num - 1);  // Clear lowest set bit
    count++;
}

// Isolate rightmost set bit
rightmost_bit = num & -num;
```

## 💡 How This Helps Your Push_Swap

1. **Radix Sort Implementation**: The most efficient sorting algorithm for push_swap
2. **Index Optimization**: Convert array indices to binary for better processing
3. **Performance**: Bitwise operations are among the fastest CPU operations
4. **Understanding**: Deep comprehension of how computers handle numbers

## 🔍 Example Output Preview

The tutorial demonstrates:
- Converting numbers like 42 to binary: `0010 1010`
- Extracting specific bits for radix sort processing
- Showing how each bit position affects sorting decisions
- Performance comparisons between different approaches

## 📝 Practice Exercises

The exercises include:
1. Power of 2 detection
2. Bit counting algorithms
3. Bit range extraction
4. Radix sort helpers
5. Optimization patterns
6. Advanced bit manipulation

## 🎓 Next Steps

After mastering these concepts:
1. Implement radix sort in your push_swap project
2. Use bitmasking for array index management
3. Optimize your sorting algorithm performance
4. Apply these techniques to other programming challenges

## 🔧 Technical Requirements

- GCC compiler with C99 support
- Make utility
- Standard C libraries (stdlib.h, unistd.h, limits.h)

## 🐛 Troubleshooting

If you encounter compilation errors:
1. Run `make clean` first
2. Ensure all header files are present
3. Check that GCC supports the `-std=c99` flag
4. Try `make safe` to build only error-free components

## 📚 Additional Resources

- **Binary Number System**: Understanding base-2 representation
- **Two's Complement**: How negative numbers are stored
- **Bit Manipulation Tricks**: Advanced optimization techniques
- **Algorithm Complexity**: Understanding O(n log n) vs O(d × n) for radix sort

---

Happy learning! Master bitmasking and take your push_swap implementation to the next level! 🚀