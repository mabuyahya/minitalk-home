/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuyahy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:44:53 by mabuyahy          #+#    #+#             */
/*   Updated: 2024/12/09 18:15:54 by mabuyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(int argc, cahr *argv[])
{
	int	pid;
	char	*string;

	if (argv != 3)
	{
		ft_printf("invalid input");
		exit(1);
	}
	pid = ft_itoa(argv[1]);
	if (pid <= 0)
	{
		ft_printf("invalid pid");
		exit(1);
	}
	string = agrv[2];
	
	







}
