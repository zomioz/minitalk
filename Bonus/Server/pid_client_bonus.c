/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 01:37:26 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/13 01:37:27 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	ft_receive_pid(int signal)
{
	static struct s_sentence	sentence;

	if (g_pidc == NULL)
		g_pidc = ft_calloc(sizeof(char), 8);
	if (sentence.tab == NULL)
		sentence.tab = ft_calloc(sizeof(int), 8);
	if (!sentence.x)
		sentence.x = 0;
	if (sentence.x < 8)
	{
		if (signal == SIGUSR1)
		{
			sentence.tab[sentence.x] = 1;
			sentence.x++;
		}
		else
			sentence.x++;
	}
	if (sentence.x == 8)
	{
		ft_bit_to_pid(sentence.tab);
		free(sentence.tab);
		sentence.tab = NULL;
		sentence.x = 0;
	}
}

void	ft_bit_to_pid(int *tab)
{
	int			x;
	int			stock;
	static int	pos;

	if (!pos)
		pos = 0;
	x = 0;
	stock = 0;
	while (x < 8)
	{
		if (tab[x] == 1)
			stock = stock + ft_recursive_power(2, (7 - x));
		x++;
	}
	g_pidc[pos] = stock;
	pos++;
	if (pos == 7)
		pos = 0;
}

void	send_back_client(void)
{
	int	pid;

	pid = ft_atoi(g_pidc);
	usleep(1000);
	if (kill(pid, SIGUSR1) == -1)
		ft_printf("\n\t    CAN'T SEND BACK TO THE CLIENT\n");
	else
	{
		ft_printf("\n\n\t  |Mesage received and ");
		ft_printf("confirm to|\n\t\t      %d\n\n", pid);
	}
	free(g_pidc);
	g_pidc = NULL;
}
