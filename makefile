# SPDX-License-Identifier: GPL-2.0+
# Lab 2: Brandon Carl

.PHONY: carlb2-lb2.tar.gz
carlb2-lb2.tar.gz: carlb2-lb2.tar
	gzip carlb2-lb2.tar

CC = gcc
CFLAGS = -Wall -ansi -std=c99

.PHONY: all
all: q1 q2 q3 q7 shell

.PHONY: q1
q1: q1.c
	$(CC) $(CFLAGS) -o q1 q1.c

.PHONY: q2
q2: q2.c
	$(CC) $(CFLAGS) -o q2 q2.c

.PHONY: q3
q3: q3.c
	$(CC) $(CFLAGS) -o q3 q3.c

.PHONY: q7
q7: q7.c
	$(CC) $(CFLAGS) -o q7 q7.c

.PHONY: shell
shell: shell.c
	$(CC) $(CFLAGS) -o shell shell.c