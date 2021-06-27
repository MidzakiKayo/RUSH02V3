/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 10:43:18 by bchytter          #+#    #+#             */
/*   Updated: 2021/06/27 12:28:34 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int len_str(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return (i);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == '-')
		sign = -1;
	while ((*str == '-') || (*str == '+'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + ((int)*str - '0');
		str++;
	}
	return (num * sign);
}

//Check space for split first parameter.
int is_space(char i)
{
    if (i == '\t' || i == '\n' || i == '\v' || i == '\f' || i == ' ')
        return (1);
    return (0);
}

//Split first parameter in dict.
char *ft_first_word(char *str)
{
    int i;
    char *first_word;

    i = 0;
    while(is_space(*str))
        str++;
    first_word = (char *)malloc(i * sizeof(char));
    i = 0;
    while (*str && !(is_space(*str)))
        first_word[i] = str[i];
        i++;
    return (first_word);
}
// find last word 2 func.
void fn_word(char *str, int i)
{
    while(!(is_space(str[i])))
        i++;
}

char *ft_last_word(char *str)
{
    int		i;
    int     j;
	int		start;
	int		end;
    char    *last_word;

    i = 0;
    j = 0;
	start = 0;
	end = 0;
	if (is_space(*str))
        return ((void *)-1);
	while (str[i])
	{
		start = i;
		fn_word(str, i);
		end = i;
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
	}
    while (str[i] != ' ' && str[i] != '\t' && str[i])
        i++;
        j++;
    last_word = (char *)malloc(j * sizeof(char));
    i = 0;
    while (str[start] && str[start] != ' ' && str[start] != '\t' && end--)
        {
            last_word[i] = str[start];
            i++;
            start++;
        }
    return (last_word);
}
//clean
void clean(char *var)
{
    int i = 0;
    while(var[i] != '\0')
    {
        var[i] = '\0';
        i++;
    }
}

// read dict
char **read_dict(char *def_dict)
{
    int     fd;
    char    buffer;
    int     r;
    int     size;
    int     numb_line;
    char    **dict_mass;
    char    str[200];
    int     i;
	int		line;

    line = 0;
    size = 0;
    i = 0;
    numb_line = 0;
    fd = open (def_dict, O_RDONLY);
    if (fd == -1)
    {
        write (1, "Dict error...", 13);
        return ((void *)-1);
    }
    else
    {
        while ((r = read(fd, &buffer, 1)))     //Читаем массив для того чтобы узнать колличество строк.
            if(buffer == '\n')
            line++;
        dict_mass = *(char ***)malloc(line * sizeof(char)); //Создаём трёхмерный массив
        while (numb_line < line)
        {
            dict_mass[numb_line] = *(char **)malloc(sizeof(char) * 2); //Присваеваем каждой строке по два массива.
            numb_line++;
        }

        numb_line = 0;
        while (dict_mass[numb_line] != '\0')
        {
                    dict_mass[numb_line][0] = *(char *)malloc(200 * sizeof(char *));
                    dict_mass[numb_line][1] = *(char *)malloc(200 * sizeof(char));
                    numb_line++;
        }

        numb_line = 0;
        while ((r = read(fd, &buffer, 1)))                              // читаем файл для получения длины строки и её разбора.
        {                                                            // крутим буффер до момета встречи перевода на новую строку.
            if (buffer != '\n')
            {
                str[i] = buffer;
                i++;
            }
            else
            {
                while (dict_mass[numb_line] != '\0')                    // Разбираем по первому и последнему слову.
                {
                    dict_mass[numb_line][0] = *ft_first_word(str);
                    dict_mass[numb_line][1] = *ft_first_word(str);
                    numb_line++;
                }
                i = 0;
                clean(str);                                            // чистим строку для следующей линии.
            }
        }
    }
    return (dict_mass);
}


int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	if (argc == 3)
		read_dict (argv[1]);
	else
		read_dict ("numbers.dict");
    return 0;
}
