# ifndef FDF_H
# define FDF_H
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"

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

	int	**matrix;	
}				t_map;

//save_map.c
int		*split_digits(char *str, size_t len);
void	save_map(int fd, t_map **mdata);

//parsing.c
int		matrix_nums_only(char *str);
size_t	get_line_len(char *str);
int		parse_map(int fd, t_map **mdata);
int		check_fd(int fd);
char	*get_file(char *argv);

//exit.c
void	*clean_saved_map(t_map **mdata);
int		exit_fdf(t_map **mdata, int error);

//dbg_fdf.c
void	print_map_matrix(t_map *mdata);
void	print_pars_result(t_map *map);

#endif