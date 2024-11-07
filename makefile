compile: 
	nasm -f elf64 -o palindromo.o palindromo.asm
	gcc -o CalculadoraPalindromo main.c palindromo.o `pkg-config --cflags --libs gtk+-3.0`

clean:
	rm palindromo.o
	rm CalculadoraPalindromo

rebuild: clean compile

run:
	./CalculadoraPalindromo