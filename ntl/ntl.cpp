#include <ntddk.h>

#include "ntl"

void* __cdecl operator new(size_t count) {
    return ExAllocatePoolWithTag(NonPagedPoolNx, count, NTL_TAG);
}

void __cdecl operator delete(void* object) {
    ExFreePoolWithTag(object, NTL_TAG);
}
