#include "ntl"
#include "system"

#ifndef NTL_USER_MODE

void* __cdecl operator new(size_t count) {
    void *result = ExAllocatePoolWithTag(NonPagedPoolNx, count, NTL_TAG);
    if (!result) {
        ExRaiseStatus(STATUS_FATAL_MEMORY_EXHAUSTION);
    }
    return result;
}

void __cdecl operator delete(void *object) {
    ExFreePoolWithTag(object, NTL_TAG);
}

#else

void* __cdecl operator new(size_t count) {
    void *result = malloc(count);
    if (!result) {
        SetLastError(ERROR_OUTOFMEMORY);
    }
    return result;
}

void __cdecl operator delete(void *object) {
    free(object);
}

#endif
