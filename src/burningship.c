/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:31:14 by hcasanov          #+#    #+#             */
/*   Updated: 2019/05/15 18:48:41 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_draw_burningship(t_mlx *mlx)
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
			k = ft_algo_burningship(mlx, x, y);
			if (k != mlx->in_max && k > 1)
				ft_set_pixel(mlx, x, y, k);
			y++;
		}
		x++;
	}
}

double		ft_algo_burningship(t_mlx *mlx, int x, int y)
{
	double	tmp;
	double	i;

	mlx->c_r = x / mlx->zoom + mlx->x1;
	mlx->c_i = y / mlx->zoom + mlx->y1;
	mlx->z_r = 0;
	mlx->z_i = 0;
	i = 0;
	while ((mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i) < 4 && i < mlx->in_max)
	{
		tmp = mlx->z_r;
		mlx->z_r = fabs(mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r);
		mlx->z_i = fabs(2 * mlx->z_i * tmp + mlx->c_i);
		i++;
	}
	return (i);
}
