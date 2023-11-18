/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:09:08 by msloot            #+#    #+#             */
/*   Updated: 2023/11/18 17:34:54 by msloot           ###   ########.fr       */
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
	ft_printf("1, 2, 3, -d test, testing, 0.4s sound, 1, 2, 3xp, sound, -*dtest");
	return (0);
}
