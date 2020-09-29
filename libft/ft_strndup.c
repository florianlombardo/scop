/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:44:09 by jemagnie          #+#    #+#             */
/*   Updated: 2020/09/29 19:08:39 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;

	if (!(s2 = ft_strnew(n)))
		return (NULL);
	ft_memcpy(s2, s1, n);
	return (s2);
}
