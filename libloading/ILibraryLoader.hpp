#pragma once

#include <memory>

#ifdef _WIN32

#ifdef _MSC_VER
#define LIBL_STDCALL_T __stdcall
#define LIBL_CDECL_T __cdecl
#else
#define LIBL_STDCALL_T __attribute__((stdcall))
#define LIBL_CDECL_T __attribute__((cdecl))
#endif

#else
#define LIBL_STDCALL_T
#define LIBL_CDECL_T
#endif

namespace libloading
{

class ILibraryLoader
{
public:
   typedef int (LIBL_STDCALL_T *FuncSig)();
   union Alias
   {
   	 FuncSig funcSig;
   	 void* obj;
   	};

   virtual ~ILibraryLoader()
   {}

   class LibraryRef
   {
   public:
      virtual ~LibraryRef()
      {}

      virtual Alias symbol(const char* name) = 0;
   };

   virtual std::unique_ptr<ILibraryLoader::LibraryRef> library(std::initializer_list<const char*> names) = 0;
};

}
