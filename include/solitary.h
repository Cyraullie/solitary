#ifndef SOLITARY_H
# define SOLITARY_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_var {
	void	*mlx;
	void	*win;
}				t_var;

#endif