# Este eh o Makefile para compilar o trabalho
#
# Digite 'make' para criar o executável com o programa
# e 'make clean' para  excluir o ultimo executavel criado.

# Definindo o compilador como sendo o g++, e criando macros para
# gerar o executavel do programa ou o executavel dos testes
#
# -lm math.h
# -g debugging
# -Wall warnings
#
# As outras flags sao para o gcov
CC = g++
CFLAGS = -lm -g -Wall
GCOVFLAGS = -ftest-coverage -fprofile-arcs -lncurses

# Definindo o 'make' como a compilacao do trabalho e nao dos testes
default: trabalho

# Para criar o executável, precisamos dos .c
trabalho: *.c
	$(CC) *.c  $(CFLAGS) $(GCOVFLAGS) -o trabalho.out
