#define MAX_SAMPLE 351
#define SWAP(t,x,y) t=x;x=y;y=t;
#define MAX_ATTRIBUTES 100
#define MAX_WORD_LENGTH 30
#define MAX_CLASS 20

typedef struct Node node;

struct Node
{
    char ClassPredict;
	float NumericPredict;
    float NumericAttributes[MAX_ATTRIBUTES];
	char ClassAttributes[MAX_ATTRIBUTES][MAX_WORD_LENGTH];
    float distance;
	int validated;
};

//GLOBAL VAR
node Sample[MAX_SAMPLE];
node Validation;
int Atttr_Num;
char Atttr_Seq[MAX_ATTRIBUTES];
int Sample_Num;
int predict_attr;
int get_line (char *s, FILE *fp);

//MATH FUNC 
float square(float t);
float absv(float a, float b);


//READING ARFF FILE
void get_attributes(char* filename);
char* getword(char *ptr);
void readfile(char * filename);

//KNN functions
void getdistances(node s);
void quicksort(int low, int high);
char* CLASS_KNN(int index,int k);
float NUM_KNN(int index,int k);
