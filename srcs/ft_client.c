/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:26:50 by zaiicko           #+#    #+#             */
/*   Updated: 2024/07/16 22:34:59 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_bit(int bit, int pid)
{
	if (bit == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(200);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_atoi(av[1]) < 1)
		{
			ft_printf("Error with the PID\n");
			return (1);
		}
	}
	else
	{
		ft_printf("Error, put the right number of arguments !");
		return (1);
	}
	return (0);
}
