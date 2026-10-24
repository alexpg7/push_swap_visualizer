#!/bin/bash
git clone https://github.com/42Paris/minilibx-linux.git mlx_linux


cd mlx_linux
git log --oneline
git checkout 7dc53a411a7d4ae286c60c6229bd1e395b0efb82

make -C mlx_linux

