/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 04:07:15 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/13 01:36:22 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

char	*g_pidc;

int	main(void)
{
	pid_t	pid;
	int		x;

	x = 0;
	pid = getpid();
	ft_printf("\t\t/MY SERVER PID IS\\ \n\t\t|     %d\t |\n\n", pid);
	while (1)
	{
		if (g_pidc == NULL)
			x = 0;
		while (x < 56)
		{
			signal(SIGUSR1, ft_receive_pid);
			signal(SIGUSR2, ft_receive_pid);
			pause();
			x++;
		}
		signal(SIGUSR1, ft_receiver);
		signal(SIGUSR2, ft_receiver);
		pause();
	}
	return (0);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power > 1)
		nb *= ft_recursive_power(nb, (power - 1));
	return (nb);
}

void	ft_bit_to_char(int *tab)
{
	int		x;
	int		stock;
	char	c;

	x = 0;
	stock = 0;
	while (x < 8)
	{
		if (tab[x] == 1)
			stock = stock + ft_recursive_power(2, (7 - x));
		x++;
	}
	c = stock;
	write(1, &c, 1);
	if (c == '\0')
		send_back_client();
}

void	ft_receiver(int signal)
{
	static struct s_sentence	sentence;

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
		ft_bit_to_char(sentence.tab);
		free(sentence.tab);
		sentence.tab = NULL;
		sentence.x = 0;
	}
}
