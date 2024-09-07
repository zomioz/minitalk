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

#ifndef SERVER_H
# define SERVER_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

struct		s_sentence
{
	int	*tab;
	int	x;
};

int		ft_recursive_power(int nb, int power);
void	ft_bit_to_char(int *tab);
void	ft_receiver(int signal);

#endif
