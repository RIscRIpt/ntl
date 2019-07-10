#include "ntl"
#include "system"

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
