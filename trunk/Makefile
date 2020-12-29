all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
	@echo Poprawne wyniki X=
	@echo -29.51807
	@echo 19.75904

testAll: test test1 test2 test3 test4 test5
	test, test1, test2, test3, test4, test5

test1: all
	bin/gauss dane/test1/A dane/test1/b
	@echo Poprawne wyniki X=
	@echo 0.01918
	@echo -0.37779

test2: all
	bin/gauss dane/test2/A dane/test2/b
	@echo Poprawne wyniki X=
	@echo 0.00161
	@echo 1.25483
	@echo -3.22029
	@echo -1.58949
	@echo 4.05857

test3: all
	bin/gauss dane/test3/A dane/test3/b
	@echo Poprawne wyniki X=
	@echo -5.45630
	@echo -3.34393
	@echo 11.17594

test4: all
	bin/gauss dane/test4/A dane/test4/b
	@echo Poprawne wyniki: Macierz osobliwa

test5: all
	bin/gauss dane/test5/A dane/test5/b
	@echo Poprawne wynik testu: Zle dane wejsciowe