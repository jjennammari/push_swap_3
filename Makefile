# Makefile for Push_swap Bitmasking Tutorial
# ==========================================

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
NAME = push_swap

# Source files needed for basic functionality
CORE_SRCS = create_stack.c stack_helper.c array_helper.c convert_to_binary.c
ERROR_SRCS = error_minimal.c

# Tutorial and demo files
TUTORIAL_SRC = bitmasking_tutorial.c
DEMO_SRC = bitmasking_demo.c
EXERCISES_SRC = bitmasking_exercises.c

# Objects
CORE_OBJS = $(CORE_SRCS:.c=.o)
ERROR_OBJS = $(ERROR_SRCS:.c=.o)

# Targets
all: tutorial demo exercises

# Build the standalone bitmasking tutorial
tutorial: $(TUTORIAL_SRC)
	@echo "Building bitmasking tutorial..."
	$(CC) $(CFLAGS) -o bitmasking_tutorial $(TUTORIAL_SRC)
	@echo "Tutorial built! Run with: ./bitmasking_tutorial"

# Build the push_swap context demo (requires fixing some compilation issues first)
demo: fix_errors $(CORE_OBJS) $(ERROR_OBJS) $(DEMO_SRC)
	@echo "Building bitmasking demo..."
	$(CC) $(CFLAGS) -o bitmasking_demo $(CORE_OBJS) $(ERROR_OBJS) $(DEMO_SRC)
	@echo "Demo built! Run with: ./bitmasking_demo"

# Fix compilation errors in existing files
fix_errors:
	@echo "Fixing compilation errors..."
	@# Fix reverse_rotate.c include
	@sed -i 's/#include "push_swap"/#include "push_swap.h"/' reverse_rotate.c 2>/dev/null || true
	@# Fix rotate.c include  
	@sed -i 's/#include "push_swap"/#include "push_swap.h"/' rotate.c 2>/dev/null || true

# Individual object files
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

# Test the tutorial
test_tutorial: tutorial
	@echo "Running bitmasking tutorial..."
	./bitmasking_tutorial

# Test the demo (requires working stack functions)
test_demo: demo
	@echo "Running bitmasking demo..."
	./bitmasking_demo

# Build the practice exercises
exercises: $(EXERCISES_SRC)
	@echo "Building bitmasking exercises..."
	$(CC) $(CFLAGS) -o bitmasking_exercises $(EXERCISES_SRC)
	@echo "Exercises built! Run with: ./bitmasking_exercises"

# Test the exercises
test_exercises: exercises
	@echo "Running bitmasking exercises..."
	./bitmasking_exercises

# Clean up
clean:
	rm -f $(CORE_OBJS) $(ERROR_OBJS) bitmasking_tutorial bitmasking_demo bitmasking_exercises

fclean: clean
	rm -f $(NAME)

re: fclean all

# Helpful targets
help:
	@echo "Available targets:"
	@echo "  tutorial      - Build standalone bitmasking tutorial"
	@echo "  demo          - Build push_swap context demo"
	@echo "  exercises     - Build practice exercises"
	@echo "  test_tutorial - Build and run tutorial"
	@echo "  test_demo     - Build and run demo"
	@echo "  test_exercises- Build and run exercises"
	@echo "  clean         - Remove object files and executables"
	@echo "  help          - Show this help message"

# Just build what we can without errors
safe: tutorial exercises
	@echo "Built safe targets (tutorial and exercises)"

.PHONY: all tutorial demo exercises test_tutorial test_demo test_exercises clean fclean re help fix_errors safe