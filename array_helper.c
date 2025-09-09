#include "push_swap.h"
#include <limits.h>

void	create_array(int *arr, char **argv, int size)
{
	int	nbr;
	int	i;

	i = 0;
	while (i < size)
	{
        if (!check_if_number(argv[i + 1]))
            error_array(arr, size);
        nbr = ft_atol(argv[i + 1]);
        if ((nbr < INT_MIN) || (nbr > INT_MAX))
            error_array(arr, size);
        if (check_if_double(arr, (int)nbr))
            error_array(arr, size);
		arr[i] = (int)nbr;
		i++;
	}
	sort_array(arr, size);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < (size - 1))
	{
		j = (i + 1);
		temp = 0;
		while (j < size)
		{
			if (arr[j] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				j = i;
			}
			j++;
		}
		i++;
	}
}

int	get_index(int *arr, char **argv, int size)
{
	int	i;

	i = 0;
	while (arr[i] != (int)ft_atol(argv[size]))
		i++;
	return (i);
}
