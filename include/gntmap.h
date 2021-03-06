#ifndef __GNTMAP_H__
#define __GNTMAP_H__

#include <os.h>

// #define FAST_MODE
#define PUBLIC_GRANT
enum ml_models {none, squeezenet1_0, resnet18, alexnet, densenet121, vgg11};

/*
 * Please consider struct gntmap opaque. If instead you choose to disregard
 * this message, I insist that you keep an eye out for raptors.
 */
struct gntmap {
    int nentries;
    struct gntmap_entry *entries;
};

int
gntmap_set_max_grants(struct gntmap *map, int count);

int
gntmap_munmap(struct gntmap *map, unsigned long start_address, int count);

int
gntmap_munmap_batch(struct gntmap *map, unsigned long start_address, int count, int model);

void*
gntmap_map_grant_refs(struct gntmap *map, 
                      uint32_t count,
                      uint32_t *domids,
                      int domids_stride,
                      uint32_t *refs,
                      int writable);

void*
gntmap_map_grant_refs_batch(struct gntmap *map, 
                            uint32_t count,
                            uint32_t *domids,
                            int domids_stride,
                            uint32_t *refs,
                            int writable,
                            int model);

void
gntmap_init(struct gntmap *map);

void
gntmap_fini(struct gntmap *map);

#endif /* !__GNTMAP_H__ */
