#
#   Copyright (c) 2023 Mihai Zegheru
#   All rights reserved.
#

CC=gcc
CFLAGS=-Wall -Wextra -pedantic

SOURCES=main.c\

build:
	$(CC) $(CFLAGS) $(SOURCES) -o run.exe -lm
