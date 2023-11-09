/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:31:06 by msloot            #+#    #+#             */
/*   Updated: 2023/10/29 13:09:01 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_len(int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*n_cpy(char *dst, long n, size_t len)
{
	dst[len] = '\0';
	len--;
	if (n == 0)
	{
		dst[0] = '0';
		return (dst);
	}
	if (n < 0)
	{
		n = -n;
		dst[0] = '-';
	}
	while (n != 0)
	{
		dst[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (dst);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	len;

	len = n_len(n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	return (n_cpy(ret, n, len));
}

/*
#include <stdio.h>
#include <limits.h>

static void	test(int n)
{
	printf("%d:\t'%s'\n", n, ft_itoa(n));
}

int	main(void)
{
	test(0);
	test(1);
	test(-1);
	test(42);
	test(-42);
	test(4242);
	test(-4242);
	test(INT_MAX);
	test(INT_MIN);
}
*/
