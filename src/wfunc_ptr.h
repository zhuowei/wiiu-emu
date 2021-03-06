#pragma once
#include <cstdint>
#include <ostream>
#include "p32.h"
#include "ppc.h"
#include "ppctypes.h"

ThreadState *GetCurrentFiberState();

#pragma pack(push, 1)

template<typename ReturnType, typename... Args>
struct wfunc_ptr
{
   wfunc_ptr() :
      address(0)
   {
   }

   wfunc_ptr(std::nullptr_t) :
      address(0)
   {
   }

   wfunc_ptr(int addr) :
      address(addr)
   {
   }

   wfunc_ptr(uint32_t addr) :
      address(addr)
   {
   }

   wfunc_ptr(p32<void> addr) :
      address(addr)
   {
   }

   operator uint32_t() const
   {
      return address;
   }

   ReturnType operator()(Args... args);

   uint32_t address;

};

#pragma pack(pop)


template<typename ReturnType, typename... Args>
static inline std::ostream&
operator<<(std::ostream& os, const wfunc_ptr<ReturnType, Args...>& val)
{
   return os << static_cast<uint32_t>(val);
}

namespace ppctypes {

template<typename ReturnType, typename... Args>
struct ppctype_converter_t<wfunc_ptr<ReturnType, Args...>>
{
   typedef wfunc_ptr<ReturnType, Args...> Type;
   static const PpcType ppc_type = PpcType::WORD;
   
   static inline void to_ppc(const Type& v, uint32_t& out) {
      out = v.address;
   }

   static inline Type from_ppc(uint32_t in) {
      return Type(in);
   }
};
}
