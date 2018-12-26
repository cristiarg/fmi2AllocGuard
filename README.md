### Warning ###
Work in incipient state. Nothing functional yet.

### What is? ###
Rather that trying to describe what it is, I'll describe what it can be used for:
* there exists a process that loads/unloads a number of - same or different - shared libraries that conform to the [FMI / Functional Mockup Interface](https://fmi-standard.org) standard.
* it does so repeatedly - being a long running process, akin to service
* once loaded, one such FMU library is executed ("co-simulation" in FMI-speak)
* depending on a configuration flag, upon initialization, a library might need be supplied with pointers to two memory management functions:
  * `void\* (\*allocateMemory)(size_t nobj, size_t size)`
  * `void (\*freeMemory)(void\* obj)`
* for various reasons, during execution of said libraries things might not work as expected:
  * abnormal execution termination
  * hang
  * implementation itself might be leaking memory
* this is where this library comes into place; it keeps a bookkeeping of all allocations and it will free unfreed memory once not needed anymore

### What is not? ###
It is not a calloc/free implementation. So it will use whatever memory allocator happens to be present.

### Details ###
Due to the nature of FMI-standard, the author is aware that advanced features of the c++ language would not always be readily available at the usage location.
Therefore, the default implementation, albeit C++ in nature, does not use any of the modern

### TODOs ###
* implement specific distinct versions:
  * C++03 (the default)
  * C-only
  * C++latest 

### License
Whatever you want it to be.
