/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 12:31:06 by msloot            #+#    #+#             */
/*   Updated: 2023/11/20 21:39:26 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ntoa_base(ssize_t n, const t_base *b)
{
	char	*ret;
	size_t	n_len;

	n_len = ft_nbrlen_base(n, b->len);
	ret = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!ret)
		return (NULL);
	return (ft_nbr_convert_base(ret, n, n_len, b));
}
