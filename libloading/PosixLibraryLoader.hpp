#pragma once

#include "ILibraryLoader.hpp"

#include <dlfcn.h>

namespace libloading
{

class PosixLibraryLoader : public ILibraryLoader
{
private:
   void* moduleByName(const char* name)
   {
      std::string libName = "lib" + std::string(name);
#if __APPLE__
      // Untested!
      libName += ".dylib";
#else
      libName += ".so";
#endif

      return ::dlopen(libName.c_str(), RTLD_LAZY);
   }

public:
   class LibraryRef : public ILibraryLoader::LibraryRef
   {
   private:
      void* mHandle;

   public:
      explicit LibraryRef(void* handle)
       : mHandle(handle)
      {}

      ~LibraryRef()
      {
         ::dlclose(mHandle);
      }

      Alias symbol(const char* name) override
      {
         Alias res;
         res.obj = ::dlsym(mHandle, name);
         if(res.obj == nullptr)
            throw std::runtime_error(::dlerror());
         return res;
      }
   };

   std::unique_ptr<ILibraryLoader::LibraryRef> library(std::initializer_list<const char*> names) override
   {
      void* handle = nullptr;

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
