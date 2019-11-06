#include <stdio.h>
#include <stdlib.h>

int binary_search(int * array, int l, int r, int d){
	int c = (l + r) / 2;
	if(array[c] > d){
		r = c - 1;
	} else if(array[c] < d){
		l = c + 1;
	}
	if((array[c] == d)){
		return c;
	} else if(l > r){
		return -1;
	} else{	
		binary_search(array, l , r, d);
	}
}


int main(){
	int n = 0;
	int d = 0;
	printf("Please input a range : ");
	scanf("%d", &n);
	int * array = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++){
		array[i] = i * i;
	}

	for(int i = 0; i < n; i++){
		printf("Array[%d] : %d\n", i, array[i]);
	}

	printf("Please enter a number to search : ");	
	scanf("%d", &d);
	int result = binary_search(array, 0, n - 1, d);
	if(result > -1){
		printf("Number found in %d index", result);
	} else{
		printf("Number not found");
	}
}
