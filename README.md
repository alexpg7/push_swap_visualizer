# 📊push_swap_visualizer ![Static Badge](https://img.shields.io/badge/Original-blue?style=for-the-badge)
![Static Badge](https://img.shields.io/badge/c-grey?style=flat&logo=c)
![Static Badge](https://img.shields.io/badge/Makefile-green?style=flat&logo=AnkerMake)
![Static Badge](https://img.shields.io/badge/status-completed-green?style=flat)

A program to visualize the solution of push_swap. Using 42's MiniLibX and Libft.

## :hammer::book: Compilation and usage
Firstly, copy the repository into the same folder where your `push_swap` file.

> [!WARNING]
> Your `push_swap` file must exist

```bash
git clone https://github.com/alexpg7/push_swap_visualizer.git push_swap_visualizer && cd push_swap_visualizer
```

Before compiling, make sure you have the correct permissions to compile the MiniLibX.

```bash
chmod 777 mlx_linux/configure
```

Now, inside the `push_swap_visualizer` folder, just execute the following command:

```bash
make exec ARG="9 8 1 2 5 4 3 7 6"
```

> [!CAUTION]
> Sometimes the compilation of MiniLibX can give trouble with the `-lbsd` flag. Just execute make again until you have the `ps_visualizer` executable.

Where you can put whatever combination of numbers you want. The program uses the numbers (`ARG`) to feed the arguments of `push_swap`, the output is _piped_ to `ps_visualizer` with the same arguments (`ARG`).

Of course, you can also try to execute
```bash
./ps_visualizer 9 8 1 2 5 4 3 7 6
```
and figure out the solution by yourself 😆

If you want to try a specific number of arguments (for example, 100), execute this command:


```bash
make exec ARG="$(echo $(shuf -i 1-100 -n 100))"
```

## 🎮Controls

Once the **mlx** window has oppened up, use your keys ⬅️ and ➡️ (Linux) to go back and forth through all the instructions your `push_swap` has outputed. To exit the program, just click the close button of the window (the cross ❎).

## ❔Example

The continuous pressing of the right arrow, for 100 numbers, should look like this (sped up):

![til](https://github.com/alexpg7/Images/blob/main/ps_visualizer/Visualizer.gif)

