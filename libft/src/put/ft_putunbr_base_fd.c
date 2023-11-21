/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:55:10 by msloot            #+#    #+#             */
/*   Updated: 2023/11/20 21:57:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putunbr_base_fd(size_t n, const t_base *b, int fd)
{
	char	*str;
	size_t	n_len;
	ssize_t	ret;

	n_len = ft_unbrlen_base(n, b->len);
	str = (char *)malloc(sizeof(char) * (n_len + 1));
	if (!str)
		return (-2);
	ft_unbr_convert_base(str, n, n_len, b);
	ret = write(fd, str, n_len);
	free(str);
	return (ret);
}
