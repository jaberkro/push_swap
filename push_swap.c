/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 15:30:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/24 23:43:41 by jaberkro      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

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

int	parse_input(int argc, char **argv)//, t_double_list *stack_a) // parsing 
{
	char	*inputstring;
	char	**separated_inputs;
	int		i;

	i = 1;
	inputstring = ft_calloc(1, '\0');
	while (i < argc)
	{
		inputstring = ft_strjoin(inputstring, argv[i]);
		inputstring = ft_strjoin(inputstring, " ");
		i++;
	}
	separated_inputs = ft_split(inputstring, ' ');
	return (check_and_convert_input(separated_inputs));//, stack_a));	
}

int main(int argc, char **argv)
{
	//t_double_list 	stack_a;
	int				error;
	
	if (argc == 1)
	 	return (0);
	error = parse_input(argc, argv);//, &stack_a); // error_handling
	if (error == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
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