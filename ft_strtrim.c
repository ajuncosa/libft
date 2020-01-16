/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajuncosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:57:14 by ajuncosa          #+#    #+#             */
/*   Updated: 2020/01/15 12:38:16 by ajuncosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_create_new(char *new, const char *s1, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start <= end)
	{
		new[i] = s1[start];
		start++;
		i++;
	}
	new[i] = '\0';
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*new;

	if (!s1)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]) && start < ft_strlen(s1))
		start++;
	if (start == ft_strlen(s1))
	{
		if (!(new = malloc(1)))
			return (0);
		new = "\0";
		return (new);
	}
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]))
		end--;
	if (!(new = malloc(sizeof(char) * (end - start + 2))))
		return (0);
	ft_create_new(new, s1, start, end);
	return (new);
}
