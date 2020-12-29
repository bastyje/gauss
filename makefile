all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test:
	bin/gauss dane/A dane/b
	@echo -------------------------
	@echo Poprawne wyniki X=
	@echo -29.518072
	@echo 19.759036
	@echo ------------------------- 

testAll: test test1 test2 test3 test4 test5

test1: 
	- bin/gauss dane/test1/A dane/test1/b
	@echo ------------------------- 
	@echo Poprawne wyniki X=
	@echo 0.019177
	@echo -0.377789
	@echo ------------------------- 

test2:
	- bin/gauss dane/test2/A dane/test2/b
	@echo -------------------------  
	@echo Poprawne wyniki X=
	@echo 0.001609
	@echo 1.254829
	@echo -3.220290
	@echo -1.589490
	@echo 4.058575
	@echo -------------------------

test3:
	- bin/gauss dane/test3/A dane/test3/b
	@echo ------------------------- 
	@echo Poprawne wyniki X=
	@echo -5.456300
	@echo -3.343927
	@echo 11.175936
	@echo ------------------------- 

test4:
	- bin/gauss dane/test4/A dane/test4/b
	@echo ------------------------- 
	@echo Poprawne wyniki: Macierz osobliwa
	@echo ------------------------- 

test5:
	- bin/gauss dane/test5/A dane/test5/b
	@echo ------------------------- 
	@echo Poprawne wynik testu: Zle dane wejsciowe
	@echo -------------------------  
