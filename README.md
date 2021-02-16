# 42cursus' miniRT

Development repo for 42cursus' **miniRT** project.

For further information about **42cursus** and this project, please refer to [42cursus repo](https://github.com/appinha/42cursus).

---

![Code size in bytes](https://img.shields.io/github/languages/code-size/appinha/42cursus-02-miniRT?color=blueviolet)
![Number of lines of code](https://img.shields.io/tokei/lines/github/appinha/42cursus-02-miniRT?color=blueviolet)
![Code language count](https://img.shields.io/github/languages/count/appinha/42cursus-02-miniRT?color=blue)
![GitHub top language](https://img.shields.io/github/languages/top/appinha/42cursus-02-miniRT?color=blue)
![GitHub last commit](https://img.shields.io/github/last-commit/appinha/42cursus-02-miniRT?color=brightgreen)

## Contents

* **files in root:** source code developed for the project.

Note: files contain only mandatory requirements.

For extensive documentation on the source code, please refer to the [projects' folder](https://github.com/appinha/42cursus/tree/master/02-minirt) in the 42cursus repo.

## Usage

### Installing MiniLibX

```
sudo apt-get install -y libxext-dev && sudo apt-get install -y libxrandr-dev && sudo apt-get install -y libx11-dev && sudo apt-get install -y libbsd-dev && sudo apt-get install -y libssl-dev

cd /usr/local/man/ && sudo mkdir man1

cd ~ && git clone https://github.com/42Paris/minilibx-linux.git && cd minilibx-linux && make

sudo cp man/man1/* /usr/local/man/man1/ && sudo cp libmlx.a /usr/local/lib/ && sudo cp mlx.h /usr/local/include/
```

* To show MiniLibX 's manual page: `man mlx`
* To compile: `clang -Wall -Wextra -Werror main.c -lbsd -lmlx -lXext -lX11`

### Compilation

```shell
make
```

### Execution

```shell
./miniRT <scene-file.rt>
./miniRT <scene-file.rt> --save
```

## Useful Links

* [42Paris/minilibx-linux](https://github.com/42Paris/minilibx-linux)
* [Tutorial on MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
* [Useful links and info by lcouto et al](https://www.notion.so/miniRT-5f6fcdf6d05e4742b6c38f0588f12436)
