#
# Este eh o Makefile geral, que realiza os outros makefiles

# Definindo o 'make' como a compilacao do trabalho e nao dos testes
default: trabalho

# Criando o executavel do programa
trabalho: 
	cd app/src; make

# Make para rodar o executavel do programa
rodar:
	cd app/src; ./trabalho.out

# Criando o executavel de testes
teste:
	cd app/test; make

# Make para rodar o executavel de teste
testar:
	cd app/test; ./teste.out

# Make para executar o gcov
gcov:
	cd app/src; gcov *.c
	cd app/test; gcov *.c

# Make para realizar o cppcheck
cppcheck:
	cd app/src; cppcheck *.c
	cd app/test; cppcheck *.c

# Make para limpar todos os arquivos gerados
clean: 
	rm app/src/*.gcno app/src/*.out app/src/*.c.gcov app/src/*.h.gcov app/src/*.gcov app/src/*.gcda app/test/*.gcno app/test/*.out app/test/*.c.gcov app/test/*.h.gcov app/test/*.gcov app/test/*.gcda