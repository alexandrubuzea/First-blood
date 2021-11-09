build:
	gcc ninel.c -o ninel -Wall -Wextra
	gcc vectsecv.c -o vectsecv -Wall -Wextra
	gcc codeinvim.c -o codeinvim -Wall -Wextra
	gcc nomogram.c -o nomogram -Wall -Wextra
clean:
	rm -f ninel vectsecv codeinvim nomogram
.PHONY: clean