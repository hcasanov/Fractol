/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:14:43 by hcasanov          #+#    #+#             */
/*   Updated: 2019/05/16 17:02:41 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_init_list(t_mlx *mlx)
{
	if (!(mlx->ptr = mlx_init()))
		ft_exit(mlx);
	mlx->img_w = 1800;
	mlx->img_h = 1200;
	mlx->color = 0xfff;
	mlx->red = ((unsigned char *)&(mlx->color))[2];
	mlx->green = ((unsigned char *)&(mlx->color))[1];
	mlx->blue = ((unsigned char *)&(mlx->color))[0];
	if (!(mlx->window = mlx_new_window(mlx->ptr, mlx->img_w, mlx->img_h, "test"\
)))
		ft_exit(mlx);
	mlx->move = 1;
}

void		ft_init_list_julia(t_mlx *mlx)
{
	mlx->x1 = -2;
	mlx->x2 = 0;
	mlx->y1 = -1.5;
	mlx->y2 = 1.5;
	mlx->zoom = 400;
	mlx->in_max = 50;
	mlx->c_r = 0.285;
	mlx->c_i = 0.02;
}

void		ft_init_list_mandelbrot(t_mlx *mlx)
{
	mlx->x1 = -2;
	mlx->x2 = 2;
	mlx->y1 = -1.5;
	mlx->y2 = 2;
	mlx->zoom = 450;
	mlx->in_max = 50;
}

void		ft_init_list_burningship(t_mlx *mlx)
{
	mlx->x1 = -2.0;
	mlx->x2 = 2.5;
	mlx->y1 = -2.5;
	mlx->y2 = 1.5;
	mlx->zoom = 300;
	mlx->in_max = 500;
	mlx->in_max = 50;
}
