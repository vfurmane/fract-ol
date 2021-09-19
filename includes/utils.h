/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hintauh <hintauh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:57:54 by vfurmane          #+#    #+#             */
/*   Updated: 2021/09/19 16:57:48 by hintauh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

void	*ft_bzero(void *str, size_t len);
void	*ft_calloc(size_t len, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t len);
int		ft_strcmp(const char *str1, const char *str2);

#endif
