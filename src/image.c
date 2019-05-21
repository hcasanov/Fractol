/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:10:11 by hcasanov          #+#    #+#             */
/*   Updated: 2019/05/21 13:31:45 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_push_img(t_mlx *mlx)
{
	if (!(mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img_ptr, 0, 0)))
		ft_exit(mlx);
}

void	ft_creat_img(t_mlx *mlx)
{
	int	bpp;
	int	s_l;
	int	endian;

	bpp = 32;
	s_l = (mlx->screen_w) * 4;
	endian = 0;
	if (!(mlx->img_ptr = mlx_new_image(mlx->ptr, mlx->img_w, mlx->img_h)))
		ft_exit(mlx);
	if (!(mlx->img_str = mlx_get_data_addr(mlx->img_ptr, &bpp, &s_l, &endian)))
		ft_exit(mlx);
}

void	ft_set_pixel(t_mlx *mlx, int x, int y, double c)
{
	int	px;
	int	py;
	int	result;

	if (x < 0 || x >= mlx->img_w || y < 0 || y >= mlx->img_h)
		return ;
	px = (4 * x);
	py = (y * 4 * mlx->img_w);
	result = (px + py);
	mlx->img_str[result] = mlx->red * (c / 50);
	mlx->img_str[result + 1] = mlx->green * (c / 50);
	mlx->img_str[result + 2] = mlx->blue * (c / 50);
}

void	ft_refresh_img(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img_ptr);
	ft_creat_img(mlx);
	if (mlx->fractal == 1)
		ft_draw_julia(mlx);
	else if (mlx->fractal == 2)
		ft_draw_mandelbrot(mlx);
	else if (mlx->fractal == 3)
		ft_draw_burningship(mlx);
	ft_push_img(mlx);
}
