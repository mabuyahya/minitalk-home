/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <mabuyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:58:24 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/12 13:01:57 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_strlen(int signal, int *cur_bit_i, int *len_flag,
		char **final_str)
{
	static int	len_value = 0;

	if (signal == SIGUSR2)
		len_value += ft_recursive_power(2, *cur_bit_i);
	if (*cur_bit_i == 31)
	{
		*len_flag = 1;
		*cur_bit_i = 0;
		*final_str = (char *)ft_calloc_exit(len_value + 1, 1);
		len_value = 0;
		return ;
	}
	(*cur_bit_i)++;
}

static void	restart_variables(int *flag, char **str, int *i)
{
	*flag = 0;
	if (str)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*str = NULL;
	}
	*i = 0;
}

static void	signal_handler(int signal)
{
	static int	cur_bit_i = 0;
	static char	char_value = 0;
	static int	len_flag = 0;
	static char	*final_str = 0;
	static int	i = 0;

	if (!len_flag)
		receive_strlen(signal, &cur_bit_i, &len_flag, &final_str);
	else
	{
		if (signal == SIGUSR2)
			char_value += ft_recursive_power(2, cur_bit_i);
		if (cur_bit_i == 7)
		{
			final_str[i++] = char_value;
			cur_bit_i = 0;
			if (char_value == 0)
				return (restart_variables(&len_flag, &final_str, &i));
			char_value = 0;
			return ;
		}
		cur_bit_i++;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		usleep(WAIT_TIME);
}
