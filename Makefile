knn: knn.o getfile.o knnfunc.o
	gcc -o knn knn.o getfile.o knnfunc.o

knn.o: knn.c
	gcc -Werror -Wall -O0 -c knn.c

getfile.o: getfile.c
	gcc -Werror -Wall -O0 -lm -c getfile.c

knnfunc.o: knnfunc.c
	gcc -Werror -Wall -O0 -lm -c knnfunc.c
