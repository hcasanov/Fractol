/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 19:45:15 by hcasanov          #+#    #+#             */
/*   Updated: 2019/05/10 19:45:18 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_algo_mandelbrot(t_mlx *mlx, int x, int y)
{
    double  tmp;
    double  i;

    mlx->z_r = 0;
    mlx->z_i = 0;
    mlx->c_r = x / mlx->zoom + mlx->x1;
    mlx->c_i = y / mlx->zoom + mlx->y1;
    i = 0;
    while ((mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i) < 4 && i < mlx->k_max)
    {
        tmp = mlx->z_r;
        mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
        mlx->z_i = 2 * mlx->z_i * tmp + mlx->c_i;
        i++;
    }
    return (i);
}

void	ft_draw_mandelbrot(t_mlx *mlx)
{
		int		x;
		int		y;
        double img_x = (mlx->x2 - mlx->x1) * mlx->zoom;
        double img_y = (mlx->y2 - mlx->y1) * mlx->zoom;
        double  k;

        printf("FAIL\n");
		x = 0;
		while (x < img_x )
		{
            y = 0;
			while (y < img_y)
			{
                k = ft_algo_mandelbrot(mlx, x, y);
                if (k != mlx->k_max && k > 1)
                    ft_set_pixel(mlx, x + mlx->m_x, y + mlx->m_y, k);
				y++;
			}
			x++;
		}
}