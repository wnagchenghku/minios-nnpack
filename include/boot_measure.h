#ifndef _BOOT_MEASURE_
#define _BOOT_MEASURE_

#define UINT32_T uint32_t
#define UINT64_T uint64_t

typedef struct {
    UINT32_T l;
    UINT32_T h;
} x86_64_timeval_t;

#define HRT_TIMESTAMP_T x86_64_timeval_t

#define HRT_GET_TIMESTAMP(t1)  __asm__ __volatile__ ("rdtsc" : "=a" (t1.l), "=d" (t1.h));

#define HRT_GET_ELAPSED_TICKS(t1, t2, numptr)   *numptr = (((( UINT64_T ) t2.h) << 32) | t2.l) - \
                                                          (((( UINT64_T ) t1.h) << 32) | t1.l);

HRT_TIMESTAMP_T t1, t2;

#endif