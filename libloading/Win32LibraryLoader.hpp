#pragma once

#include "ILibraryLoader.hpp"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace libloading
{

class Win32LibraryLoader : public ILibraryLoader
{
private:
   HMODULE moduleByName(const char* name)
   {
      std::string libName = std::string(name) + ".dll";

      return ::LoadLibrary(libName.c_str());
   }

public:
   class LibraryRef : public ILibraryLoader::LibraryRef
   {
   private:
      HMODULE mHandle;

   public:
      explicit LibraryRef(HMODULE handle)
       : mHandle(handle)
      {}

      ~LibraryRef()
      {
         ::FreeLibrary(mHandle);
      }

      Alias symbol(const char* name) override
      {
      	 Alias res;
      	 res.funcSig = ::GetProcAddress(mHandle, name);
         if(res.obj == nullptr)
            throw std::runtime_error("Failed to load symbol");
         return res;
      }
   };

   std::unique_ptr<ILibraryLoader::LibraryRef> library(std::initializer_list<const char*> names) override
   {
      HMODULE handle = nullptr;

      for(auto name : names)
      {
      	handle = moduleByName(name);
        if(handle)
        	break;
      }

      if(handle == nullptr)
         throw std::runtime_error("Failed to load library");

      return std::make_unique<LibraryRef>(handle);
   }

};

}
