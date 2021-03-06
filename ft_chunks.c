/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:20:19 by adaly             #+#    #+#             */
/*   Updated: 2017/04/29 06:50:39 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_chunk_follow(t_dbinfo *dbmeta, long long chunkid)
{
	long long	size;
	int			llsize;
	void		**chunk;
	long long	*ptr;

	llsize = sizeof(long long);
	size = dbmeta->chunksize;
	chunk = &(dbmeta->chunks[chunkid].chunk_addr);
	ptr = (*chunk) + (size - llsize);
	if (*ptr)
		ft_load_chunk(dbmeta->fd, dbmeta, *ptr);
	return (*ptr);
}
