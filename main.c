/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcasanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:52:51 by hcasanov          #+#    #+#             */
/*   Updated: 2019/04/29 15:52:53 by hcasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_key_exit(void)
{
	exit(EXIT_SUCCESS);
}

void    ft_usage(void)
{
    ft_putstr("usage : fractol [fractals]\n\n    Fractals disponibles:\n\n---> Julia\n---> Mandelbrot\n---> XXXX\n\n");
}

void		ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int     main(int argc, char **argv)
{
    t_mlx   *mlx;

    if (argc == 2)
    {
        
        if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
            ft_exit();
        ft_init_list(mlx);
        if (ft_strcmp("Julia", argv[1]) == 0)
        {
            mlx->fractal = 1;
            ft_fractal(mlx);
        } 
        else if (ft_strcmp("Mandelbrot", argv[1]) == 0)
        {
            mlx->fractal = 2;
            ft_fractal(mlx);
        } 
        // else if (ft_strcmp("XXXXXXX", argv[1]) == 0)
            // ft_XXXXXX();
        else
            ft_usage();
    }
    else
        perror("Nombre de parametre");
    return (0);
}