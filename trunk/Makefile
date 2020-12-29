all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b

testAll: test test1 test2 test3 test4 test5
	test, test1, test2, test3, test4, test5

test1: all
	bin/gauss dane/test1/A dane/test1/b

test2: all
	bin/gauss dane/test2/A dane/test2/b

test3: all
	bin/gauss dane/test3/A dane/test3/b

test4: all
	bin/gauss dane/test4/A dane/test4/b

test5: all
	bin/gauss dane/test5/A dane/test5/b