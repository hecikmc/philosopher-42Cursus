# SO_LONG 42cursus

## Description 

<p align="center">
<img width="837" alt="Screen Shot 2023-04-13 at 4 46 17 PM" src="https://user-images.githubusercontent.com/121127625/231797144-76790ce9-3a86-4421-8618-e3db4af849b8.png">
</p>

This project is a small 2D game, whose requirements are:
* Only 1 player.
* Only 1 exit. 
* The map is closed by the borders.
* An unknown number of collectibles (minimum one).
* The goal of the player is to collect all the collectibles before leaving the map in the fewest number of moves.
* Each movement of the player will be counted and displayed by the terminal.

<table align="center">
  <td>
  
  ![mandatory solong](https://user-images.githubusercontent.com/121127625/231807710-bab6d89a-d62f-4e3f-86dd-a876caec6850.gif)
  
  </td>
</table>


#### :checkered_flag: Bonus part :checkered_flag: 

* Enemies are included on the map (between 0 and 2).
* The player loses if he is hit by an enemy.
* Each movement of the player will be counted and displayed by the game screen.
* Sprite animations are included. 

<table align="center">
  <td>
  
  ![bonus so_long](https://user-images.githubusercontent.com/121127625/231814053-969c7a7b-31b5-445e-9101-bbba881d810d.gif)

  </td>
</table>


* Project developed in 'C' language.
* The project compiles with the 'norma' (Norminette).
* The makefile compiles the program (and the librarys needed, libft and MLX42) with the name: **so_long**


### Mandatory part

<p align="center">
<img width="609" alt="Screen Shot 2023-04-13 at 5 54 20 PM" src="https://user-images.githubusercontent.com/121127625/231816234-a99d65ae-da05-4128-826f-a992559f02a2.png">
</p>

The program receives as a parameter the map to play on (.ber extension), if is not valid, an advice will be show. 
The player is able to move in 4 directions: up, down, left or right. The W, A, S and D keys will be used to move the player. The player cannot enter inside the walls.

To exit the game simply close the window with ESC or by clicking on the :x:

### Maps :earth_africa:

The available maps are in the 'map' folder. 
The map is composed of only 5 characters: 0 for an empty space, 1 for a wall, C for a collectible, E to exit the map, and P for starting position of the player.

In order to play, the map must have only one exit, at least one object to collect, and only one player. The map must be rectangular and be closed by the borders with walls. 

The program checks all the requirements as well as if it can be solved, for example if the exit is not accessible by the player.

If something is wrong on the map, an error message will appear indicating the type of error found on the map.

Maps containing enemies have an 'f' in the name (bonus).

Example of valid map:
```shell
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```


## Usage

You can use the rule **'make'** to compile the program and run it.
```shell
$> make 
```

And to compile the bonus **'make bonus'**
```shell
$> make bonus
```

You can ran the game using:
```shell
$> ./so_long map/nameofmap.ber
$> ./so_long_bonus map/nameofmap.ber
```

## Resources - MLX42 graphic library by 42

To implement this project it is necessary to use a version of the [MLX42 library](https://github.com/codam-coding-college/MLX42).

MLX42 is a performant, easy to use, cross-platform, minimal windowing graphics library to create graphical applications without having to work directly with the native windowing framework of the given operating system.

It provides primitive tools to draw textures onto the window as well as modifying them at runtime as they get displayed on the window.

### How to install?

First, you need to install the platform [brew](https://github.com/kube/42homebrew) to be able to download the library MLX42. 

And then, use the next comand to download and install the **brew**:
```shell
curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
```

Use the next comand to install **MLX42 library**:
```shell
brew install glfw
```
