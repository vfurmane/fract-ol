/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:57:54 by vfurmane          #+#    #+#             */
/*   Updated: 2021/06/20 21:14:09 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

void	*ft_bzero(void *str, size_t len);
void	*ft_calloc(size_t len, size_t size);
int		ft_strcmp(const char *str1, const char *str2);

#endif
