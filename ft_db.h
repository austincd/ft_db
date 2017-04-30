/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:43:49 by adaly             #+#    #+#             */
/*   Updated: 2017/04/29 20:25:57 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H
# include "libft/libft.h"
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
	long long	chunkid;
	long long	fieldid;
}				t_chunkinfo;

typedef struct	s_fieldinfo
{
	char		*field_name;
	long long	field_id;
	long long	size;
	char		text;
	char		sign;
	char		delim;
}				t_fieldinfo;

typedef struct	s_dbinfo
{
	char		*name;
	int			fd;
	t_chunkinfo	*chunks;
	t_fieldinfo	*fields;
	long long	chunksize;
	long long	num_entries;
	long long	num_fields;
	long long	num_chunks;
}				t_dbinfo;

int				ft_load_chunk(int fd, t_dbinfo *dbmeta, long long chunk_id);
t_dbinfo		*ft_read_dbheader(int fd);
int				ft_write_dbheader(int fd, t_dbinfo *dbmeta);
t_chunkinfo		**ft_locate_chunks(int fd, long long num_chunks);
t_chunkinfo		*ft_parse_chunk(int fd);
t_field			*ft_create_entry(t_dbinfo *dbmeta);
int				ft_initialize_field(long long field_id, t_field *prev_addr);
int				ft_identify_fields(t_dbinfo *dbmeta, int fd);
t_fieldinfo		*ft_parse_field(char *str);
int				ft_create_database(char *name, long long fields, long long chunk_size);
int				ft_new_chunk(t_dbinfo *dbmeta, long long field_id);
int				ft_write_chunk(t_dbinfo *dbmeta, long long chunk_id);
#endif
