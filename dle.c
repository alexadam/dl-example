#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <dlfcn.h>

int main(int argc, char **argv) {
	void *lib_handle;
	float (*fn)(char *, int);
	int x;
	char *error;

	lib_handle = dlopen("liblib.so", RTLD_LAZY);
	if (!lib_handle)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	fn = dlsym(lib_handle, "getLibVal");
	if ((error = dlerror()) != NULL)
	{
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	char * a;
	int i=0;

	float res = (*fn)(&a, &i);

	printf("REZ = %f\n", res);
}
