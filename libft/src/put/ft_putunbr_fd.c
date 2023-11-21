/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:19:22 by msloot            #+#    #+#             */
/*   Updated: 2023/11/20 21:58:52 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline ssize_t	ft_putunbr_fd(size_t n, int fd)
{
	return (ft_putunbr_base_fd(n, &(t_base){B10, B10_LEN}, fd));
}
