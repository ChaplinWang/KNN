/*********************************************
 *  knn.c
 *  Sample KNN implementation
 *  COMP9417 Machine Learning and Data Mining
 *  UNSW Session 1, 2012
 *	Chengbin Wang z3313137

 *  leave one out crossvalidation implementation
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include "knn.h"


int main()
{
	int i;
	int correct = 0;
	Sample_Num = 0;
	int valid = 0;
	char* filename;

	int num_knn = 0;
	int cls_knn = 0;
	int k_value = 3;

	while(!valid){
		printf("\n=======Which file do you want to use?:========\n");
		printf(" 1.ionosphere.arff \n 2.auto.arff \n enter 1 or 2 or 3(use your own file):   ");

		char c = getchar();
		if(c == '1'){
			valid = 1;
			filename = "ionosphere.arff";
		}else if(c == '2'){
			valid = 1;
			filename = "autos.arff";
		}else if(c == '3'){
			valid = 1;
			printf("\nEnter file name:");
			scanf("%s",filename);
		}else{
			valid = 0;
			printf("\n\nWrong input!!\n\n");
		}
	}

	printf("\n\n=======which attribute do you want to predict?========\n");
	printf("*Select from follwing:\n");
	readfile(filename);
	printf("\nplease select:");
	scanf("%d",&predict_attr);

	if(Atttr_Seq[predict_attr] == 'r'){
		num_knn = 1;
	}else if(Atttr_Seq[predict_attr] == 'c'){
		cls_knn = 1;
	}else{
		printf("wrong number, program shutting down\n\n");
		return 0;
	}


	printf("\n\n========What k value do you want to use?========\n\n");
	printf("\nplease enter:");
	scanf("%d",&k_value);
	
	//predict numeric value
	if(num_knn == 1){
		//leave one out 
		for(i = 0; i < Sample_Num;i++){
			int t = 0;
			while(Sample[t].validated ==1){
				t++;
			};
			Sample[t].validated = 1;

			float actural = Sample[t].NumericAttributes[predict_attr];
			float result = NUM_KNN(t,k_value);

			// if this value is within 20% of actual
			//then treat it as correct prediction
			if(absv(actural,result)/actural < 0.2){
				printf("Correct Prediction, predict %f actualral %f\n",result,actural);
				correct++;
			}else{
				printf("Wrong   Prediction, predict %f actualral %f\n",result,actural);
			}
		}
	}

	//predict classification
	else if(cls_knn == 1){
		//leave one out 
		for(i = 0; i < Sample_Num;i++){
			int t = 0;
			while(Sample[t].validated ==1){
				t++;
			};
			Sample[t].validated = 1;
			char actural = *(Sample[t].ClassAttributes[predict_attr]);
			char* result = CLASS_KNN(t,k_value);
			if(*result == actural){
				printf("Correct Prediction, predict %c actualral %c\n",*result,actural);
				correct++;
			}else{
				printf("Wrong   Prediction, predict %c actualral %c\n",*result,actural);
			}
		}

	}

	//summary
	printf("========Total %d |Correct %d |Correct rate %f========\n"
			,Sample_Num, correct,(float)correct/Sample_Num);

	return 0;
}
