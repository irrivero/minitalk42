/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:23:41 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/15 11:00:18 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t		pid;
	const char	*str;
	
	if (argc != 3)
	{
		ft_printf("Usage: %s [Server PID] [Message]\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_string(pid, str);
	void	*arg;
}

void	send_bit(pid_t pid, int bit)
{
	if (bit)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	usleep(100);
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		send_bit(pid, (c >> i) & 1);
		i++;
	}
}

void	send_string(pid_t pid, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}