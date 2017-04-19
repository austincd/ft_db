/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fields.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:34:28 by adaly             #+#    #+#             */
/*   Updated: 2017/04/19 15:00:49 by adaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_field		*ft_create_entry(t_dbinfo *dbmeta)
{
	long long	counter;
	t_dbinfo	*first;
	t_dbinfo	*current;

	counter = 0;
	first = NULL;
	first = ft_initialize_field(counter, NULL);
	++counter;
	current = ft_initialize_field(counter, first);
	++counter;
	while (counter < dbmeta->num_fields)
	{
		current = ft_initialize_field(counter, current);
		if (!current)
			return (NULL);
		++counter;
	}
	if (first)
		++(dbmeta->num_entries);
	return (first);
}

int		ft_initialize_field(long long field_id, ft_field *prev_addr)
{
	t_field *new;

	new = NULL;
	new = (t_field*)ft_memalloc(sizeof(t_field));
	if (new)
	{
		new->prev_addr = prev_addr;
		new->field_id = field_id;
		if (new->prev_addr)
			new->prev_addr->next_addr = new;
	}
	return (new);
}
