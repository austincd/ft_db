/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 18:35:46 by adaly             #+#    #+#             */
/*   Updated: 2017/04/29 06:49:48 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_new_chunk(t_dbinfo *dbmeta, long long field_id)
{
	if (dbmeta)
	{
		lseek(dbmeta->fd, 0, SEEK_END);
		ft_write_file(dbmeta->fd, NULL, dbmeta->chunksize);
		ft_append_chunk(dbmeta, 0, field_id);
		ft_write_chunk(dbmeta, 0);
	}
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
	}
}
