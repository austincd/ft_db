/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:59:30 by adaly             #+#    #+#             */
/*   Updated: 2017/04/27 17:53:19 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int				ft_identify_fields(t_dbinfo *dbmeta, int fd)
{
	long long	num_fields;
	long long	counter;
	char		*field;


	if (dbmeta)
	{
		num_fields = dbmeta->num_fields;
		counter = 0;
		dbmeta->fields = (t_fieldinfo**)ft_memalloc(sizeof(t_fieldinfo*) * num_fields);
		if (dbmeta->fields)
		{
			while (counter < num_fields)
			{
				ft_get_next_n_lines(fd, 6, &field);
				dbmeta->fields[counter] = ft_parse_field(field);
				++counter;
			}
			return (counter);
		}
	}
	return (-1);
}

t_fieldinfo*	ft_parse_field(char *str)
{
	char		*name;
	short		counter;
	t_fieldinfo	*new;

	counter = 0;
	new = (t_fieldinfo*)ft_memalloc(sizeof(t_fieldinfo));
	if (new)
	{
		while (counter < 6)
		{
			if (counter == 0)
				new->field_id = ft_atoi(ft_strstr(str, "FIELD=") + 6);
			if (counter == 1)
				new->field_name = ft_strcdup((ft_strstr(str, "NAME=") + 5), '\n');
			if (counter == 2)
			{
				new->size = ft_atoi(ft_strstr(str, "SIZE=") + 5);
				if (ft_strstr(str, "SIZE=var"))
					new->size = -2;
			}
			if (counter == 3)
				new->text = *(ft_strstr(str, "TEXT?=") + 6);
			if (counter == 4)
				new->sign = *(ft_strstr(str, "SIGNED?=") + 8);
			if (counter == 5)
				new->delim = ft_atoi(ft_strstr(str, "DELIM=") + 6);
			str = ft_strchr(str, '\n') + 1;
			++counter;
		}
	}
	return (new);
}
