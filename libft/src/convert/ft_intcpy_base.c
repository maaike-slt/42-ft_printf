/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcpy_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:10:20 by msloot            #+#    #+#             */
/*   Updated: 2023/11/15 18:26:27 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// no check over base matching base_len for optimization reasons
// the base_len is not needed if we calculate it inside the function using -
// ft_intlen_base, but all len calculation should be optimized
char	*ft_intcpy_base(char *dst, long n, const char *base, size_t base_len)
{
	size_t	len;

	len = ft_intlen_base(n, base_len);
	dst[len] = '\0';
	len--;
	if (n == 0)
	{
		dst[0] = base[0];
		return (dst);
	}
	if (n < 0)
	{
		n = -n;
		dst[0] = '-';
	}
	while (n != 0)
	{
		dst[len] = base[n % base_len];
		n /= base_len;
		len--;
	}
	return (dst);
}
