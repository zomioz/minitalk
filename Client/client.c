/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 05:57:15 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/13 03:08:35 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	int		check;

	if (argc < 3)
		return (ft_printf("Error\n"));
	else
	{
		pid_server = ft_atoi(argv[1]);
		check = ft_treat_sentence(argv[2], pid_server);
		if (check == 0)
			return (0);
	}
	return (1);
}

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

int	ft_transform_to_bit(char c, pid_t pid_server)
{
	int	x;
	int	bite;
	int	check;

	x = c;
	bite = 128;
	while (bite != 0)
	{
		if (x >= bite)
		{
			x = x % bite;
			bite = bite / 2;
			check = ft_sender(1, pid_server);
		}
		else
		{
			bite = bite / 2;
			check = ft_sender(0, pid_server);
		}
		if (check == 0)
			return (0);
		usleep(200);
	}
	return (1);
}

int	ft_sender(int x, pid_t pid_server)
{
	if (x == 1)
	{
		if (kill(pid_server, SIGUSR1) == -1)
		{
			ft_printf("Error of reception, end of process\n");
			return (0);
		}
	}
	if (x == 0)
	{
		if (kill(pid_server, SIGUSR2) == -1)
		{
			ft_printf("Error of reception, end of process\n");
			return (0);
		}
	}
	return (1);
}
