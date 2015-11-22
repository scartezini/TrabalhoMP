# Este eh o Makefile para compilar o teste
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
# As outras flags sao para o gtest e gcov
CC = g++
CFLAGS = -lm -g -Wall
TESTFLAGS = -lgtest -lgtest_main -lpthread
GCOVFLAGS = -ftest-coverage -fprofile-arcs

# Definindo os .c como uma variavel
SRCS = ../app/src/Adaptadores.c ../app/src/Cidades.c ../app/src/Geradores.c ../app/src/Interconexoes.c ../app/src/Geral.c

# Definindo o 'make' como a compilacao do trabalho e nao dos testes
default: teste

# Para criar o executável, precisamos dos .cpp
teste: *.c
	$(CC) $(SRCS) *.c $(CFLAGS) $(GCOVFLAGS) $(TESTFLAGS) -o teste.out
