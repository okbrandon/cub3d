<h1 align="center">🎮 cub3d</h1>

<p align="center">
	<b><i>cub3d is a project from the 42 school using raycasting, inspired by the most well known game that used this technique, is of course Wolfenstein 3D.</i></b><br>
</p>

<p align="center">
	<img alt="Top used language" src="https://img.shields.io/github/languages/top/okbrandon/cub3d?color=success"/>
	<img alt="Norminette run" src="https://github.com/okbrandon/cub3d/actions/workflows/42-norminette.yml/badge.svg"/>
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/okbrandon/cub3d"/>
</p>

## 📚 Table of Contents

- [👨‍🏫 Quick demonstration](#-quick-demonstration)
- [📚 Table of Contents](#-table-of-contents)
- [📦 Installation](#-installation)
- [📝 Usage](#-usage)
- [📝 Example](#-example)
- [📎 References](#-references)

## 👨‍🏫 Quick demonstration

## 📦 Installation

Clone the repository from GitHub:
```sh
git clone https://github.com/okbrandon/cub3d.git
```

Compile the `cub3d`'s mandatory executable:
```sh
make
```
> [!NOTE]  
> If you're on Linux, you'll need to install [some libraries](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux) first.

Compile the `cub3d`'s bonus executable:
```sh
make bonus
```

## 📝 Usage

Run the `cub3d` executable:
```sh
./cub3d map_name.cub
```
> On the mandatory part, you'll be able to move with `W`, `A`, `S` and `D` keys, and rotate the camera with the `←` and `→` keys.
> On the bonus part, you'll be able to move with `W`, `A`, `S` and `D` keys, rotate the camera with the `←` and `→` keys, but also using the mouse.

> [!NOTE]
> You can find some maps in the `maps` directory. (Special thanks to [mcombeau](https://github.com/mcombeau/cub3D) for the maps and textures)
> You can also create your own maps in the same format as the ones in the directory.

## 📝 Example

If you want to insert a door in your map, you'll need to add a `C` for a closed one or a `O` for an opened one in your map file, like this:
```
1111111111111111111111111
1000000000010001000000001
1000000000010001000000001
100E0000000C000O000000001
1000000000010001000000001
1000000000010001000000001
1111111111111111111111111
```
> [!NOTE]
> The `E` is the player's spawn point, and the `C` is the door's spawn point.

If you want to insert our animated sprite in your map, you'll need to add a `X` in your map file, like this:
```
1111111111111111111111111
1000000000010001000000001
1000000000010001000000001
100E0000X00C000O000000001
1000000000010001000000001
1000000000010001000000001
1111111111111111111111111
```
> [!NOTE]
> The `E` is the player's spawn point, and the `X` is the sprite's spawn point.

> [!WARNING]
> The sprite and the door only work on the bonus part.

## 📎 References

- [miniLibX - 42docs](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
- [lode's raycasting tutorial](https://lodev.org/cgtutor/raycasting.html)
- [WeirdDevers' video](https://youtu.be/g8p7nAbDz6Y?si=v6Bxxvr8yZHDMuvP)

[⬆ Back to Top](#-table-of-contents)

## 🌏 Meta

bsoubaig - bsoubaig@student.42nice.fr
evmorvan - evmorvan@student.42nice.fr