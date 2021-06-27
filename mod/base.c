/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:12:55 by bchytter          #+#    #+#             */
/*   Updated: 2021/06/27 16:13:54 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
	{
		ft_putchar(str[c]);
		c++;
	}
}

int		ft_strlen(char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

int		ft_atoi_uni(char nbr)
{
	int n;

	n = nbr - ('0');
	return (n);
}

int		ft_msg_error(void)
{
	ft_putstr("Error");
	return (0);
}
