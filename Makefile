1: 1.c
	@gcc 1.c -o 1 -pthread 
run: 1
	@rm -f data.txt
	@./1
plot: data.txt
	@python pltll.py
data.txt: 1
	@rm -f data.txt
	@./1