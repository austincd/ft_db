/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_database_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:54:03 by adaly             #+#    #+#             */
/*   Updated: 2017/04/19 13:45:31 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_dbinfo	*ft_read_dbheader(int fd, t_dbinfo *dbmeta)
{
	int		status;
	int		counter;
	char	*line;

	counter = 0;
	status = 0;
	if (fd > 0 && dbmeta)
	{
		dbmeta->chunks = NULL;
		line = NULL;
		while ((status = get_next_line(fd, &line)) == 1 && counter < 3)
		{
			if (counter == 0)
				dbmeta->num_entries = ft_atoi(line);
			if (counter == 1)
				dbmeta->num_fields = ft_atoi(line);
			if (counter == 2)
				dbmeta->num_chunks = ft_atoi(line);
			++counter;
		}
		if (counter == 3)
			dbmeta->chunks = ft_locate_chunks(fd, dbmeta->num_chunks);
		if (dbmeta->chunks)
			return (dbmeta);
	}
	return (NULL);
}

int			ft_write_dbheader(int fd, t_dbinfo *dbmeta)
{
}
