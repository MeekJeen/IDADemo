#include <stdio.h>
#include <dlfcn.h>
#include <errno.h>
#include <string.h>
typedef int(*pfoo)();

int main(){
  void *handler = dlopen("./libtest.so",RTLD_NOW);
  if(handler == NULL){
    printf("dlopen libtest.so failed. errno(-%d): %s\n",errno, strerror(errno));
    return -1;
  }

  pfoo foo = (pfoo)dlsym(handler, "foo");
  int sum = foo(12, 24);

  printf("%s(), line = %d, sum = %d\n",__FUNCTION__,__LINE__,sum);
  return 0;
}
