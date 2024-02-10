/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:57:11 by psegura-          #+#    #+#             */
/*   Updated: 2024/02/10 15:42:53 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (s1 == NULL && s2)
		return (s2);
	if (s2 == NULL && s1)
		return (s1);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_strcpy(str, s1);
	ft_strlcat(str, s2, ft_strlen(s2));
	return (str);
}
