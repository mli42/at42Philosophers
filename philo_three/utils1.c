/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:32:53 by mli               #+#    #+#             */
/*   Updated: 2020/09/23 11:05:07 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*ft_memalloc(size_t size)
{
	void *result;

	if (!(result = malloc(size)))
		return (NULL);
	memset(result, 0, size);
	return (result);
}

void	ft_free(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

size_t	ft_strlen(const char *const str)
{
	const char *tmp = str;

	while (*tmp)
		tmp++;
	return (tmp - str);
}

void	ft_putstr_fd(const char *const str, const int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putendl_fd(const char *const str, const int fd)
{
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}
