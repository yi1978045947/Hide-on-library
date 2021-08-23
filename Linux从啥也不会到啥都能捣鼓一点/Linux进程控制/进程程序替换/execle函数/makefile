.PHONY:all 
all:myexe mycmd
myexe:myexe.c
	gcc $^ -o $@
mycmd:mycmd.c
	gcc $^ -o $@
.PHONY:clean
clean:
	rm -f myexe mycmd
