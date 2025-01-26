/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:45:09 by cgoldens          #+#    #+#             */
/*   Updated: 2025/01/26 11:52:02 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solitary.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
	{
		printf("Failed to initialize MLX\n");
		return (1);
	}
	printf("MLX initialized successfully!\n");
	win = mlx_new_window(mlx, 800, 600, "MLX Test");
	if (!win)
	{
		fprintf(stderr, "Failed to create a window\n");
		return (1);
	}
	mlx_loop(mlx);
	return (0);
}
