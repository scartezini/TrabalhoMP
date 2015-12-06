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
	cd test; make

# Make para rodar o executavel de teste
testar:
	cd test; ./teste.out

# Make para executar o gcov
gcov:
	cd app/src; gcov *.c
	cd test; gcov *.c

# Make para realizar o cppcheck
cppcheck:
	cd app/src; cppcheck *.c

# Make para checar memory leak com o Valgrind
valgrind:
	cd app/src; valgrind --track-origins=yes --leak-check=full ./trabalho.out

# Make para instalar o gource
instalar_gource:
		sudo apt-get install gource

# Make para visualizar o gource
gource:
	gource -s 1

# Make para limpar todos os arquivos gerados
clean:
	rm app/src/*.gcno app/src/*.out app/src/*.c.gcov app/src/*.h.gcov app/src/*.gcov app/src/*.gcda test/*.gcno test/*.out test/*.c.gcov test/*.h.gcov test/*.gcov test/*.gcda
