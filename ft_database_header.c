/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_database_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:54:03 by adaly             #+#    #+#             */
/*   Updated: 2017/04/29 05:27:16 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

t_dbinfo	*ft_read_dbheader(int fd, t_dbinfo *dbmeta)
{
	long long	*ptr;
	long long	llsize;
	long long	counter;
	
	if (fd > 0 && dbmeta)
	{
		llsize = sizeof(long long);
		ptr = (long long*)ft_memalloc(llsize);
		dbmeta->chunks = NULL;
		while (read(fd, ptr, llsize) == llsize && counter < 4)
		{
			if (counter == 0)
				dbmeta->chunksize = *ptr;
			if (counter == 1)
				dbmeta->num_entries = *ptr;
			if (counter == 2)
				dbmeta->num_fields = *ptr;
			if (counter == 3)
			{
				dbmeta->num_chunks = *ptr;
				dbmeta->chunks = (t_chunkinfo*)ft_memalloc(sizeof(t_chunkinfo) * *ptr);
			}
			++counter;
		}
	}
	return (NULL);
}

void		ft_read_chunkzero(long long fd, t_dbinfo *dbmeta)
{
	long long	counter;
	long long	*ptr;

	counter = 0;
	if (dbmeta)
	{
		if (ft_load_chunk(fd, dbmeta, 0);
		{
			while (counter < num_chunks)
			{
				ptr = dbmeta->chunks[counter].chunk_addr;
				dbmeta->chunks[counter].chunkid = counter;
				dbmeta->chunks[counter].fieldid = *ptr;
				++counter;
			}
		}
	}

}

int			ft_write_dbheader(int fd, t_dbinfo *dbmeta)
{
}
