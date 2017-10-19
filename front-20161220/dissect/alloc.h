#ifndef _dissect_alloc_h
#define _dissect_alloc_h

typedef struct alloc_s alloc_t;
typedef struct alloc_list_s alloc_list_t;

struct alloc_s {
  unsigned ptr, size;
  int freed;
};

alloc_t *alloc_add (unsigned ptr, unsigned size);
void alloc_rm (unsigned ptr);

alloc_t *alloc_list_last (alloc_list_t *l);
alloc_list_t *alloc_list_prepend (alloc_list_t *l, alloc_t *alloc);
unsigned alloc_list_lost_mem (alloc_list_t *l);

alloc_list_t *alloc_list_sweep (alloc_list_t *l);
void allocations_sweep (void);

int num_allocations(void);
void alloc_print_mem_used (void);

#endif /* _dissect_alloc_h */
