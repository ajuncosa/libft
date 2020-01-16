/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuncosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:07:17 by ajuncosa          #+#    #+#             */
/*   Updated: 2020/01/10 18:38:23 by ajuncosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*copy;

	if (!(copy = malloc((ft_strlen(s1) + 1))))
		return (0);
	i = 0;
	while (i <= ft_strlen(s1))
	{
		copy[i] = s1[i];
		i++;
	}
	return (copy);
}
