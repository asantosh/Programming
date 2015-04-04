#ifndef __MALLOC_H__
#define __MALLOC_H__

void *m_malloc(size_t size);
void *m_calloc(size_t mem, size_t size);
void m_free(void *ptr);

#endif /*__MALLOC_H__*/
