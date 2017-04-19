/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:52:53 by adaly             #+#    #+#             */
/*   Updated: 2017/04/19 14:30:21 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_load_chunk(int fd, t_dbinfo *dbmeta, long long chunk_id)
{
	long long	offset;
	long long	size;

	if (fd > 0 && dbmeta)
	{
		dbmeta->chunks[chunk_id]->chunk_addr = NULL;
		offset = dbmeta->chunks[chunk_id]->offset;
		size = dbmeta->chunks[chunk_id]->chunk_size;
		dbmeta->chunks[chunk_id]->chunk_addr = ft_read_file(fd, offset, size);
		if (dbmeta->chunks[chunk_id]->chunk_addr)
			return (1);
	}
	return (-1);
}
