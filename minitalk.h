/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:07:15 by vguidoni          #+#    #+#             */
/*   Updated: 2023/01/23 13:07:18 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>

int		ft_atoi(const char *nptr);
void	ft_gest(int signal);
void	controllo(int segnale);
void	ft_bits(int pid, char i);
int		ft_printf(const char *format, ...);

#endif
