CC=cc

FLEX=vtl4.l

BISON=vtl4.y

parse:vtl4.tab.c lex.yy.c
	$(CC) *.c -g -o out -ll

flex:debug.yy.c
	$(CC) -o hello debug.yy.c

vtl4.tab.c:$(BISON)
	bison -d -t $(BISON) --report=all

lex.yy.c:$(FLEX)
	flex $(FLEX)

debug.yy.c:vtl-debug.l
	flex -o debug.yy.c vtl-debug.l
