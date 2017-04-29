/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:52:53 by adaly             #+#    #+#             */
/*   Updated: 2017/04/29 06:42:48 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_load_chunk(int fd, t_dbinfo *dbmeta, long long chunk_id)
{
	int			llsize;
	long long	size;
	void		*new;

	llsize = sizeof(long long);
	
	if (fd > 0 && dbmeta)
	{
		size = dbmeta->chunksize;
		new = ft_read_file(fd, (llsize * 4) + (size * chunk_id), size);
		dbmeta->chunks[chunk_id]->chunk_addr = new;
		if (dbmeta->chunks[chunk_id]->chunk_addr)
			return (1);
	}
	return (-1);
}
