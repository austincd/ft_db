/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:19:52 by adaly             #+#    #+#             */
/*   Updated: 2017/04/27 17:44:59 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_db.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	t_dbinfo *dbmeta;
	long long counter;

	counter = 0;
	dbmeta = NULL;
	if (argc == 2)
	{
		fd = ft_open_file(argv[1]);
		dbmeta = (t_dbinfo*)ft_memalloc(sizeof(t_dbinfo));

		if (dbmeta)
		{
			ft_read_dbheader(fd, dbmeta);
			ft_identify_fields(dbmeta, fd);
			printf("num_fields=%lld\n", dbmeta->num_fields);
			while (counter < dbmeta->num_fields)
			{
				printf("FIELD=%lld\n", dbmeta->fields[counter]->field_id);
				printf("NAME=%s\n", dbmeta->fields[counter]->field_name);
				printf("SIZE=%lld\n", dbmeta->fields[counter]->size);
				printf("TEXT?=%c\n", dbmeta->fields[counter]->text);
				printf("SIGNED?=%c\n", dbmeta->fields[counter]->sign);
				printf("DELIM=%d\n", dbmeta->fields[counter]->delim);
				++counter;
			}
		}
	}
}
