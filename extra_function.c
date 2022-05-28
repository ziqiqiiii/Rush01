/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzi-qi <tzi-qi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:26:43 by tzi-qi            #+#    #+#             */
/*   Updated: 2022/05/28 22:49:41 by tzi-qi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	*ft_memset(void *str, int c, size_t n)
{
	int				i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)str;
	if (!a)
		return (NULL);
	while (n--)
		a[i++] = (unsigned char)c;
	return (a);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(count * size);
	ft_bzero(temp, count * size);
	return (temp);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}