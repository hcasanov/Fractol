/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:02:22 by hcasanov          #+#    #+#             */
/*   Updated: 2019/04/29 17:02:25 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./fractol.h"

void        ft_fractal(t_mlx *mlx)
{
    ft_creat_img(mlx);
    if (mlx->fractal == 1)
    {
        ft_init_list_julia(mlx);
        ft_draw_julia(mlx);
    }
    else if (mlx->fractal == 2)
    {
        ft_init_list_mandelbrot(mlx);
        ft_draw_mandelbrot(mlx);
    }
    ft_push_img(mlx);
    mlx_hook(mlx->window, 2, (1L << 0), ft_get_key, mlx);
    mlx_mouse_hook(mlx->window, ft_get_key_mouse, mlx);
    mlx_hook(mlx->window, 6, 0, ft_mouse_cur, mlx);
    mlx_loop(mlx->ptr);
}