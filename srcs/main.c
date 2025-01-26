/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:45:09 by cgoldens          #+#    #+#             */
/*   Updated: 2025/01/26 12:05:06 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solitary.h"

int	main(void)
{
	t_var	var;

	var.mlx = mlx_init();
	if (!var.mlx)
	{
		printf("Failed to initialize MLX\n");
		return (1);
	}
	printf("MLX initialized successfully!\n");
	var.win = mlx_new_window(var.mlx, 800, 600, "MLX Test");
	if (!var.win)
	{
		fprintf(stderr, "Failed to create a window\n");
		return (1);
	}
	mlx_loop(var.mlx);
	return (0);
}
