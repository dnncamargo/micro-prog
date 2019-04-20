gcc -c alusimulation.c
gcc -c processorarchitecture.c
gcc -c baseconv.c
gcc -c system.c
gcc -c main.c
gcc -o main main.c baseconv.c processorarchitecture.c alusimulation.c system.c -lm
