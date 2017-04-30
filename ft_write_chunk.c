/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:35:46 by adaly             #+#    #+#             */
/*   Updated: 2017/04/29 20:29:57 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_new_chunk(t_dbinfo *dbmeta, long long field_id)
{
	int			llsize;
	long long	counter;
	long long	*ptr;

	llsize = sizeof(long long);
	counter = 0;
	if (dbmeta)
	{
		lseek(dbmeta->fd, 0, SEEK_END);
		ft_write_file(dbmeta->fd, NULL, dbmeta->chunksize);
		ptr = dbmeta->chunks[0].chunk_addr;
		while (ptr[0] && ptr[1] && counter < dbmeta->chunksize - llsize)
		{
			++ptr;
			counter += llsize * 2;
		}
		if (!ptr[0] && !ptr[1])
		{
			*ptr = dbmeta->num_chunks;
			ptr[1] = field_id;
			dbmeta->num_chunks += 1;
			lseek(dbmeta->fd, llsize * 3, SEEK_SET);
			ft_write_file(dbmeta->fd, &field_id, llsize);
		}
		ft_write_chunk(dbmeta, 0);
		return (1);
	}
	return (-1);
}

int		ft_write_chunk(t_dbinfo *dbmeta, long long chunk_id)
{
	int			llsize;
	long long	size;

	llsize = sizeof(long long);
	size = dbmeta->chunksize;
	if (dbmeta)
	{
		lseek(dbmeta->fd, (llsize * 4) + (size * chunk_id), SEEK_SET);
		ft_write_file(dbmeta->fd, dbmeta->chunks[chunk_id].chunk_addr, size);
		return (1);
	}
	return (-1);
}

/*int		ft_append_chunk(t_dbinfo *dbmeta, long long chunk_id, void *data)
{
	int			llsize;
	long long	data_size;

	if (dbmeta)
	{
		llsize = sizeof(long long);
		if (!dbmeta->chunks[chunk_id]->chunk_addr)
			ft_load_chunk(dbmeta->fd, dbmeta, chunk_id);
		while (ft_memcmp(
	}
}*/
