/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:02:22 by hcasanov          #+#    #+#             */
/*   Updated: 2019/04/29 17:02:25 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./fractol.h"

void	ft_set_pixel(t_mlx *mlx, int x, int y)
{
    int	px;
	int	py;
	int	result;

	if (x < 0 || x >= mlx->img_w || y < 0 || y >= mlx->img_h)
		return ;
	px = (4 * (int)x);
	py = ((int)y * 4 * mlx->img_w);
	result = (px + py);
	mlx->img_str[result] = mlx->red;
	mlx->img_str[result + 1] = mlx->green;
	mlx->img_str[result + 2] = mlx->blue;
}

void	ft_draw_fractal(t_mlx *mlx)
{
		int		x;
		int		y;
        double img_x = (mlx->x2 - mlx->x1) * mlx->zoom;
        double img_y = (mlx->y2 - mlx->y1) * mlx->zoom;

		x = 0;
		while (x < img_x && x < mlx->img_w)
		{
            y = 0;
			while (y < img_y && y < mlx->img_h)
			{
				if (ft_algo_fractal(mlx, x, y) == mlx->in_max)
                    ft_set_pixel(mlx, x + mlx->m_x, y + mlx->m_y);
				y++;
			}
			x++;
		}
}

double	ft_algo_fractal(t_mlx *mlx, int x, int y)
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

void        ft_julia(void)
{
    t_mlx   *mlx;
    if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
        ft_exit();
    ft_init_list(mlx);
    ft_creat_img(mlx);
    ft_draw_fractal(mlx);
    ft_push_img(mlx);
    mlx_hook(mlx->window, 2, (1L << 0), ft_get_key, mlx);
    mlx_mouse_hook(mlx->window, ft_get_key_mouse, mlx);
    mlx_loop(mlx->ptr);
}