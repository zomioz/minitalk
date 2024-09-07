/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirulenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 04:17:03 by pirulenc          #+#    #+#             */
/*   Updated: 2024/02/13 03:12:20 by pirulenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

int		ft_transform_to_bit(char c, pid_t pid);
int		ft_sender(int x, pid_t pid);
int		ft_treat_sentence(char *argv, pid_t pid_server);
int		ft_treat_pid(char *pid_client, pid_t pid_server);
void	ft_confirm(int signal);

#endif
