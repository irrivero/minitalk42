/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:23:41 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/16 16:51:09 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* sends a binary sequence (represented by a string of 0s and 1s) to the server
using UNIX signals. It interprets each 0 as a SIGUSR2 and each 1 as a SIGUSR1 
signal. The function loops through the binary string and sends the appropriate
signal for each character in the string, with a delay between each signal.
*/
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

/* sends the PID(Process ID) of the client process to the server. It converts
the PID into binary representation using ft_to_binary and then sends the 
corresponding signals (SIGUSR1 for 1 and SIGUSR2 for 0) to the server. This
allows the server to recognize the client that sent the message.*/
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

/* this function is a signal handler that gets triggered when the client
receives a SIGUSR1 signal. It simply prints a message to indicate that
the server has received the message*/
void	send_string(int signal)
{
	if (signal == SIGUSR1)
		write(1, "Message received by server\n", 27);
}

/* this is the entry point of the program. It first sets up the signal handler
using signal(SIGUSR1, send_string). Then it checks the command line arguments 
to ensure the correct number of arguments (server PID and message) are 
provided. If the arguments are valid, it sends the PID using send_char and then
for each character in the message, it converts the character to its binary 
representation using ft_to_binary and sends the binary signals using 
send_binary.*/
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
			bin = ft_to_binary(argv[2][i++]);
			send_binary(bin, ft_atoi(argv[1]));
			free(bin);
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
