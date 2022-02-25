/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 15:30:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/25 13:29:55 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "push_swap.h"

// int	error_check(char **inputs)
// {
// 	int	i;

// 	i = 0;
// 	while (i)
// }

int	check_and_convert_input(char **separated_inputs)
{
	int		*inputs;
	int		len;
	int		i;

	len = 0;
	while (separated_inputs[len] != '\0')
	{
		i = 0;
		while (separated_inputs[len][i])
		{
			if (ft_isdigit(separated_inputs[len][i]) == 0 && separated_inputs[len][i] != '-' && separated_inputs[len][i] != '+')
 				return (0);
			i++;
		}
		len++;
	}
	inputs = malloc(4 * len);
	if (inputs == NULL)
		return (0);
	while (len > 0)
	{
		inputs[len - 1] = ft_atoi(separated_inputs[len - 1]);
		len--;
	}
	return (1);
}

// int	*read_input(int argc, char **argv)
// {
// 	char	*inputstring;
// 	int		*inputs;
// 	int		i;

// 	i = 1;
// 	inputstring = ft_calloc(1, '\0');
// 	while (i < argc)
// 	{
// 		inputstring = ft_strjoin(inputstring, argv[i]);
// 		inputstring = ft_strjoin(inputstring, " ");
// 		i++;
// 	}
// 	inputs = check_and_convert_input(inputstring);
// 	free(inputstring);
// 	return (inputs);
// }

// int	check_and_convert_input(char *inputstring)//, t_double_list *stack_a)
// {
// 	char			to_convert[20];
// 	//unsigned int	converted;
// 	size_t			i;
// 	size_t			j;

// 	i = 0;
// 	while(i < ft_strlen(inputstring))
// 	{
// 		j = 0;
// 		while (inputstring[i] != ' ')
// 		{
// 			if (ft_isdigit(inputstring[i]) == 0 && inputstring[i] != '-' && inputstring[i] != '+')
// 				return (0);
// 			to_convert[j] = inputstring[i];
// 			i++;
// 			j++;
// 		}
// 		to_convert[0]  = '\0';
// 		i++;
// 	}
// 	return (1);

// }

int	*index_array(int *input_array)
{
	int	*output_array;

	return (output_array);
}

t_dlist	*make_stack(char **separated_inputs, int i)
{
	int		*input_array;
	t_dlist	*stack_a;

	input_array = malloc (4 * i);
	if (input_array == NULL)
		return (NULL);
	while (i > 0)
	{
		input_array[i - 1] = ft_atoi(separated_inputs[i - 1]);
		i--;
	}
	input_array = index_array(input_array);
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
			if (i != 0 && ft_isdigit(separated_inputs[len][i]) == 0)
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
	t_dlist	*stack_a;

	i = 1;
	inputstring = ft_calloc(1, '\0');
	while (i < argc)
	{
		inputstring = ft_strjoin(inputstring, argv[i]);
		inputstring = ft_strjoin(inputstring, " ");
		i++;
	}
	separated_inputs = ft_split(inputstring, ' ');
	i = error_check_and_array_len(separated_inputs);
	//free (inputstring);
	if (i == 0)
		//free separated_inputs (nested array)
		return (NULL);
	return(make_stack(separated_inputs, i));
}

int main(int argc, char **argv)
{
	t_dlist 	*stack_a;
	
	if (argc == 1)
	 	return (0);
	stack_a = parse_input(argc, argv);
	if (stack_a == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}

/*
Parse the input
- Make it all one string
- Use split to make separate parts
- Check every part and count how much we should malloc for the array
- Malloc the array
- Use atoi to fill the array
- Make a similar array that counts from 1 to the highest number in the array
- Put the array inputs in a stack
- Return the stack
*/



	// int		len;
	// int		*inputs;
	
	// len = 0;
	// if (argc == 1)
	// 	return (0);
	// write(1, "hi from push_swap\n", 18);
	// inputs = read_input(argc, argv);
	// if (inputs == NULL)
	// 	return (0);

	// int i = 0;
	// while (inputs[i])
	// {
	// 	ft_printf("<%d>\n", inputs[i]);
	// 	i++;
	// }
	//ft_printf("<%d>\n", inputs[2]);
	//ft_printf("<%d>\n", inputs[3]);
	// if (!error_check(inputs))
	// {
	// 	free(inputs);
	// 	write(1, "Error\n", 6);
	// 	return (1);
	// }


// atoi
// arr = MAX_LONG MAX_LONG MAX_LONG MAX_LONG smallest = 10
// arr2 = 2   3  1 4 bigest = 4 --> length of my list
// lst = 2->3->1->4
// out = 