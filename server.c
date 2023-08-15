/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:23:51 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/15 11:01:08 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_received_message[4096];
int		g_received_bit = 0;

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	setup_signals();
	while (1)
	{
		pause();
	}
	return (0);
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		g_received_message[g_received_bit / 8] &= ~(1 << (7 - (g_received_bit % 8)));
	else if (signal == SIGUSR2)
		g_received_message[g_received_bit / 8] |= (1 << (7 - (g_received_bit % 8)));
	g_received_bit++;
	if (g_received_bit % 8 == 0 && g_received_message[g_received_bit / 8] == '\0')
	{
		ft_printf("Received message: %s\n", g_received_message);
		kill(getpid(), SIGUSR1);
		g_received_bit = 0;
		ft_memset(g_received_message, 0, 4096);
	}
}

void	setup_signals(void)
{
	struct sigaction sa;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}
