.PHONY:all
all: read write 
read:read.cpp
	g++ $^ -o $@
write:write.cpp 
	g++ $^ -o $@
.PHONY:clean
clean:
	rm -f read write
