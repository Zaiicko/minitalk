/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:30:46 by zaiicko           #+#    #+#             */
/*   Updated: 2024/07/16 01:36:08 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	reset_byte(t_byte *byte)
{
	byte->i = 0;
	byte->c = 0;
}

void	handler(int bit)
{

}

int	main()
{
	ft_printf("THE PID ARE : %d\n", getpid()); 	
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
