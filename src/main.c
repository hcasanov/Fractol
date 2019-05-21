/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:52:51 by hcasanov          #+#    #+#             */
/*   Updated: 2019/05/13 21:06:25 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_key_exit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img_ptr);
	exit(EXIT_SUCCESS);
}

void		ft_usage(void)
{
	ft_putstr("usage : fractol [fractals]\n\n    Fractals disponibles:\n\n");
	ft_putstr("---> Julia\n---> Mandelbrot\n---> Burningship\n\n");
	exit(EXIT_FAILURE);
}

void		ft_exit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img_ptr);
	exit(EXIT_FAILURE);
}

void		ft_fractal_index(char *str, t_mlx *mlx)
{
	if (ft_strcmp("Julia", str) == 0)
		mlx->fractal = 1;
	else if (ft_strcmp("Mandelbrot", str) == 0)
		mlx->fractal = 2;
	else if (ft_strcmp("Burningship", str) == 0)
		mlx->fractal = 3;
	else
		ft_usage();
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		ft_fractal_index(argv[1], &mlx);
		ft_init_list(&mlx);
		ft_fractal(&mlx);
	}
	else
		ft_usage();
	return (0);
}
