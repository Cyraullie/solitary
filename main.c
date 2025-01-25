
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    void *mlx;

    mlx = mlx_init();
    if (!mlx)
    {
        printf("Failed to initialize MLX\n");
        return 1;
    }
    printf("MLX initialized successfully!\n");
    return 0;
}
