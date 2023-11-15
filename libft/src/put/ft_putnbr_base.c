/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:55:10 by msloot            #+#    #+#             */
/*   Updated: 2023/11/15 13:18:09 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_valid_base(const char *base)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(base);
	if (len < 2)
		return (false);
	i = 0;
	while (base[i] != '\0')
	{
		if (i + 1 < len && ft_is_in(base + i + 1, base[i]))
			return (false);
		if (base[i] == '-' || base[i] == '+')
			return (false);
		i++;
	}
	return (true);
}

void	ft_putnbr_base(int n, const char *base)
{
	long	nb;
	int		len;

	if (!is_valid_base(base))
		return ;
	if (n == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	nb = (long)n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	len = ft_strlen(base);
	if (nb / len != 0)
		ft_putnbr_base(nb / len, base);
	ft_putchar(base[nb % len]);
}