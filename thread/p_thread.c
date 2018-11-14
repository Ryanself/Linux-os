//pthread_create - create a new thread
#include <pthread.h>

int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
			                          void *(*start_routine) (void *), void *arg);

/* Compile and link with -pthread.
*start_routine：线程的执行函数；入参是 void*，返回值是 void*，
*恭喜你，这两个值的类型都是百搭的，任何类型你都可以在这使用了。
*arg：传递给 start_routine 的 void* 参数。
*/
