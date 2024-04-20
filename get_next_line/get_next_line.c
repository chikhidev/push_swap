/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdoo <abdoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:13:43 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/20 16:57:11 by abdoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	extract_line(t_store *store, char **saved, int is_last)
{
	int	to_return;

	to_return = 1;
	if (is_last)
	{
		if (!*saved || **saved == '\0')
			to_return = 0;
		else
			store->line = ft_strdup(*saved);
		free(*saved);
		*saved = NULL;
		return (to_return);
	}
	else
	{
		store->line = ft_substr(*saved, 0, store->new_line_pos - *saved + 1);
		store->temp = ft_substr(store->new_line_pos,
				1, ft_strlen(store->new_line_pos));
		free(*saved);
		*saved = store->temp;
	}
	return (1);
}

int	free_and_fail(t_store *store, char **saved)
{
	if (store->buff != NULL)
	{
		free(store->buff);
		store->buff = NULL;
	}
	if (*saved != NULL)
	{
		free(*saved);
		*saved = NULL;
	}
	return (0);
}

int	store_line(char **saved, t_store *store, int fd)
{
	while (1)
	{
		store->buff = malloc(BUFFER_SIZE + 1);
		if (!store->buff)
			return (free_and_fail(store, saved));
		store->bytes = read(fd, store->buff, BUFFER_SIZE);
		if (store->bytes == -1)
			return (free_and_fail(store, saved));
		store->buff[store->bytes] = '\0';
		store->temp = ft_strjoin(*saved, store->buff);
		free(store->buff);
		if (*saved != NULL)
		{
			free(*saved);
			*saved = NULL;
		}
		*saved = store->temp;
		store->new_line_pos = ft_strchr(*saved, '\n');
		if (store->bytes == 0 && !store->new_line_pos)
			return (extract_line(store, saved, 1));
		if (store->new_line_pos != NULL)
			return (extract_line(store, saved, 0));
	}
	return (1);
}

char	*get_next_line(int fd, int signal)
{
	static char	*saved;
	t_store		store;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (signal == 1 && saved)
		return (saved);
	if (!store_line(&saved, &store, fd))
		return (NULL);
	return (store.line);
}
