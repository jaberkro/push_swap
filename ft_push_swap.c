/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_swap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaberkro <jaberkro@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 15:30:51 by jaberkro      #+#    #+#                 */
/*   Updated: 2022/02/14 20:43:48 by jaberkro      ########   odam.nl         */
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

int	*check_and_convert_input(char *inputstring)
{
	char	**separated_inputs;
	int		*inputs;
	int		len;
	int		i;

	len = 0;
	i = 0;
	separated_inputs = ft_split(inputstring, ' ');
	while (separated_inputs[len] != '\0')
		len++;
	inputs = malloc(4 * len);
	if (inputs == NULL)
		return (NULL);
	while (len > 0)
	{
		inputs[len - 1] = ft_atoi(separated_inputs[len - 1]);
		len--;
	}
	return (inputs);
}

int	*read_input(int argc, char **argv)
{
	char	*inputstring;
	int		*inputs;
	int		i;

	i = 1;
	inputstring = ft_calloc(1, '\0');
	while (i < argc)
	{
		inputstring = ft_strjoin(inputstring, argv[i]);
		inputstring = ft_strjoin(inputstring, " ");
		i++;
	}
	inputs = check_and_convert_input(inputstring);
	free(inputstring);
	return (inputs);
}

int main(int argc, char **argv)
{
	int		len;
	int		*inputs;
	
	len = 0;
	if (argc == 1)
		return (0);
	write(1, "hi from push_swap\n", 18);
	inputs = read_input(argc, argv);
	if (inputs == NULL)
		return (0);

	int i = 0;
	while (inputs[i])
	{
		ft_printf("<%d>\n", inputs[i]);
		i++;
	}
	//ft_printf("<%d>\n", inputs[2]);
	//ft_printf("<%d>\n", inputs[3]);
	// if (!error_check(inputs))
	// {
	// 	free(inputs);
	// 	write(1, "Error\n", 6);
	// 	return (1);
	// }
	return (0);
}
