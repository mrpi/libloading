# libloading
Simple and portable dynamic library loading in C++

This header-only library eases the loading of DLLs/Shared-Object-Files.
So that you don't have to deal with dlopen/dlsym/dlclose on Posix or LoadLibrary/GetProcAddres/FreeLibrary on Win32.

## Examples

Create a thin wrapper for the functions from odbc32.dll/libodbc.so:
```c++
#pragma once
#include <libloading/Library.hpp>
#include <sql.h>

class Odbc : libloading::Library
{
public:
   Odbc(libloading::ILibraryLoader& loader)
    : libloading::Library(loader, {/*on WIN32*/"odbc32", /*for unix odbc*/"odbc"})
   {}

   LIBL_STDCALL(SQLAllocConnect, SQLRETURN(SQLHENV EnvironmentHandle, SQLHDBC *ConnectionHandle));
   LIBL_STDCALL(SQLAllocEnv, SQLRETURN(SQLHENV *EnvironmentHandle));
   // ...
};
```

Initialization and use of wrapper class:
```c++
#include "Odbc.hpp" // own wrapper class

#include <libloading/DynamicLibraryLoader.hpp>

int main()
{
   Odbc odbc(*libloading::dynamicLibraryLoader());
   SQLHENV henv;
   odbc.SQLAllocEnv(&henv);
};
```
## License

Boost Software License - Version 1.0
