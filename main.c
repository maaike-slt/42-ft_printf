/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:09:08 by msloot            #+#    #+#             */
/*   Updated: 2023/11/18 18:04:22 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	main(void)
{
	// ft_printf("%c\t%s\t%d\t%x\t%X\t%%\t%z\n", 'a', "Hello", 42, 42, 42);
	// ft_printf("%c\n", 'a');
	// ft_printf("%s\n", "Hello %");
	// ft_printf("%d %i\n", 42, 42);
	// ft_printf("%x %X\n", 42, 42);
	ft_printf("%d\n", ft_printf("%d", 0));
	return (0);
}
