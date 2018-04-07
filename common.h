#ifdef MY_EXPORTS
#define MY_API __declspec(dllexport)
#else
#define MY_API __declspec(dllimport)
#endif

int MY_API foo();