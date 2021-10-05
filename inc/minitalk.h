/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 22:40:19 by tgildero          #+#    #+#             */
/*   Updated: 2021/10/05 23:35:06 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H 

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "../libft/libft.h"

typedef struct s_mes
{
	unsigned int	counter;
	unsigned int	value;
	char			*data;
	int				exit;
}				t_mes;

t_mes		g_mes;

void			print_error(char *mes);
long int		ft_pow(long int x, unsigned int n);

#endif
