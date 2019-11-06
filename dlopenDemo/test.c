#include "test.h"
int foo(int x, int y){
  printf("%s(), line = %d, x = %d, y = %d\n",__FUNCTION__,__LINE__,x,y);
  return x+y;
}
