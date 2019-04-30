/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:10 by hcasanov          #+#    #+#             */
/*   Updated: 2019/04/29 17:22:12 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./fractol.h"

void    ft_init_list(t_mlx *mlx)
{
    mlx->ptr = mlx_init();
    mlx->img_w = 1800;
    mlx->img_h = 1200;
    //mlx->green = 100;
    //mlx->red = 100;
   // mlx->blue = 100;
    mlx->red = ((unsigned char *)&(mlx->color))[2];
	mlx->green = ((unsigned char *)&(mlx->color))[1];
	mlx->blue = ((unsigned char *)&(mlx->color))[0];
    mlx->window = mlx_new_window(mlx->ptr, mlx->screen_w, mlx->screen_h,
			"test");
}