/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaiicko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 23:17:32 by zaiicko           #+#    #+#             */
/*   Updated: 2024/07/17 03:19:12 by zaiicko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/inc/libft.h"
# include <signal.h>

# define RESET	"\033[0m"
# define CYAN	"\033[36m"
# define BOLD	"\033[1m"

typedef struct byte
{
	size_t		i;
	char		c;
}		t_byte;

void	reset_byte(t_byte *byte);
void	handler(int sig);
void	send_bit(int bit, int pid);
void	send_string(char *str, int pid);

#endif
