/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:14:03 by bchytter          #+#    #+#             */
/*   Updated: 2021/06/27 16:47:00 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_dict(int argc, char **argv)
{
	char	*file;
	char	*filestd;
	int		i;

	filestd = "numbers.dict";
	i  = 0;
	file = (char*)malloc(200 * sizeof(char)); // подсмотренная идея/
	if (argc == 2)
	{
		while (filestd[i] != '\0')
		{
			file[i] = filestd[c];
			i++;
		}
		file[i] = '\0';
	}
	else
	{
		while (argv[1][i] != '\0')
		{
			filename[i] = argv[1][i];
			i++;
		}
	}
	return (file);
}
//copy частичный копи паст//
char	*ft_read(char *file)
{
	int		open;
	int		read;
	char	*dict_in;
	char	*dict;
	int		i;

	i = 0;
	dict_in = (char*)malloc(2000 * sizeof(char));
	open = open(filename, O_RDONLY);
	if (open < 0)
	{
		write (2, "Dict error..\n", 12);
		return (0);
	}
	read = read(open, dict_in, 2000);
	dict = (char*)malloc((read + 1) * sizeof(char));
	while (i < read)
	{
		dict[i] = dict_in[i];
		i++;
	}
	dict[i] = '\0';
	free(dict_in);
	if ((i = close(open)) < 0)
		write (2, "Error close\n", 12);
	return (dict);
}
//copy
void	ft_write_nbr(char *nbr, char *dict)
{
	int c;
	int len;
	int div;

	c = 0;
	len = ft_strlen(nbr);
	ft_write(nbr, len, dict);
	while (nbr[c])
	{
		div = len / 3;
		c++;
	}
}
//copy
void	ft_write(char *nbr, int len, char *dict)
{
	int		c;
	int		mod;

	c = 0;
	mod = 0;
	while (nbr[c] != '\0')
	{
		mod = len % 3;
		if (mod == 2 && nbr[c] == '1')
		{
			ft_write_teens(nbr[c], dict);			
			break ;
		}
		else if (mod == 2 && nbr[c] != '1' && nbr[c + 1] != '0')
		{
			ft_write_dez(nbr[c], dict);
			write(1, " ", 1);
		}
		if (mod == 1)
			ft_write_uni(nbr[c], dict);
		c++;
		len--;
	}
}

