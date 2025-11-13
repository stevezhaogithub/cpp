#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

// 为类型 struct thrdpool_s, 定义了一个别名 thrdpool_t
typedef struct thrdpool_s thrdpool_t;

// 为函数指针 xxx 起了个别名 handler_pt
typedef void (*handler_pt)(void *);

#ifdef __cplusplus // 如果是C++编译器
extern "C"         // 使用C语言的链接规范
{
#endif

    // 对称处理
    thrdpool_t *thrdpool_create(int thrd_count);

    void thrdpool_terminate(thrdpool_t *pool);

    int thrdpool_post(thrdpool_t *pool, handler_pt func, void *arg);

    void thrdpool_waitdone(thrdpool_t *pool);
#ifdef __cplusplus // 如果是C++编译器
} // 结束extern "C"块
#endif
#endif

/**
 *
 * 一、__cplusplus
 *      1. __cplusplus 是C++编译器的预定义宏
 *      2. 当代码被C++编译器编译时，这个宏会自动定义
 *      3. 当代码被C编译器编译时，这个宏不会被定义
 *
 *
 */