# ifndef FDF_H
# define FDF_H
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "libft/libft.h"
#include "mlx/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pix;
	int		line_length;
	int		endian;
}				t_data;

typedef	struct s_map
{
	size_t	line_len;
	int	line_num;

	void	*mlx_ptr;
	void	*win_ptr;

	int	**matrix;
	int		zoom;
	int		color;

	int		shift_x;
	int		shift_y;

	float		rad;

	int		win_height;
	int		win_wight;
}				t_map;

//frameware.c
int	make_frameware(float x, float x1, float y, float y1, t_map *mdata);
void	draw_map(t_map *mdata);

//fdf_split.c
char	**fdf_split(char const *s, char c);

//save_map.c
int		*split_digits(char *str, size_t len);
void	save_map(int fd, t_map **mdata);

//parsing.c
int		matrix_nums_only(char *str);
int		get_line_len(char *file);
int		parse_map(char *file, t_map **mdata);
int		check_fd(int fd);
char	*get_file(char *argv);

//exit.c
void	*clean_saved_map(t_map **mdata);
int		exit_fdf(t_map **mdata, int error);

//dbg_fdf.c
void	print_line(int *line, size_t len);
void	print_map_matrix(t_map *mdata);
void	print_pars_result(t_map *map);

//main.c
int	deal_key(int key, t_map *mdata);

#endif