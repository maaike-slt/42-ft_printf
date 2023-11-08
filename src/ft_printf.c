/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:06:28 by msloot            #+#    #+#             */
/*   Updated: 2023/11/08 18:41:41 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_input_iter(const char *input, va_list args)
{
	size_t	i;

	(void)args;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
			write(1, "!", 1);
		else
			write (1, &input[i], 1);
		i++;
	}
	// loop char by char
	// if char == '%' print hello
	// else putchar the char
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		ret;

	va_start(args, input);
	ret = ft_input_iter(input, args);
	va_end(args);
	return (ret);
}
