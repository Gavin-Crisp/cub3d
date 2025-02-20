#include "casting.h"
#include "mlx.h"

int main(int argc, char const **argv)
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "Cub3D");
	mlx_loop(mlx);
}
