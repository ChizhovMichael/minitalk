/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 22:41:15 by tgildero          #+#    #+#             */
/*   Updated: 2021/09/29 22:41:17 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	usage_error(char *argv[])
{
	int	i;

	i = 1;
	if (argv[i])
	{
		ft_putstr_fd("./client: ", 1);
		while (argv[i])
		{
			ft_putstr_fd("\'", 1);
			ft_putstr_fd(argv[i], 1);
			ft_putstr_fd("\' ", 1);
			i++;
		}
		ft_putstr_fd("is not a ./client command.\n", 1);
	}
	print_error("usage: ./client [server_pid] [value]\n");
}

void	empty_act(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
}

void	send_act(int sig, siginfo_t *info, void *context)
{
	char	c;

	(void)sig;
	(void)context;
	c = *g_mes.data;
	if ((c >> g_mes.counter) & 0x01)
		if (kill(info->si_pid, SIGUSR1) < 0)
			print_error("Fatal error: kill\n");
	if (!((c >> g_mes.counter) & 0x01))
		if (kill(info->si_pid, SIGUSR2) < 0)
			print_error("Fatal error: kill\n");
	if (g_mes.counter == 0)
	{
		if (!c)
			exit(1);
		g_mes.data++;
		g_mes.counter = 7;
	}
	else
		g_mes.counter--;
}

int	main(int argc, char *argv[])
{
	struct sigaction	send;
	struct sigaction	empty;

	if (argc != 3)
		usage_error(argv);
	send.sa_sigaction = send_act;
	send.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &send, NULL) < 0)
		print_error("Fatal error: sigaction\n");
	empty.sa_sigaction = empty_act;
	empty.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR2, &empty, NULL) < 0)
		print_error("Fatal error: sigaction\n");
	g_mes.counter = 7;
	g_mes.data = argv[2];
	if (kill((pid_t)ft_atoi(argv[1]), SIGUSR1) < 0)
		print_error("Fatal error: kill\n");
	while (1)
		pause();
	return (0);
}
