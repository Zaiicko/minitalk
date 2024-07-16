/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:30:46 by zaiicko           #+#    #+#             */
/*   Updated: 2024/07/16 18:09:14 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_byte	g_byte;

void	reset_byte(t_byte *byte)
{
	byte->i = 0;
	byte->c = 0;
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_byte.c |= (1 << g_byte.i);
	g_byte.i++;
	if (g_byte.i == 8)
	{
		if (g_byte.c == 0)
			ft_putchar('\n');
		else
			ft_putchar(g_byte.c);
		reset_byte(&g_byte);
	}
}

int	main(void)
{
	reset_byte(&g_byte);
	ft_printf("THE PID IS : %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
