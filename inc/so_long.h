/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:37:10 by barjimen          #+#    #+#             */
/*   Updated: 2024/07/01 21:53:19 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef enum e_sprites {
	FLOOR,
	PLAYER,
	COLLECT,
	WALL,
	EXIT,
	ENEMY
} t_sprites;

typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		bppx;
	int		line_length;
	int		endian;
	int     width;
    int     height;
}				t_img;

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	t_img		sprites[10]; // MLX image pointers (on the stack)
	t_img		img; //TODO: background
	//t_so_long		*map; --preguntar--
}	t_data;

typedef struct s_player
{
	int pos;
	int x;
	int y;
} t_player;

typedef struct s_map
{
	int c;
	int p;
	int e;
	int width;
	int height;
} t_map;

typedef struct s_move
{
	int player_pos;
	int	collect_num;
} t_move;


typedef struct s_so_long
{
	char		**map;
	int			map_h;
	int 		map_w;
	
	
	t_map		maps;
	t_player	player;
	t_data 		mlx_data;
	t_move		count;
	
}	t_so_long;


void	arg_handler(int argc, char **argv);
char	*map_check(t_so_long *so_long);
void 	map_iter_context(char **map, void (*f)(void *, int x, int y), void *data);
void 	is_char(void *data, int x, int y);
void 	is_map_valid(void *data, int x, int y);
void 	is_valid_p_c(void *data, int x, int y);
void	render_map(t_so_long    *so_long);
int 	length_map(char **map);
int		height_map(char **map);
void	paint_map(int width, int height, char *img, t_so_long *so_long);
char	**load_map(char *path);


/* Image Handle */
void			put_pixel_img(t_img img, int x, int y, int color);
t_img			create_image(void *mlx, int width, int height);
unsigned int	get_pixel_img(t_img img, int x, int y);
void			put_img_to_img(t_img dst, t_img src, int x, int y);
t_img			load_xpm(void *mlx, char *path);

//Hooks
int	exit_msg(char *msg);
int close_w(t_data *mlx);
int	key_hook(int keycode, t_data *mlx);
void move_handler(int keycode, t_so_long so_long);

// To library
int	ft_str_end_with(const char *str, const char *end);

//-- Window and other things

# define W_SIZE 2500
# define H_SIZE 1080

//-- Error msg --
# define FD_0 "FD error!"
# define NOT_BER "File needs to be .ber!"
# define ARG_KO "To much arguments!"
# define MAP_KO "Invalid map!"
# define MAP_CHAR_KO "Only valid 1,0,C,P,E"
# define MAP_H_KO "Height not valid!"
# define MAP_W_KO "Width not valid!"
# define MAP_LENGHT_KO "Different lenght lines!"
# define IMG_KO "Image does's exist!"
//-- Map checker error msg --
# define CPE_MSG "C,P or E error!"
# define C_MSG "Can't reach C!"
# define E_MSG "Can't reach E!"
//-- Close window --
# define C_WINDOW "Bye!"

#endif