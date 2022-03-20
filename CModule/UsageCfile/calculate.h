#ifndef _CALCULATE_H_
#define _CALCULATE_H_
#include <stdio.h>


//int add( int a, int b );
//void display();



#ifdef __cplusplus
//加入extern "C" 是因为C编译器在编译代码的时候不会对函数做出安全类型检查, 例如: 只会把 add这个函数编译成 _add 这个符号就可以成功链接
//               而如果使用C++编译器的话, 会将add这个函数编译成类似于 _Z_add_int_int 这种符号(结果就是找不到,所以会报错)
//  external "C" 的作用就是告诉C++编译器, 按照C语言编译器的方式去寻找 add 函数的符号 "_add"
extern "C"{
    int add( int a, int b );

    void display();
}
#endif

#endif
