/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:06:28 by msloot            #+#    #+#             */
/*   Updated: 2023/11/22 20:28:07 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_raw(const char *input, size_t i)
{
	ssize_t	ret1;
	ssize_t	ret2;

	ret1 = ft_putchar('%');
	if (ret1 < 0)
		return (ret1);
	ret2 = ft_putchar(input[i + 1]);
	if (ret2 < 0)
		return (ret2);
	return (ret1 + ret2);
}

static ssize_t	ft_convert_p(va_list args)
{
	size_t	p;
	ssize_t	ret1;
	ssize_t	ret2;

	p = va_arg(args, size_t);
	if (p == 0)
		return (ft_putstr("(nil)"));
	ret1 = ft_putstr("0x");
	if (ret1 < 0)
		return (ret1);
	ret2 = ft_putunbr_base(p, &(t_base){B16, B16_LEN});
	if (ret2 < 0)
		return (ret2);
	return (ret1 + ret2);
}

static ssize_t	ft_convert(const char *input, size_t i, va_list args)
{
	if (input[i + 1] == '\0')
		return (-1);
	if (input[i + 1] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (input[i + 1] == 'i' || input[i + 1] == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (input[i + 1] == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (input[i + 1] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (input[i + 1] == 'x')
		return (ft_putnbr_base(
				va_arg(args, unsigned int), &(t_base){B16, B16_LEN}));
	else if (input[i + 1] == 'X')
		return (ft_putnbr_base(
				va_arg(args, unsigned int), &(t_base){B16X, B16_LEN}));
	else if (input[i + 1] == 'p')
		return (ft_convert_p(args));
	else if (input[i + 1] == '%')
		return (ft_putchar('%'));
	else
		return (ft_raw(input, i));
}

static ssize_t	ft_input_iter(const char *input, va_list args)
{
	size_t	i;
	ssize_t	ret;
	ssize_t	current;

	ret = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
		{
			current = ft_convert(input, i, args);
			i++;
		}
		else
			current = ft_putchar(input[i]);
		if (current < 0)
			return (current);
		ret += current;
		i++;
	}
	return (ret);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		ret;

	if (!input)
		return (-1);
	va_start(args, input);
	ret = ft_input_iter(input, args);
	va_end(args);
	return (ret);
}
