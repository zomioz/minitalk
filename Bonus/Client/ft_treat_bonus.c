/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 03:09:20 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/13 03:09:21 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

int	ft_treat_sentence(char *argv, pid_t pid_server)
{
	int	check;
	int	x;

	x = 0;
	while (argv[x])
	{
		check = ft_transform_to_bit(argv[x], pid_server);
		if (check == 0)
			return (0);
		x++;
	}
	check = ft_transform_to_bit(argv[x], pid_server);
	if (check == 0)
		return (0);
	return (1);
}

int	ft_treat_pid(char *pid_client, pid_t pid_server)
{
	int	check;
	int	x;

	x = 0;
	while (pid_client[x])
	{
		check = ft_transform_to_bit(pid_client[x], pid_server);
		if (check == 0)
			return (0);
		x++;
	}
	return (1);
}
