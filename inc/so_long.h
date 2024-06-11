/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:37:10 by barjimen          #+#    #+#             */
/*   Updated: 2024/06/11 22:32:31 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bppx;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_img		img;
	//t_so_long		*map; --preguntar--
}	t_data;

typedef struct s_so_long
{
	char		**map;
	int			map_h;
	int 		map_w;
	
	t_data 		mlx_data;
	
}	t_so_long;


char	**arg_handler(int argc, char **argv, char **map);
char	*map_check(char **map);
void	is_char(char **map, int width, int height);
int		is_map_valid(char **map, int width, int height);
void	render_map(t_so_long    *so_long);
int 	length_map(char **map);
int		height_map(char **map);


//-- Window and other things

# define w_size 1920
# define h_size 1080


//-- Error msg --
# define FD_0 "FD error!"
# define NOT_BER "File needs to be .ber!"
# define ARG_KO "To much arguments!"
# define MAP_KO "Invalid map!"
# define MAP_CHAR_KO "Only valid 1,0,C,P,E"
# define MAP_H_KO "Height not valid!"
# define MAP_W_KO "Width not valid!"
# define MAP_LENGHT_KO "Different lenght lines!"
//-- Map checker error msg --
# define CPE_MSG "C,P or E error!"
# define C_MSG "Can't reach C!"
# define E_MSG "Can't reach E!"
//-- Close window --
# define C_WINDOW "Bye!"

#endif