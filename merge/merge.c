#include <stdio.h>
#include <stdlib.h>
/***************
* Jeffrey Marple
* Lab 7, 2400
****************/

void merge(int array1[], int length1, int array2[], int length2, int result[]);

int main(){
	
	int arr1Size = 0;
	int arr2Size = 0;
	int* arr1;
	int* arr2;
	int newNum[1];
	int* resultArr;

	printf("Enter how many values for list 1: ");
	arr1Size = readInt();
	arr1 = (int*)malloc(arr1Size * sizeof(int));
 	
	printf("Enter how many values for list 2: ");
	arr2Size = readInt();
	arr2 = (int*)malloc(arr2Size * sizeof(int)); 


	//get vals for 1st array
	printf("Enter %d interger values for List 1 one at a time: \n", arr1Size);
	for(int i=0; i<arr1Size; i++){
		//store input number
		newNum[0] = readInt();
		resultArr = (int*)malloc((arr1Size) * sizeof(int));
		//sort newNum into list appropriately
		merge(arr1, i, newNum, 1, resultArr);
		

		//copy contents from result array into arr1
		for(int j=0; j<arr1Size; j++){
			arr1[j] = resultArr[j];
		}		

		free(resultArr);
	}



	printf("Enter %d interger values for List 2 one at a time: \n", arr2Size);
	//get vals for 2nd array
	for(int j=0; j< arr2Size; j++ ){
		//store input number
		newNum[0] = readInt();
		resultArr = (int*)malloc((arr2Size) * sizeof(int));
		//sort newNum into list appropriately, store in result
		merge(arr2, j, newNum, 1, resultArr);
		
		//copy contents from result array into arr2
		for(int i=0; i<arr2Size; i++){
			arr2[i] = resultArr[i];
		}		
		free(resultArr);
	}


	//------prints------//
	printf("Sorted List 1: ");
	for(int j=0; j< arr1Size; j++ ){
		printf("%d ", arr1[j]);

	}
	printf("\n");


	printf("Sorted List 2: ");
	for	(int j=0; j< arr2Size; j++ ){
		printf("%d ", arr2[j]);

	}
	printf("\n");



	resultArr = (int*)malloc((arr1Size + arr2Size) * sizeof(int));

	printf("Merged lists of 1 and 2: ");
	merge(arr1, arr1Size, arr2, arr2Size, resultArr);
	
	for	(int j=0; j< (arr2Size+arr1Size); j++ ){
		printf("%d ", resultArr[j]);

	}
	printf("\n");



	free(arr1);
	free(arr2);
	free(resultArr);
}//endMain





void merge(int array1[], int length1, int array2[], int length2, int result[]){

	
	int arr1Index = 0;
	int arr2Index = 0;	
	int resultArrIndex = 0;

	while(resultArrIndex < length1 + length2){
		//printf("%d ", array2[1]);
		
		//compare each index in array
		if(arr1Index >= length1){
			result[resultArrIndex] = array2[arr2Index];
			resultArrIndex++;
			arr2Index++;
		}else if (arr2Index >= length2){
			result[resultArrIndex] = array1[arr1Index];
			resultArrIndex++;
			arr1Index++;
		}else if(array1[arr1Index] <= array2[arr2Index]){
			result[resultArrIndex] = array1[arr1Index];
			resultArrIndex++;
			arr1Index++;
		}else{
			result[resultArrIndex] = array2[arr2Index];
			resultArrIndex++;
			arr2Index++;
		}		

	}//end while


}//endMerge




int readInt(){
	int c = 0;
	int i = 0;
  
	while( (c = getchar()) != EOF && c != '\n' )
	{
		if( c >= '0' && c <= '9')	
			i = i * 10 + (c - '0');	
	}
	
	return i;
}
