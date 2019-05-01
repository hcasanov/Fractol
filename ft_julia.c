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

		x = 0;
		y = 0;
		while (x < 1800)
		{
			while (y < 1200)
			{
				ft_algo_fractal(mlx, x, y);
				y++;
			}
			x++;
		}
}

void	ft_algo_fractal(t_mlx *mlx, int x, int y)
{
	int		in_max = 50;
    int     c;
    int     z;
    int     i;

    i = 0;
    c = x + i * y;
    z = 0;

    while (z < 2 && i < in_max)
    {
        z = z * z + c;
        i++;
    }
    if (i == in_max)
    {
        ft_set_pixel(mlx, x, y);
    }
}

void        ft_julia(void)
{
    t_mlx   *mlx;
    if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
        ft_exit();
    ft_init_list(mlx);
    ft_creat_img(mlx);
    //ft_set_pixel(mlx);
    ft_push_img(mlx);
    // ft_push_img(mlx);
    //printf("%lu\n", strlen(mlx->img_str));
    // mlx_new_window(mlx->ptr, 1800, 1200, "Test");
    mlx_loop(mlx->ptr);
}