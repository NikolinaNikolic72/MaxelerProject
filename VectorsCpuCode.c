#include <stdio.h>
#include <stdlib.h>
#include "Maxfiles.h"
#include <MaxSLiCInterface.h>
#include <math.h>



void VectorsCPU(int n, float *matA, float *matB, float *res){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                float sum = 0;
                    for (int k = 0; k < n; k++) {
                        sum += matA[i*n+k] * matB[k*n+j];
                                }
                    res[i*n+j] = sum;
                        }
                    }
                }


int main()
{   const int vectorSize= Vectors_vectorSize;
    int n= sqrt(vectorSize);
    size_t sizeBytes = vectorSize*sizeof(float);
    float *matA= malloc(sizeBytes);
    float *matB= malloc(sizeBytes);
    float *res = malloc(sizeBytes);
    float *out = malloc(sizeBytes);
    
    for(int i=0; i< vectorSize ; i++)
       matA[i]=i;
       
    for(int i=0; i < vectorSize ; i++)
       matB[i]=i;
      
    for(int i=0;i < vectorSize;i++)
      res[i]=0;

	VectorsCPU(n, matA, matB, res);

	printf("Running DFE.\n");
	Vectors(matA, matB, out);

	
}
