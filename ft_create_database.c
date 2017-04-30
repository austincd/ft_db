/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_database.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 19:21:53 by adaly             #+#    #+#             */
/*   Updated: 2017/04/29 20:25:07 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int	ft_create_database(char *name, long long fields, long long chunk_size)
{
	long long	counter;
	long long	*new;
	int			llsize;
	int	   		fd;

	fd = -1;
	new = NULL;
	counter = 0;
	llsize = sizeof(long long);
	if (name && chunk_size)
	{
		fd = ft_create_file(ft_strjoin(name, ".ftdb"));
		if (fd)
		{
			new = (long long*)ft_memalloc(llsize * 4);
			new[0] = 0;
			new[1] = fields;
			new[2] = fields + 2;
			new[3] = chunk_size;
			if (write(fd, (void*)new, llsize * 4) == llsize * 4)
			{
				while (counter < fields)
				{
					ft_new_chunk(ft_read_dbheader(fd), counter);
					++counter;
				}
				return (fd);
			}
		}
	}
	return (-1);
}
