/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:33:44 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/16 16:24:47 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// prints an integer to the standard output by recursively printing each digit
void	ft_putnbr(int n)
{
	char	c;

	if (n >= 0 && n <= 9)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		c = (n % 10) + 48;
		write(1, &c, 1);
	}
}

// converts an integer to a string, adding 27 ASCII at the end
char	*ft_itoa_pid(int n)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	y = n;
	while (y)
	{
		y /= 10;
		i++;
	}
	str = malloc(i + 2);
	str[i + 1] = '\0';
	str[i] = 27;
	while (--i >= 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

// converts an unsigned char(byte) to a binary representation of a string
char	*ft_to_binary(unsigned char c)
{
	int		i;
	char	*binary;

	i = 7;
	binary = malloc(9);
	while (i >= 0)
	{
		binary[i] = (c % 2) + '0';
		c = c / 2;
		i--;
	}
	binary[8] = 0;
	return (binary);
}

// converts a string to an integer
int	ft_atoi(char *ptr)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (ptr[i] != '\0')
	{
		nbr = nbr * 10;
		nbr = nbr + ptr[i] - 48;
		i++;
	}
	return (nbr);
}

// returns the length of a string
int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}
