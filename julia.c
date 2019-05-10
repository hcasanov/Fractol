/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:58:44 by hcasanov          #+#    #+#             */
/*   Updated: 2019/05/10 18:58:46 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./fractol.h"

void	ft_draw_julia(t_mlx *mlx)
{
		int		x;
		int		y;
        double img_x = (mlx->x2 - mlx->x1) * mlx->zoom;
        double img_y = (mlx->y2 - mlx->y1) * mlx->zoom;
        double  c;

		x = 0;
		while (x < img_x )
		{
            y = 0;
			while (y < img_y)
			{
                c = ft_algo_julia(mlx, x, y);
                if (c != mlx->in_max && c > 1)
                    ft_set_pixel(mlx, x + mlx->m_x, y + mlx->m_y, c);
                
				y++;
			}
			x++;
		}
}

double	ft_algo_julia(t_mlx *mlx, int x, int y)
{
    double  tmp;
    double  i;

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