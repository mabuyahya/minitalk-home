/* ************************************************************************** */
/*                                                                            */

/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:44:53 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/11 12:30:13 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void send_strlen(int str_len, int pid)
{
	int	i;

	i = -1;
	while(++i < 32)
	{
		if (str_len & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);	
		str_len = str_len >> 1;
		usleep(WAIT_TIME);
	}
}

static void	send_char(unsigned char	c, int pid)
{
	int	i;

	i = -1;
	while(++i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(WAIT_TIME);
	}


}

static int	invalid_input(int argc, char **argv)
{
    int     i;

    if (argc != 3) 
            return (1);
    i = -1;
    while (argv[1][++i])
    {
		if(!ft_strchr("0123456789", argv[1][i]))
            return (1);
    }
        return (0);
}

int	main(int argc, char *argv[])
{
	int	pid;
	char	*string;
	int	string_len;
	int	i;

	i = -1;
	pid = ft_atoi(argv[1]);
	string = argv[2];
	if (invalid_input(argc, argv))
	{
		ft_printf("invalid input");
		exit(1);
	}
	if (pid <= 0)
	{
		ft_printf("invalid pid");
		exit(1);
	}
	string_len = ft_strlen(string);
	send_strlen(string_len, pid);	
	while (string[++i])
		send_char(string[i], pid);
	// send_char(string[i], pid);
}
