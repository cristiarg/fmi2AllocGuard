### What is? ###
Rather than trying to describe what it is, I'll describe what it can be used for:
* there exists a process that loads/unloads a number of - same or different - shared libraries that conform to the [FMI / Functional Mockup Interface](https://fmi-standard.org) standard.
* it does so repeatedly - being a long running process, akin to a service
* once loaded, one such FMU library is executed ("co-simulation" in FMI-speak)
* depending on a configuration flag, upon initialization, a library might need be supplied with pointers to two memory management functions:
  * `void\* (\*allocateMemory)(size_t nobj, size_t size)` - calloc like
  * `void (\*freeMemory)(void\* obj)` - free like
* for various reasons, during execution of said libraries things might not work as expected:
  * abnormal execution termination
  * hang
  * implementation itself might be leaking memory
* it is where this library comes into place:
  * it keeps a bookkeeping of all allocations and it will free unfreed memory once not needed anymore

### What is not? ###
It is not a calloc/free implementation. So it will use whatever memory allocator happens to be present.

### Details ###
Due to the nature of FMI-standard and various environments where it is used, the author is aware that advanced features of the c/c++ language would not always be readily available.
Therefore, the implementation is C99 compliant.

For convenient [modern] C++ usage, wrapping in a [RAII-style] class should do.

### Thread safety ###
There is no thread safety built in.

### Platform ###
Only Linux/GCC at the moment.

TODO:
* Linux/Clang
* Win32/Visual C++

### Example ###
TODO

### License
TODO
