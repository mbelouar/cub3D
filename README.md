# cub3D
This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way. It's implemented in C using the raycasting technique and the [MiniLibX](https://github.com/codam-coding-college/MLX42) library.

![Cub3D Banner](https://i.postimg.cc/W3vSvvBL/CUB3-D-website-logo.png)

## Table of Contents

- [Demo](#demo)
- [Features](#features)
- [Collaborators](#collaborators)
- [Raycasting](#raycasting)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Contributing](#contributing)
- [License](#license)

## Demo

![Cub3D Demo](https://i.postimg.cc/fThmLCyZ/Screen-Shot-2023-12-13-at-9-52-48-PM.png)
![Cub3D Demo](https://i.postimg.cc/zvV1nK0k/Screen-Shot-2023-12-14-at-4-52-36-PM.png)
![Cub3D Demo](https://i.postimg.cc/fWjHKJ6c/Screen-Shot-2023-12-14-at-4-53-57-PM.png)

There's a famous soundtrack in the background of the game.

## Features

- Raycasting engine for 3D graphics
- Customizable maps using a simple text file
- Texture mapping for walls
- Player movement and controls
- Mouse hook move the player
- Music in the background

### Collaborators
This project must be done by two students so, I would welcome this article by thanking my peer [Mohamed Elalj](https://github.com/elaljo) since he was my collaborator throughout this project

#### Raycasting
#### Emitter
Raycasting begins with an emitter, a pivotal point in space that serves as the starting location for the rays. In a 2D scenario, this emitter could be a point on the screen, while in 3D, it might represent the position of a camera or any other designated point in space.

#### Rays
Rays are projected from the emitter in diverse directions, representing paths of light or vision. In 2D raycasting, these rays typically form a grid pattern across the screen, while in 3D, they can be cast in various patterns depending on the application.

#### Intersections
As rays traverse the virtual environment, they may intersect with objects or surfaces. The raycasting algorithm calculates essential properties at these intersections, including the distance to the object, the surface normal, and material properties.

#### Rendering
Raycasting shines in rendering by determining the color and intensity of light reaching the camera or observer at each pixel. Tracing rays from the camera through pixel positions, intersections with objects guide the determination of pixel color and shading based on object properties and the lighting model.

#### Collision Detection
Beyond rendering, raycasting excels in collision detection for games and simulations. By projecting rays from a character's position in the direction of movement, it efficiently identifies potential collisions with objects in its path.


## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/Cub3D.git




