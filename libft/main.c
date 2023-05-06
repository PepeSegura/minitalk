/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 02:37:36 by psegura-          #+#    #+#             */
/*   Updated: 2023/03/25 04:22:08 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/libft.h"

int	main(int argc, char **argv, char **env)
{
	char	**after_delete;
	char	**after_add;

	ft_print_matrix(env, "env");
	after_delete = ft_delete_row_matrix(env, 10);
	ft_print_matrix(after_delete, "after_delete");
	after_add = ft_add_row_matrix(after_delete, "paco=1234");
	ft_print_matrix(after_add, "after_add");
	return (0);
}
