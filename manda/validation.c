/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:01:31 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/20 18:13:16 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_overflowed_num(char *expected, int actual)
{
	char	*got;

	got = ft_itoa(actual);
	if (!got)
		return (1);
	if ((ft_strncmp(expected, got, ft_strlen(expected)) != 0
			&& (ft_strlen(expected) == ft_strlen(got)))
		|| ft_strlen(expected) != ft_strlen(got))
	{
		free(got);
		return (1);
	}
	free(got);
	return (0);
}
