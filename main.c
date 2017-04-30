/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 19:10:31 by adaly             #+#    #+#             */
/*   Updated: 2017/04/29 19:37:23 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int	main(int argc, char **argv)
{
	char		*name;
	long long	chunk_size;
	long long	fields;

	chunk_size = 0;
	if (argc == 5)
	{
		if (ft_strequ(argv[1], "-c") && (chunk_size = ft_atoi(argv[3])))
		{
			fields = ft_atoi(argv[4]);
			name = ft_strdup(argv[2]);
			if (ft_create_database(name, fields, chunk_size) >= 0)
				ft_putendl("SUCCESS!");
			else
				ft_putendl("ERROR CREATING DATABASE");
		}
	}
}
