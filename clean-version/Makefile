CFLAGS=-I. -g

project = mypas

relocatables = $(project).o lexer.o parser.o keywords.o

executable = $(project)

$(executable): $(relocatables)
	cc -o $(executable) $(relocatables) -lm
clean:
	$(RM)  $(relocatables)
mostlyclean: clean
	$(RM) $(executable) *~
indent:
	indent -nfca -nsc -orig - nuts - ts4 *.[ch]
