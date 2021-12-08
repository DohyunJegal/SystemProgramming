#include <stdio.h>
#include <stdlib.h>

int func2(int a, int b)
{
	__asm__ __volatile__
  	(
		"movl 16(%ebp),%edx \n\t"
		"movl 24(%ebp),%eax \n\t"
		"cmpl %eax,%edx \n\t"
		"jle L0 \n\t"
		"movl $1,%eax \n\t"
		"jmp L1 \n\t"
	"L0: \n\t"
		"movl $0,%eax \n\t"
	"L1: \n\t"
	);
}

void func1(int *a, int *b)
{
	__asm__ __volatile__
  	(
		"movl 24(%ebp),%ecx \n\t"
		"movl 16(%ebp),%edx \n\t"
		"movl (%ecx),%eax \n\t"
		"movl (%edx),%ebx \n\t"
		"movl %eax,(%edx) \n\t"
		"movl %ebx,(%ecx) \n\t"
	);
}

int main(int argc, char *argv[]) {
	 
	int arr[] = { 1, 9, 5, 6, 3, 2, 9, 4, 1, 3 };

	// Sort arr using bubble sort algorithm
	// YOU MUST USE func1, func2 

	// Output MUST be
	// 1 1 2 3 3 4 5 6 9 9
	
	// fill your own codes from here
	
	int i, j, res;
	for(i=9; i>0; i--){
		for(j=0; j<i; j++){
			res = func2(arr[j],arr[j+1]);
			if(res == 1)
				func1(&arr[j],&arr[j+1]);
		}	
	}
	for(i=0; i<10; i++){
		printf("%d", arr[i]);	
	}
	return 0;
}
