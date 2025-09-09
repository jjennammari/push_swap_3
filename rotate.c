#include "push_swap.h"

void	rotate(t_node **top)
{
	t_node	*n1;
	t_node	*n2;
	t_node	*last;

	if (!top || !*top || !(*top)->next)
		return ;
	n1 = *top;
	n2 = n1->next;
	last = n2;
	while (last->next != NULL)
		last = last->next;
	n1->next = NULL;
	last->next = n1;
	*top = n2;
}

void	rotate_a(t_node **a)
{
	rotate (&a);
	write (1, "ra\n", 3);
}

void	rotate_b(t_node **b)
{
	rotate (&b);
	write (1, "rb\n", 3);
}

void	rotate_ab(t_node **a, t_node **b)
{
	rotate (&a);
	rotate (&b);
	write (1, "rr\n", 3);
}
