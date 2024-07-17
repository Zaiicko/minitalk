/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:26:50 by zaiicko           #+#    #+#             */
/*   Updated: 2024/07/17 03:23:27 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_bit(int bit, int pid)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(550);
}

void	send_string(char *str, int pid)
{
	t_byte	byte;

	if (!str)
		return ;
	while (*str)
	{
		byte.c = *str;
		byte.i = 0;
		while (byte.i <= 7)
		{
			send_bit((byte.c >> byte.i) & 1, pid);
			byte.i++;
		}
		str++;
	}
	byte.c = *str;
	byte.i = 0;
	while (byte.i <= 7)
	{
		send_bit((byte.c >> byte.i) & 1, pid);
		byte.i++;
	}
	str++;
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_atoi(av[1]) < 1)
		{
			ft_printf("Error with the PID !\n");
			return (1);
		}
		send_string(av[2], ft_atoi(av[1]));
	}
	else
	{
		ft_printf("Error, put the right number of arguments !\n");
		return (1);
	}
	return (0);
}
