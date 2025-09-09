#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int	data;
	struct s_node	*next;
} t_node;

		/*\ create_stack.c \*/

void	create_stack(t_node **a, char **argv, int argc);
void	add_to_stack(t_node **top, int nbr);

		/*\ array_helper.c \*/

void    create_array(int *arr, char **argv, int size);
void    sort_array(int *arr, int size);
int 	get_index(int *arr, char **argv, int size);

		/*\ stack_helper.c \*/

int 	check_if_number(char *argv);
int		check_if_double(int *arr, int nbr);
long    ft_atol(char *str);
int		count_stack_size(t_node *a);

		/*\ error_exit.c \*/

void	error_int(t_node **a);
void    error_digit(t_node **a);
void    error_double(t_node **a);
void    error_malloc(t_node **a);
void    error_array(int *array, int size);

	/*\ stack operation functions \*/

void    push(t_node **dest, t_node **src);
void    push_a(t_node **a, t_node **b);
void    push_b(t_node **a, t_node **b);

void    reverse_rotate(t_node **top);
void    reverse_rotate_a(t_node **a);
void    reverse_rotate_b(t_node **a);
void    reverse_rotate_ab(t_node **a, t_node **b);

void    rotate(t_node **top);
void    rotate_a(t_node **a);
void    rotate_b(t_node **b);
void    rotate_ab(t_node **a, t_node **b);

void    swap(t_node **top);
void    swap_a(t_node **a);
void    swap_b(t_node **b);
void    swap_ab(t_node **a, t_node **b);

	/*\ bitmasking and binary conversion functions \*/

int     get_bit_count(int num);
int     get_max_bits(t_node *stack);
int     is_bit_set(int num, int bit_position);
void    number_to_binary_array(int num, int *binary_array, int array_size);
void    print_binary_representation(int num, int bits);
int     extract_bit(int num, int bit_position);
int     extract_bit_range(int num, int start_bit, int num_bits);
int     count_set_bits(int num);
int     count_set_bits_fast(int num);
int     is_power_of_2(int num);
int     find_lowest_set_bit(int num);
int     create_mask(int num_bits);
int     get_bit_digit(int num, int bit_position);
void    demonstrate_radix_bitmasking(t_node *stack);
void    convert_index_to_binary(int index, int max_bits);

#endif
