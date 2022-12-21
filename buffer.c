#include <stdlib.h>
#include <ctype.h>
#include "b64.h"

#ifdef b64_USE_CUSTOM_MALLOC
extern void* b64_malloc(size_t);
#endif

#ifdef b64_USE_CUSTOM_REALLOC
extern void* b64_realloc(void*, size_t);
#endif

int b64_buf_malloc(b64_buffer_t * buf)
{
	buf->ptr = b64_malloc(B64_BUFFER_SIZE);
	if(!buf->ptr) return -1;

	buf->bufc = 1;

	return 0;
}

int b64_buf_realloc(b64_buffer_t* buf, size_t size)
{
	if (size > buf->bufc * B64_BUFFER_SIZE)
	{
		while (size > buf->bufc * B64_BUFFER_SIZE) buf->bufc++;
		buf->ptr = b64_realloc(buf->ptr, B64_BUFFER_SIZE * buf->bufc);
		if (!buf->ptr) return -1;
	}

	return 0;
}
