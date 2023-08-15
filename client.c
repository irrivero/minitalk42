/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:23:41 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/15 17:41:41 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_binary(char *binary, int bit)
{
	int	i;

	i = 0;
	while (binary[i])
	{
		if (binary[i] == '0')
			kill(bit, SIGUSR2);
		else if (binary[i] == '1')
			kill(bit, SIGUSR1);
		usleep(5000);
		i++;
	}
}

void	send_char(int pid)
{
	int		i;
	int		x;
	char	*binary;
	char	*pid1;

	i = 0;
	pid1 = ft_itoa_pid(getpid());
	while (pid1[i])
	{
		binary = ft_to_binary(pid1[i]);
		x = 0;
		while (binary[x])
		{
			if (binary[x] == '0')
				kill(pid, SIGUSR2);
			else if (binary[x] == '1')
				kill(pid, SIGUSR1);
			usleep(1000);
			x++;
		}
		free(binary);
		i++;
	}
	free(pid1);
}

void	send_string(int signal)
{
	if (signal == SIGUSR1)
	{
		write(1, "Message received by server\n", 27);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		len;
	char	*bin;

	i = 0;
	signal(SIGUSR1, send_string);
	if (argc == 3)
	{
		send_char(ft_atoi(argv[1]));
		len = ft_strlen(argv[2]);
		while (len >= i)
		{
			bin = ft_to_binary(argv[2][i]);
			send_binary(bin, ft_atoi(argv[1]));
			free(bin);
			i++;
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
