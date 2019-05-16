/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 19:45:15 by hcasanov          #+#    #+#             */
/*   Updated: 2019/05/15 18:49:11 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_draw_mandelbrot(t_mlx *mlx)
{
	int		x;
	int		y;
	double	k;

	x = 0;
	while (x < mlx->img_w)
	{
		y = 0;
		while (y < mlx->img_h)
		{
			k = ft_algo_mandelbrot(mlx, x, y);
			if (k != mlx->in_max && k > 1)
				ft_set_pixel(mlx, x, y, k);
			y++;
		}
		x++;
	}
}

double		ft_algo_mandelbrot(t_mlx *mlx, int x, int y)
{
	double	tmp;
	double	i;

	mlx->z_r = 0;
	mlx->z_i = 0;
	mlx->c_r = x / mlx->zoom + mlx->x1;
	mlx->c_i = y / mlx->zoom + mlx->y1;
	i = 0;
	while ((mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i) < 4 && i < mlx->in_max)
	{
		tmp = mlx->z_r;
		mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
		mlx->z_i = 2 * mlx->z_i * tmp + mlx->c_i;
		i++;
	}
	return (i);
}
