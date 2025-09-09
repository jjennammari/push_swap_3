#include "push_swap.h"

void	reverse_rotate(t_node **top)
{
	t_node	*n2;
	t_node	*second_last;
	t_node	*last;

	if (!top || !*top || !(*top)->next)
		return ;
	n2 = *top->next;
	second_last = n2;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	last->next = n2;
	second_last->next = NULL;
	*top = last;
}

void	reverse_rotate_a(t_node **a)
{
	reverse_rotate(&a);
	write (1, "rra\n", 4);
}

void	reverse_rotate_b(t_node **a)
{
	reverse_rotate(&b);
	write (1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_node **a, t_node **b)
{
	reverse_rotate(&a);
	reverse_rotate(&b);
	write (1, "rrr\n", 4);
}
