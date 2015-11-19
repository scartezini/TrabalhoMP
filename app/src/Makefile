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
CC = g++
CFLAGS = -lm -g -Wall

# Definindo o 'make' como a compilacao do trabalho e nao dos testes
default: trabalho

# Para criar o executável, precisamos dos .c
trabalho: *.c 
	$(CC) *.c  $(CFLAGS) -o trabalho.out

clean: 
	rm *.out