/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:25:41 by irivero-          #+#    #+#             */
/*   Updated: 2023/08/15 11:01:01 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int n);
char	*ft_itoa_pid(int n);
char	*ft_to_binary(unsigned char c);
int		ft_atoi(char *ptr);
int		ft_strlen(char *s);

#endif
