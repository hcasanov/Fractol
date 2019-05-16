/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:58:44 by hcasanov          #+#    #+#             */
/*   Updated: 2019/05/13 20:21:02 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_draw_julia(t_mlx *mlx)
{
	int		x;
	int		y;
	double	c;

	x = 0;
	while (x < mlx->img_w)
	{
		y = 0;
		while (y < mlx->img_h)
		{
			c = ft_algo_julia(mlx, x, y);
			if (c != mlx->in_max && c > 1)
				ft_set_pixel(mlx, x, y, c);
			y++;
		}
		x++;
	}
}

double		ft_algo_julia(t_mlx *mlx, int x, int y)
{
	double	tmp;
	double	i;

	mlx->z_r = x / mlx->zoom + mlx->x1;
	mlx->z_i = y / mlx->zoom + mlx->y1;
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
