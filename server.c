/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:23:51 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/15 17:35:09 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_int = 0;

void	receive_pid(int n, int l)
{
	static int	res = 0;

	if (n >= 0)
	{
		res *= 10;
		res += (n - '0');
	}
	if (l)
	{
		kill (res, SIGUSR1);
		g_int = 1;
		res = 0;
	}
}

void	signal_handler(int signum)
{
	static int	i = 0;
	static int	str = 0;

	if (signum == SIGUSR1)
		str = str | 1;
	if (++i == 8)
	{
		if (str == 27)
			receive_pid(-1, 1);
		else if (g_int)
			write(1, &str, 1);
		else if (!g_int)
			receive_pid(str, 0);
		if (!str)
		{
			g_int = 0;
			write(1, "\n", 1);
		}
		str = 0;
		i = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause ();
	return (0);
}
