#Makefile中非常三个变量：
# $@:目标文件，$^:所有的依赖文件，$<:第一个依赖文件
$(CC) = gcc
.PHONY:clean

all: libtest.so main
libtest.so: test.c
	@echo $@
	@echo $<
	@echo $^
	$(CC) -fPIC -shared -o $@ $^
main: main.c
	$(CC) -L ./ -ltest -o $@ $^

clean:
	rm libtest.so main
