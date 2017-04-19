/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:43:49 by adaly             #+#    #+#             */
/*   Updated: 2017/04/19 15:02:57 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H

typedef struct	s_field
{
	void		*data;
	void		*index_addr;
	void		*next_addr;
	void		*prev_addr;
	int			field_id;
	int			next_chunk;
	int			prev_chunk;
	int			index_chunk;
}				t_field;

typedef struct	s_chunkinfo
{
	void		*chunk_addr;
	long long	offset;
	long long	chunkid;
	long long	fieldid;
	long long	chunksize;
}				t_chunkinfo;

typedef struct	s_dbinfo
{
	t_chunkinfo	**chunks;
	char		**field_names;
	long long	**field_sizes;
	long long	num_entries;
	long long	num_fields;
	long long	num_chunks;
}				t_dbinfo;

int				ft_load_chunk(int fd, t_dbinfo *dbmeta, long long chunk_id);
t_dbinfo		*ft_read_dbheader(int fd, t_dbinfo *dbmeta);
int				ft_write_dbheader(int fd, t_dbinfo *dbmeta);
t_chunkinfo		**ft_locate_chunks(int fd, long long num_chunks);
t_chunkinfo		*ft_parse_chunk(int fd);
t_field			*ft_create_entry(t_dbinfo *dbmeta);
int				ft_initialize_field(long long field_id, ft_field *prev_addr);

#endif
