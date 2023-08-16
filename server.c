/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:23:51 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/16 17:01:14 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_int = 0;

/* responsible for receiving the PID (Process ID) of the client. It accumulates
the digits of the PID and forms a complete PID number. When the end of the PID
is detected (using flag 1), it sends a SIGUSR1 signal to the recieved PID and 
sets the g_int flag to indicate that the subsequent characters received are
part of the message*/
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

/* is the main signal handler for the  server. It gets triggered by SIGUSR1 and
SIGUSR2 signals. It accumulates the incoming bits (1 or 0)  to form a complete
character (8 bits). When a complete character is formed, it checks if it's the
special character 27(used for sending the PID), and if so, it triggers the 
received_pid function. Otherwise, it decodes the received character and writes
it to the standard output. It then resets the bit accumulator(str) and the
bit counter(i)*/
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

/*the entry point of the server progran, It starts  by printing the PID of the
server process. Then, it sets up signal handlers for SIGUSR1 and SIGUSR2 using 
signal(SIGUSR1, signal_handler) and signal(SIGUSR2, signal_handler). The 
program enters a loop using while(1) and waits for incoming signals using 
pause(). when a signal is received, it calls the signal_handler function*/
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
