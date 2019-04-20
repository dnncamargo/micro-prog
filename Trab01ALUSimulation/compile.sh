#!/bin/bash
echo "============COMPILING PROCESS============"
gcc -c alusimulation.c
gcc -c processorarchitecture.c
gcc -c baseconv.c
gcc -c sys.c
gcc -c main.c
gcc -o main main.c baseconv.c processorarchitecture.c alusimulation.c sys.c -lm
