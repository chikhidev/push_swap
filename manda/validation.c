/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <abchikhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:01:31 by abchikhi          #+#    #+#             */
/*   Updated: 2024/04/26 09:52:39 by abchikhi         ###   ########.fr       */
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
	char	*tmp;
	int		i;

	tmp = ft_itoa(actual);
	if (!tmp)
		return (1);
	got = tmp + (expected[0] == '-' && ft_strncmp(tmp, "0", 1) != 0);
	expected += (expected[0] == '+');
	expected += (expected[0] == '-');
	i = 0;
	while (expected[i] == '0'
		&& i < (int)(ft_strlen(expected) - 1))
		expected++;
	if ((ft_strncmp(expected, got, ft_strlen(expected)) != 0
			&& (ft_strlen(expected) == ft_strlen(got)))
		|| ft_strlen(expected) != ft_strlen(got))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}
