gcc -c cardnumber.c
gcc -c filehandler.c
gcc -o cardnumber cardnumber.c filehandler.c -lm
