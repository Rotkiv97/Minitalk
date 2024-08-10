/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:57:30 by vguidoni          #+#    #+#             */
/*   Updated: 2023/01/23 12:57:33 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	ft_gest(int signal)
{
	static int	bit = 0;
	static int	i = 0;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int	get;

	get = getpid();
	printf("PID = %d\n", get);
	signal(SIGUSR1, ft_gest);
	signal(SIGUSR2, ft_gest);
	while (1)
		pause();
	write(1, "\n", ft_strlen("\n"));
	return (0);
}

