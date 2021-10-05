/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 22:41:22 by tgildero          #+#    #+#             */
/*   Updated: 2021/09/29 22:41:23 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	print_char(int c)
{
	if (g_mes.value == 0)
		write(1, "\n", 1);
	else
		write(1, &c, 1);
	g_mes.counter = 7;
	g_mes.value = 0;
}

long int	ft_pow(long int x, unsigned int n)
{
	if (n == 0)
		return (1);
	else if (n == 1)
		return (x);
	else if (n % 2 == 0)
		return (ft_pow(x * x, n / 2));
	else
		return (ft_pow(x * x, n / 2) * x);
}

void	one_act(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (g_mes.counter == 7)
	{
		if (kill(info->si_pid, SIGUSR1) < 0)
			print_error("Fatal error: kill\n");
		return ;
	}
	g_mes.value += ft_pow(2, g_mes.counter);
	if (g_mes.counter == 0)
		print_char(g_mes.value);
	else
		g_mes.counter--;
	if (kill(info->si_pid, SIGUSR1) < 0)
		print_error("Fatal error: kill\n");
}

void	zero_act(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (g_mes.counter == 0)
		print_char(g_mes.value);
	else
		g_mes.counter--;
	if (kill(info->si_pid, SIGUSR1) < 0)
		print_error("Fatal error: kill\n");
}

int	main(int argc, char const *argv[])
{
	struct sigaction	one;
	struct sigaction	zero;

	(void)argc;
	(void)argv;
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 2);
	one.sa_sigaction = one_act;
	one.sa_flags = SA_SIGINFO;
	zero.sa_sigaction = zero_act;
	zero.sa_flags = SA_SIGINFO;
	g_mes.counter = 7;
	g_mes.value = 0;
	if (sigaction(SIGUSR1, &one, NULL) < 0)
		print_error("Fatal error: sigaction\n");
	if (sigaction(SIGUSR2, &zero, NULL) < 0)
		print_error("Fatal error: sigaction\n");
	while (1)
		pause();
	return (0);
}
