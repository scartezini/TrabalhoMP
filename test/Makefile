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
# As outras flags sao para o gtest e gcov
CC = g++
CFLAGS = -lm -g -Wall
TESTFLAGS = -lgtest -lgtest_main -lpthread -ftest-coverage -fprofile-arcs

# Definindo o 'make' como a compilacao do trabalho e nao dos testes
default: teste

# Para criar os .o, precisamos dos .c e .h

# Para criar o executável, precisamos dos .c
teste: *.c 
	$(CC) ../app/src/*.c *.c $(CFLAGS) $(TESTFLAGS) -o teste.out

clean: 
	rm *.out *.gcno