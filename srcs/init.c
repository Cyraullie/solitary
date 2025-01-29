/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:13:38 by cgoldens          #+#    #+#             */
/*   Updated: 2025/01/29 13:46:41 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solitary.h"

void	init_rng(t_var **var)
{
	int	i;
	int	rng;

	i = 0;
	(*var)->rnd_draft = ft_calloc(sizeof(int), 53);
	(*var)->rnd_draft[i] = -1;
	while (i < 52)
	{
		rng = rand() % 52;
		if (!check_tab((*var)->rnd_draft, rng))
		{
			(*var)->rnd_draft[i] = rng;
			(*var)->rnd_draft[i + 1] = -1;
			i++;
		}
	}
}
//TODO faire le drag and drop

void	init(t_var *var)
{
	var->screen_height = 1000;
	var->screen_length = 1150;
	init_img(&var);
	add_floor(var);
	init_rng(&var);
	place_card(&var);
}
