/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:28:52 by bchytter          #+#    #+#             */
/*   Updated: 2021/06/27 16:05:38 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "init_dict.c"

//test1
#include <stdio.h>

int main(int argc, char **argv)
{
	char **dict;

	if (argc > 3)
	{
		write (2, "Too many args\n", 14);
		return (1);
	}
	if (argc < 2 )
	{
		write (2, "Too low args\n", 13);
		return (1);
	}
	if (argc == 3)
	{
		//check_sint(argv[2]);
		dict = init_dict (argv[1]);
		//numb_in_word (argv[2]);
	}
	if (argc == 2)
	{
		//check_sint(argv[1]);
		dict = init_dict("numbers.dict");
		//numb_in_word(argv[1]);
	}
	return (0);
}
