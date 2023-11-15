/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:19:22 by msloot            #+#    #+#             */
/*   Updated: 2023/11/15 13:18:23 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

ssize_t	ft_putnbr_fd(int n, int fd)
{
	char	str[11];
	size_t	len;

	len = ft_intlen(n);
	n_cpy(str, n, len);
	return (ft_putstr_fd(str, fd));
}
