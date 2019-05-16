/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:22:10 by hcasanov          #+#    #+#             */
/*   Updated: 2019/05/15 18:49:35 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_get_key(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_key_exit();
	else if (key == 49)
	{
		if (mlx->move == 1)
			mlx->move = 0;
		else
			mlx->move = 1;
	}
	else if (key == 69)
		mlx->in_max += 10;
	else if (key == 78)
		mlx->in_max -= 10;
	ft_refresh_img(mlx);
	return (0);
}

int			ft_get_key_mouse(int mouse_key, int x, int y, t_mlx *mlx)
{
	if (mouse_key == 5)
	{
		mlx->x1 = (x / mlx->zoom + mlx->x1) - (x / (mlx->zoom * 1.3));
		mlx->y1 = (y / mlx->zoom + mlx->y1) - (y / (mlx->zoom * 1.3));
		mlx->zoom *= 1.3;
		mlx->in_max++;
	}
	else if (mouse_key == 4)
	{
		mlx->x1 = (x / mlx->zoom + mlx->x1) - (x / (mlx->zoom / 1.3));
		mlx->x2 = (x / mlx->zoom + mlx->x1) - (x / (mlx->zoom / 1.3));
		mlx->zoom /= 1.3;
		mlx->in_max--;
	}
	ft_refresh_img(mlx);
	return (0);
}

int			ft_mouse_cur(int x, int y, t_mlx *mlx)
{
	if (mlx->fractal == 1 && mlx->move == 1)
	{
		if ((x > 0 && x < 1800) && (y > 0 && y < 1200))
		{
			mlx->c_i = mlx->y1 + (x * 0.00166667);
			mlx->c_r = mlx->x1 + (y * 0.00333333);
			ft_refresh_img(mlx);
		}
	}
	return (0);
}
