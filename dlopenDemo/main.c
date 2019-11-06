#include <stdio.h>
#include <dlfcn.h>

typedef int(*pfoo)();

int main(){
  void *handler = dlopen("./libtest.so",RTLD_NOW);
  if(handler == NULL){
    printf("dlopen() failed\n");
    return -1;
  }

  pfoo foo = (pfoo)dlsym(handler, "foo");
  int sum = foo(12, 24);

  printf("%s(), line = %d, sum = %d\n",__FUNCTION__,__LINE__,sum);
  return 0;
}
