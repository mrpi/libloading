#pragma once

#ifdef _WIN32

#include "Win32LibraryLoader.hpp"

namespace libloading
{

inline std::unique_ptr<ILibraryLoader> dynamicLibraryLoader()
{
   return std::make_unique<Win32LibraryLoader>();
}

}

#else

#include "PosixLibraryLoader.hpp"

namespace libloading
{

inline std::unique_ptr<ILibraryLoader> dynamicLibraryLoader()
{
   return std::make_unique<PosixLibraryLoader>();
}

}

#endif
