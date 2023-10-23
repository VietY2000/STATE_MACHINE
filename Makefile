build: main.c screen.c shell.c tsm.c buzzer.c
	gcc $^ -o main.exe


run:
	main.exe