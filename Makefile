all: qa qb qc qd qe qf

qa:
	gcc -g a.c -o a.out
qb:
	gcc -g b.c -o b.out
qc:
	gcc -g c.c -o c.out
qd:
	gcc -Wall -g -std=c11 -o queue queue.c -lpthread
qe:
	gcc -g mpool.c -o e.out
qf:
	gcc -g f.c -o f.out

clean:
	rm -f a.out b.out c.out queue e.out f.out

indent:
	clang-format --verbose -i *.c

.PHONY: all qa qb qc qd qe qf clean indent
