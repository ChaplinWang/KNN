READ ME.

FILES: 
knn.h 		: header file
knn.c 		: main functions implementing leave one out cross validation
getfile 	: file to read arff info
knnfunc.c	: implementation of knn
Makefile	: build up file
result.txt 	: result of coreect rate regarding to different k value
*.arff files: arff files from course website (ionosphere.arff & autos.arff)

HOW to compile:
unzip the zip file and go to where it unziped interminal:
	1. type "make" to buld the file
	2. put ionosphere.arff & autos.arffinto current directory

How 	to run the programme:
	1. type ./knn to run it
	2. follow the prompt:

STEP 1:
=======Which file do you want to use?:========
 1.ionosphere.arff 
 2.auto.arff 
 enter 1 or 2 or 3(use your own file):  

enter 1 or 2 to select file then press enter;


STEP 2:
=======which attribute do you want to predict?========
*Select from follwing:
0 : @attribute a01 real
1 : @attribute a02 real
2 : @attribute a03 real
3 : @attribute a04 real
.......

enter the number 0,1,2,.... to choose an attribute, then press enter;


STEP 3:
========What k value do you want to use?========
please enter:


enter a positive integer k value, then press enter;


STEP 4:
check result:

......
Correct Prediction, predict b actualral b
Correct Prediction, predict b actualral b
Wrong   Prediction, predict g actualral b
Correct Prediction, predict b actualral b
========Total 351 |Correct 298 |Correct rate 0.849003========



