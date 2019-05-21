/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:37:39 by hcasanov          #+#    #+#             */
/*   Updated: 2019/05/21 13:35:00 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_move(t_mlx *mlx, int key)
{
	if (key == 124)
	{
		mlx->x2 -= (0.2 * (fabs(mlx->x1) + fabs(mlx->x2))) / 2;
		mlx->x1 -= (0.2 * (fabs(mlx->x1) + fabs(mlx->x2))) / 2;
	}
	else if (key == 123)
	{
		mlx->x2 += (0.2 * (fabs(mlx->x1) + fabs(mlx->x2))) / 2;
		mlx->x1 += (0.2 * (fabs(mlx->x1) + fabs(mlx->x2))) / 2;
	}
	else if (key == 126)
	{
		mlx->y2 += (0.2 * (fabs(mlx->y1) + fabs(mlx->y2))) / 3;
		mlx->y1 += (0.2 * (fabs(mlx->y1) + fabs(mlx->y2))) / 3;
	}
	else if (key == 125)
	{
		mlx->y2 -= (0.2 * (fabs(mlx->y1) + fabs(mlx->y2))) / 3;
		mlx->y1 -= (0.2 * (fabs(mlx->y1) + fabs(mlx->y2))) / 3;
	}
}

void			ft_color(t_mlx *mlx, int key)
{
	if (key == 83)
	{
		if ((mlx->red) - 1 < 0x00)
			mlx->red = 0xff;
		else
			(mlx->red) -= 3;
	}
	else if (key == 84)
	{
		if ((mlx->green) - 1 < 0x00)
			mlx->green = 0xff;
		else
			(mlx->green) -= 3;
	}
	else if (key == 85)
	{
		if ((mlx->blue) - 1 < 0x00)
			mlx->blue = 0xff;
		else
			(mlx->blue) -= 3;
	}
}

int				ft_close(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
