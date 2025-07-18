/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmagdano <nmagdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:40:27 by nmagdano          #+#    #+#             */
/*   Updated: 2024/04/04 20:41:05 by nmagdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx/mlx.h"

typedef struct s_ordin
{
	float	x;
	float	x1;
	float	y;
	float	y1;
}				t_ord;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pix;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	size_t				line_len;
	int					line_num;

	void				*mlx_ptr;
	void				*win_ptr;

	int					**matrix;
	unsigned int		**color_m;
	int					zoom;
	int					color;

	float				shift_x;
	float				shift_y;

	float				rad;

	float				win_height;
	float				win_wight;

	int					iso_grow;

	int					two_d;
	
	int					perspective;
	int					camera_depth;
	int					perspective_factor;
	int					win_center_w;
	int					win_center_h;
	int					yaw;
	int					pitch;

	t_data				img_d;

	float				x;
	float				y;
	float				x1;
	float				y1;
}				t_map;

//perspective.c
void			rotate_yaw(t_map **mdata, int *z);
void			rotate_pitch(t_map **mdata, int *z);
void			project_point(float *x, float *y, int *z, t_map *mdata);
void			build_perspective(t_map **mdata);

//colours.c
unsigned int	ft_gethex(char *str);
unsigned int	*check_color_matrix(char *nmbr, unsigned int *hex);

//main.c
int				close_window(t_map *mdata);
void			my_mlx_pixel_put(t_map *mdata, int x, int y, int color);

//utils.c
float			ft_fabs(float a);
int				max(int a, int b);
int				min(int a, int b);
int				adapt(int zoom, t_map *mdata);
int				free_ret(int fd, char *str, int ret);

//wireframe.c
float			get_max(float a, float b);
int				make_frameware(t_map *mdata);
void			draw_map(t_map *mdata);

//fdf_split.c
char			**fdf_split(char const *s, char c);

//parsing.c
int				get_line_len(char *file);
int				parse_map(char *file, t_map **mdata);
char			*get_file(char *argv);

//exit.c
int				exit_fdf(t_map **mdata, int error);

//zoom_shift_iso_colour.c
// 0.785398 is 45 degree in radians
void			add_isometry(float *x, float *y, int z, t_map *mdata);
void			get_color(t_map **mdata, int z, int z1);
void			zoom(t_map *mdata);
void			shift_and_centering(t_map *mdata);

//build_matrix.c
int				copy_to_matrix(int *mtx_line, char *str, int len,
					unsigned int *cl_m);
int				fill_matrix(t_map **mdata, char *file);

//cleaning_split.c
void			clean_split(char **arr, size_t n);
void			clean_all_split(char **arr, size_t n);

//get_filename.c
char			*get_file(char *argv);

//catch_events2.c
int				execute_key2(int key, t_map **mdata);
int				identify_key2(int key);

//catch_events.c
void			set_parameters(t_map **mdata);
int				identify_key(int key);
int				execute_key(int key, t_map **mdata);
void			new_window(t_map *mdata);
int				catch_key(int key, t_map *mdata);

// ****** dbg_fdf.c ******
void			print_line(int *line, size_t len);
void			print_color_matrix(t_map *mdata);
void			print_map_matrix(t_map *mdata);
void			print_pars_result(t_map *map);

#endif