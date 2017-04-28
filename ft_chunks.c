/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:20:19 by adaly             #+#    #+#             */
/*   Updated: 2017/04/26 17:48:07 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_chunkinfo	**ft_locate_chunks(int fd, long long num_chunks, long long size_index)
{
	int			countone;
	t_chunkinfo **chunks;

	chunks = NULL;
	countone = 0;
	if (fd > 0)
	{
		chunks = (t_chunkinfo**)ft_memalloc(sizeof(t_chunkinfo*) * num_chunks);
		if (chunks)
		{
			while (countone < num_chunks)
			{
				chunks[countone] = ft_parse_chunk(fd);
				if (!chunks[countone])
					return (NULL);
				++countone;
			}
		}
	}
	return (chunks);
}

t_chunkinfo	*ft_parse_chunk(int fd)
{
	int			counter;
	int			status;
	char		*line;
	t_chunkinfo	*chunk;

	counter = 0;
	chunk = NULL;
	status = 0;
	line = NULL;
	chunk = (t_chunkinfo*)ft_memalloc(sizeof(t_chunkinfo));
	if (chunk)
	{
		while ((status = get_next_line(fd, &line)) == 1 && counter < 3)
		{
			if (counter == 0)
				chunk->chunkid = ft_atoi(line);
			if (counter == 1)
				chunk->fieldid = ft_atoi(line);
			if (counter == 2)
				chunk->chunksize = ft_atoi(line);
			++counter;
		}
	}
	if (counter == 3)
		return (chunk);
	return (NULL);
}
