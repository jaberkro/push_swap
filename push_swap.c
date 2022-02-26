/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 15:30:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/26 16:17:55 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void	print_list(t_dlist *to_print)
{
	while (to_print)
	{
		ft_printf("<%d>", to_print->content);
		to_print = to_print->next;
	}
	ft_printf("\n");
}

t_dlist *make_stack(long *input_array, int len)
{
	t_dlist *stack_a;
	t_dlist *new;

	stack_a = ft_dlstnew((int)input_array[len - 1]);
	len--;
	while (len - 1 >= 0)
	{
		new = ft_dlstnew((int)input_array[len - 1]);
		if (new == NULL)
		{
			free (input_array);
			ft_dlstclear(&stack_a);
			return (NULL);
		}
		ft_dlstadd_front(&stack_a, new);
		len--;
	}
	return(stack_a);
}

long	*index_array(long *input_array, int len)
{
	int		i;
	int		val;
	long	lowest_value;
	long	lowest_loc;
	long	last_lowest;
	long	*output_array;

	output_array = malloc (sizeof(long *) * len);
	if (output_array == NULL)
	{
		free(input_array);
		return (NULL);
	}
	val = 1;
	last_lowest = -2147483649;
	while (val < len + 1)
	{	
		i = 0;
		lowest_value = 2147483648;
		lowest_loc = -1;
		while (i < len)
		{
			if (input_array[i] < lowest_value)
			{
				lowest_value = input_array[i];
				lowest_loc = i;
			}
			i++;
		}
		if (lowest_value == last_lowest)
		{
			free(output_array);
			free(input_array);
			return (NULL);
		}
		last_lowest = lowest_value;
		output_array[lowest_loc] = val;
		input_array[lowest_loc] = 2147483648;
		val++;
	}
	free(input_array);
	return (output_array);
}

t_dlist	*make_array(char **separated_inputs, int len)
{
	long	*input_array;
	long	value;
	int		i;
	t_dlist	*stack_a;

	i = len;
	input_array = malloc (sizeof(long *) * i);
	if (input_array == NULL)
		return (NULL);
	while (i > 0)
	{
		value = ft_atol(separated_inputs[i - 1]);
		if (value < -2147483648 || value > 2147483647)
		{
			free(input_array);
			return (NULL);
		}
		input_array[i - 1] = value; 
		i--;
	}
	input_array = index_array(input_array, len);
	if (input_array == NULL)
		return (NULL);
	stack_a = make_stack(input_array, len);
	free(input_array);
	return (stack_a);
}

int	error_check_and_array_len(char **separated_inputs)
{
	int	i;
	int	len;

	len = 0;
	while (separated_inputs[len] != '\0')
	{
		i = 0;
		while (separated_inputs[len][i])
		{
			if (ft_isdigit(separated_inputs[len][i]) == 0 && (i != 0 || \
				(i == 0 && separated_inputs[len][i] != '-' && \
				separated_inputs[len][i] != '+')))
				return (0);
			i++;
		}
		len++;
	}
	return (len);
}

t_dlist	*parse_input(int argc, char **argv)
{
	int		i;
	char	*inputstring;
	char	**separated_inputs;
	char	*tmp;
	t_dlist	*stack_a;

	i = 1;
	inputstring = ft_calloc(1, 1);
	while (i < argc)
	{
		tmp = inputstring;
		inputstring = ft_strjoin(inputstring, argv[i]);
		if (tmp)
			free(tmp);
		if (inputstring == NULL)
			return (NULL);
		tmp = inputstring;
		inputstring = ft_strjoin(inputstring, " ");
		if (inputstring == NULL)
			return (NULL);
		if (tmp)
			free(tmp);
		i++;
	}
	separated_inputs = ft_split(inputstring, ' ');
	i = error_check_and_array_len(separated_inputs);
	free (inputstring);
	if (i == 0)
	{
		while (separated_inputs[i])
		{
			free(separated_inputs[i]);
			i++;
		}
		free(separated_inputs);
		return (NULL);
	}
	stack_a = make_array(separated_inputs, i);
	while (i > 0)
	{
		free(separated_inputs[i - 1]);
		i--;
	}
	free (separated_inputs);
	return (stack_a);
}

int main(int argc, char **argv)
{
	t_dlist *stack_a;
	
	if (argc == 1)
	 	return (0);
	stack_a = parse_input(argc, argv);
	if (stack_a == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_list(stack_a);
	ft_dlstclear(&stack_a);
	system("leaks push_swap");
	return (0);
}

/*
Parse the input
- Make it all one string
- Use split to make separate parts
- Check every part and count how much we should malloc for the array
- Malloc the array
- Use atoi to fill the array
- Make a similar array that counts from 1 to the highest number in the array // index it
- Put the array inputs in a stack
- Return the stack
*/
