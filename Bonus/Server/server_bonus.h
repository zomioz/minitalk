/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 04:17:03 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/13 01:24:35 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

extern char	*g_pidc;

struct		s_sentence
{
	int	*tab;
	int	x;
};

int		ft_recursive_power(int nb, int power);
void	ft_bit_to_char(int *tab);
void	ft_receiver(int signal);
void	ft_receive_pid(int signal);
void	ft_bit_to_pid(int *tab);
void	send_back_client(void);

#endif
