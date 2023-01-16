#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE4(kernel_2d_memory,float *,inputmat,float *,outputmat,int,r_count,int, c_count ){
	float temporary[4][4];
	int function1=__copy_from_user(temporary,inputmat,sizeof(temporary));
	if (function1 == 0){
		return 99;
	}	
	int function2=__copy_to_user(outputmat, temporary,sizeof(temporary));
	if (function2 == 0) {
		return 101;
	}
	return 0;
	
	}
