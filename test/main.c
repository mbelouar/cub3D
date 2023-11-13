#include </goinfre/mbelouar/homebrew/opt/glfw/include/GLFW/glfw3.h>
#include "/Users/mbelouar/MLX42/include/MLX42/MLX42.h"
#include <stdio.h>


typedef struct s_data
{
    void *mlx;
    void *win;
    void *img;
    double px;
    double py;
    int mapX;
    int mapY;
    int mapS;
    int *map;
} t_data;

// Global variable for speed
double speed = 2.50;

void draw_player(t_data *data)
{
    double size = 5.0;

    // Draw horizontal line
    for (int i = -size; i <= size; i++)
        mlx_put_pixel(data->img, (int)data->px + i, (int)data->py, 0xFFFF00FF);
    // Draw vertical line
    for (int i = -size; i <= size; i++)
        mlx_put_pixel(data->img, (int)data->px, (int)data->py + i, 0xFFFF00FF);
}

int generate_color(int red, int green, int blue)
{
    return (red << 16) | (green << 8) | blue;
}

void draw_map2D(void *param)
{
    t_data *data = (t_data *)param;
    int x, y;
    int squareSize = data->mapS - 2 ; // Adjusted size to leave a border

    // color the entire window
    // mlx_image_to_window(data->mlx, data->img, 0, 0);
    for (y = 0; y < data->mapY; y++)
    {
        for (x = 0; x < data->mapX; x++)
        {
            int index = y * data->mapX + x;
            if (data->map[index] == 1)
            {
                // Draw white square for value 1
                mlx_put_pixel(data->img, x * data->mapS + 1, y * data->mapS + 1, generate_color(255, 15, 40));
                for (int i = 0; i <= squareSize; i++)
                {
                    for (int j = 0; j <= squareSize; j++)
                        mlx_put_pixel(data->img, x * data->mapS + i + 1, y * data->mapS + j + 1, generate_color(255, 15, 40));
                }
            }
            if (data->map[index] == 0)
            {
                // Draw beige square for value 0
                mlx_put_pixel(data->img, x * data->mapS + 1, y * data->mapS + 1, 0x0000FF);
                for (int i = 0; i <= squareSize; i++)
                {
                    for (int j = 0; j <= squareSize; j++)
                        mlx_put_pixel(data->img, x * data->mapS + i + 1, y * data->mapS + j + 1, 0x0000FF);
                }
            }
            else
                mlx_put_pixel(data->img, x * data->mapS + 1, y * data->mapS + 1, generate_color(0, 0, 0));
        }
    }
    draw_player(data);
}




void key_press(void *param)
{
    t_data *data = (t_data *)param;

    if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(data->mlx);
    if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
        data->px -= speed;
    if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
        data->px += speed;
    if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
        data->py -= speed;
    if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
        data->py += speed;

    // mlx_delete_image(data->mlx, data->img);
    // draw_map2D(data);
    // draw_player(data);

    // mlx_image_to_window(data->mlx, data->img, 0, 0);

}


int main()
{
    t_data data;

    if (!(data.mlx = mlx_init(1024, 512, "Simple MinilibX Program", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(0);
	}
    if (!(data.img = mlx_new_image(data.mlx, 1024, 512)))
    {
        mlx_close_window(data.mlx);
		puts(mlx_strerror(mlx_errno));
		return(0);
    }
    if (mlx_image_to_window(data.mlx, data.img, 0, 0) == -1)
	{
		mlx_close_window(data.mlx);
		puts(mlx_strerror(mlx_errno));
		return(0);
	}
    data.px = 300;
    data.py = 300;
    data.mapX = 8;
    data.mapY = 8;
    data.mapS = 64;
    data.map = (int[]){
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1};

    mlx_loop_hook(data.mlx, draw_map2D, &data);
    mlx_loop_hook(data.mlx, key_press, &data);
    mlx_loop(data.mlx);
    mlx_terminate(data.mlx);

    return 0;
} 
