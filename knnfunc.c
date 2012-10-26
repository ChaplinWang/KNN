/*********************************************
 *  knnfunc.c
 *  Sample KNN implementation
 *  COMP9417 Machine Learning and Data Mining
 *  UNSW Session 1, 2012
 *	Chengbin Wang z3313137

 *  KNN functions implementation
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "knn.h"



float square(float t){
	return t*t;
}

float absv(float a, float b){
	if (a > b) return a-b;
	return b-a;
}

// CALCULATE DISTANCE OF EACH NODE
void getdistances(node s){
	float dist;
	int i,j,k;
	for(i = 0; i < Sample_Num; i++){
		for(j = 0, dist = 0, k = 0; j < Atttr_Num; j++, k++){
			//skip the prediction attribute
			if(j == predict_attr){
				continue;
			}
			// if it is an real number, use ecludiean distance
			if(Atttr_Seq[k] == 'r'){
				dist += square(s.NumericAttributes[j] - Sample[i].NumericAttributes[j]);
			}else{
			//if it is a class, if same content, unchange distance else increment distance
				if(strcmp(s.ClassAttributes[j],Sample[i].ClassAttributes[j])){
					dist++;
				}
			}
		}
		Sample[i].distance = sqrt(dist);
	}
}

// quick sort the Nodes with distances
void quicksort(int low, int high){

	int i,j,piviot;
	node t;

	if(high > low){
		piviot = (low+high)/2;
		SWAP(t,Sample[low],Sample[piviot]);

		i = low + 1;
		j = high;
		while(i <= j){
			while(Sample[i].distance <= Sample[low].distance
				  && i <= high){i++;}
			while(Sample[j].distance >= Sample[low].distance
				  && j > low){j--;}
			if(i < j){
				SWAP(t,Sample[i],Sample[j]);
			}
		}
		SWAP(t,Sample[low],Sample[j]);
		quicksort ( low, j - 1 );
		quicksort ( j + 1, high );
	}
}


// KNN to predict classification
char* CLASS_KNN(int index,int k){
	int ClassPredict[MAX_CLASS];
	char *Classes[MAX_CLASS];
	int i,j,ClassCount;
	int max = 0;
	int best = 0;
	ClassCount = 0;

	getdistances(Sample[index]);
	quicksort(0,Sample_Num-1);

	//initialise
	for(i = 0; i < MAX_CLASS; i++){
		ClassPredict[i] = 0;
		Classes[i] = "NOT DEFINED";
	}

	//vote by k nearest neibour
	for(i= 1; i <= k; i++){
		for(j = 0; j < MAX_CLASS; j++){
			if(!strcmp(Sample[i].ClassAttributes[predict_attr],Classes[j])){
				ClassPredict[j]++;
				break;
			}
		}

		if(j == MAX_CLASS){
			Classes[ClassCount] = Sample[i].ClassAttributes[predict_attr];
			ClassPredict[ClassCount]++;
			ClassCount++;
		}
	}
	
	//collect vote, pick most voted
	for(j = 0; j < ClassCount; j++){
		if(max < ClassPredict[j]){
			max = ClassPredict[j];
			best = j;
			
		}
	}

	//return most voted
	return Classes[best];
}


//KNN to predict numeric value
float NUM_KNN(int index,int k){
	int i;
	float result = 0;

	getdistances(Sample[index]);
	quicksort(0,Sample_Num-1);

	
	// vote and get average
	for(i = 1; i <= k ; i++){
		result += Sample[i].NumericAttributes[predict_attr];
	}
		result = result/k;
	return result; 

}

