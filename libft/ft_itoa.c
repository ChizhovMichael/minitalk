/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:02:41 by tgildero          #+#    #+#             */
/*   Updated: 2021/09/29 23:06:49 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_range(int n)
{
	int	size;

	size = 1;
	n /= 10;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	int		negative;
	char	*str;

	negative = 0;
	if (n < 0)
		negative = 1;
	size = ft_range(n);
	str = malloc(sizeof(char) * (size + negative) + 1);
	if (!str)
		return (NULL);
	if (negative)
		str[0] = '-';
	str[size + negative] = '\0';
	while (size--)
	{
		if (negative)
			str[size + negative] = -(n % 10) + '0';
		else
			str[size + negative] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
