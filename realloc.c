#include "shell.c"

/**
 * _realloc - resize the memory
 * @ptr: pointer
 * @old_size: original size
 * @new_size: new size
 *
 * Return: NULL
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *mem;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(new_size);
		return (mem);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	mem = malloc(new_size);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size < old_size)
		old_size = new_size;

	memcpy(mem, ptr, old_size);
	free(ptr);

	return (mem);
}
