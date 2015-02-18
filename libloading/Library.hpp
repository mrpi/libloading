#pragma once

#include "ILibraryLoader.hpp"

namespace libloading
{

class Library
{
private:
   std::unique_ptr<ILibraryLoader::LibraryRef> mLibraryRef;

protected:
   template <typename T>
   struct StdCall;

   template <typename RET_T, typename... ARGS>
   struct StdCall<RET_T(ARGS...)>
   {
      typedef RET_T(LIBL_STDCALL_T* FuncSig)(ARGS...);

      static FuncSig init(Library* lib, const char* funcName)
      {
         return reinterpret_cast<FuncSig>(lib->mLibraryRef->symbol(funcName).funcSig);
      }
   };

   template <typename T>
   struct CDecl;

   template <typename RET_T, typename... ARGS>
   struct CDecl<RET_T(ARGS...)>
   {
      typedef RET_T(LIBL_CDECL_T* FuncSig)(ARGS...);

      static FuncSig init(Library* lib, const char* funcName)
      {
         return reinterpret_cast<FuncSig>(lib->mLibraryRef->symbol(funcName).funcSig);
      }
   };

   Library(ILibraryLoader& libLoader, const char* libNames) : mLibraryRef(libLoader.library({libNames}))
   {
   }

   Library(ILibraryLoader& libLoader, std::initializer_list<const char*> libNames) : mLibraryRef(libLoader.library(libNames))
   {
   }

#define LIBL_STDCALL(FUNC_NAME_, FUNC_SIG_) StdCall<FUNC_SIG_>::FuncSig FUNC_NAME_ = StdCall<FUNC_SIG_>::init(this, #FUNC_NAME_);
#define LIBL_CDECL(FUNC_NAME_, FUNC_SIG_) CDecl<FUNC_SIG_>::FuncSig FUNC_NAME_ = CDecl<FUNC_SIG_>::init(this, #FUNC_NAME_);
};
}
