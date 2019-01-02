
// as seen on:
//    https://gcc.gnu.org/wiki/Visibility

// Generic helper definitions for shared library support
//
# if defined _WIN32 || defined __CYGWIN__
#   define FMI2ALLOCGUARD_HELPER_DLL_IMPORT __declspec(dllimport)
#   define FMI2ALLOCGUARD_HELPER_DLL_EXPORT __declspec(dllexport)
#   define FMI2ALLOCGUARD_HELPER_DLL_LOCAL
# else
#   if __GNUC__ >= 4
#     define FMI2ALLOCGUARD_HELPER_DLL_IMPORT __attribute__ ((visibility ("default")))
#     define FMI2ALLOCGUARD_HELPER_DLL_EXPORT __attribute__ ((visibility ("default")))
#     define FMI2ALLOCGUARD_HELPER_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
#   else
#     define FMI2ALLOCGUARD_HELPER_DLL_IMPORT
#     define FMI2ALLOCGUARD_HELPER_DLL_EXPORT
#     define FMI2ALLOCGUARD_HELPER_DLL_LOCAL
#   endif
# endif

// Now we use the generic helper definitions above to define FMI2ALLOCGUARD_API and FMI2ALLOCGUARD_LOCAL.
// FMI2ALLOCGUARD_API is used for the public API symbols. It either DLL imports or DLL exports (or does nothing for static build)
// FMI2ALLOCGUARD_LOCAL is used for non-api symbols.

# ifdef FMI2ALLOCGUARD_DLL // defined if FMI2ALLOCGUARD is compiled as a DLL
#   ifdef FMI2ALLOCGUARD_DLL_EXPORTS // defined if we are building the shared library (instead of using it)
#     define FMI2ALLOCGUARD_API FMI2ALLOCGUARD_HELPER_DLL_EXPORT
#   else
#     define FMI2ALLOCGUARD_API FMI2ALLOCGUARD_HELPER_DLL_IMPORT
#   endif // FMI2ALLOCGUARD_DLL_EXPORTS
#   define FMI2ALLOCGUARD_LOCAL FMI2ALLOCGUARD_HELPER_DLL_LOCAL
# else // FMI2ALLOCGUARD_DLL is not defined: this means compilation as a static lib.
#   define FMI2ALLOCGUARD_API
#   define FMI2ALLOCGUARD_LOCAL
# endif // FMI2ALLOCGUARD_DLL
