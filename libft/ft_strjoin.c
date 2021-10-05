/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:18:13 by tgildero          #+#    #+#             */
/*   Updated: 2021/09/29 23:00:03 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*start;

	if (!s1 && !s2)
		return (0);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (0);
	start = result;
	if (start)
	{
		if (s1)
		{
			while (*s1)
				*result++ = *s1++;
		}
		if (s2)
		{
			while (*s2)
				*result++ = *s2++;
		}
		*result = '\0';
	}
	return (start);
}
