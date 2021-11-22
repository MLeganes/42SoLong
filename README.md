# 42SoLong

This project is a very small 2D game.

## To do list

- [x] makefile - relinking.
- [x] map checks new line at the end.
- [x] max screen size.
- [ ] gif for the readme :nerd_face:

## Prerequisites

This project is for macOS, using MiniLibX requires AppKit and X11. There is a MiniLibX for Linux, no used in this project.

## Installation

* `git clone git@github.com:MLeganes/42SoLong.git` this repository
* `cd 42SoLong`

## Running
 
* `make`
* `make bonus` 

* Star game with map ``` ./so_long map/pacman1.ber ```
* Star bonus game ``` ./so_long map/pacman1b.ber ```

## Useful Links

* [minilibx-42docs](https://harm-smits.github.io/42docs/libs/minilibx)
* [minilibx-graphics](https://github.com/qst0/ft_libgfx#graphics-branch-link-dump)
* [minilibx-images](https://github.com/keuhdall/images_example)
* [minilibx-more](https://github.com/qst0/ft_libgfx)

* Man for MiniLibX - Simple Graphical Interface Library

		man /usr/share/man/man3/mlx.1
		man /usr/share/man/man3/mlx_loop.1
		man /usr/share/man/man3/mlx_new_image.1
		man /usr/share/man/man3/mlx_new_window.1
		man /usr/share/man/man3/mlx_pixel_put.1

## Sanitize (To test)

Add -g in gcc command.

	-fsanitize=leak
	-fsanitize=address

* [sanitize](https://github.com/google/sanitizers/wiki/AddressSanitizerLeakSanitizer)