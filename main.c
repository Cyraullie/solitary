#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    if (!mlx)
    {
        printf("Failed to initialize MLX\n");
        return 1;
    }
    printf("MLX initialized successfully!\n");

    win = mlx_new_window(mlx, 800, 600, "MLX Test");
    if (!win)
    {
        fprintf(stderr, "Failed to create a window\n");
        return 1;
    }

    mlx_loop(mlx); // Effectuer la boucle d'événements MLX.
    return 0;
}
