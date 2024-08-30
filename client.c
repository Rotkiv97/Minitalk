/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:57:19 by vguidoni          #+#    #+#             */
/*   Updated: 2023/01/23 12:57:22 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	const char	*y;
	int			tab;
	int			j;
	int			i;

	y = nptr;
	i = 0;
	tab = 0;
	j = 1;
	while ((y[i] >= 9 && y[i] <= 13) || y[i] == ' ')
		i++;
	if (y[i] == 43)
		i++;
	else if (y[i] == 45)
	{
		j *= -1;
		i++;
	}
	while (y[i] >= 48 && y[i] <= 57)
	{
		tab *= 10;
		tab += y[i] - 48;
		i++;
	}
	return (tab * j);
}

void	controllo(int segnale)
{
	if (segnale == SIGUSR1)
		ft_printf("\033[32mok %d\n", 1);
	else
		ft_printf("\033[31mError %d", 1);
}

void	ft_bits(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	get;
	int	i;

	i = 0;
	if (argc == 3)
	{
		get = atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			signal(SIGUSR1, controllo);
			signal(SIGUSR2, controllo);
			ft_bits(get, argv[2][i]);
			i++;
		}
		ft_bits(get, '\n');
	}
	else
	{
		ft_printf("\033[91mErrore: il programma acetta solo 3 argomenti\033[0m\n");
		return (1);
	}
	return (0);
}
