# solitary

gcc -Wall -Wextra -Werror -g \
    -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux \
    main.o mlx_linux/libmlx.a libft/libft.a \
    -lX11 -lXext -lXrandr -lXrender -lm -lz -Wl,--no-as-needed -o solitary
