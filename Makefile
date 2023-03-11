12:12.c
	@gcc 12.c -o 12
run: 12
	@rm -f mata.txt
	@./12
makeExecutable: bash1.sh bashy2.sh bashy3.sh
	@chmod +x bashy1.sh
	@chmod +x bashy2.sh
	@chmod +x bashy3.sh