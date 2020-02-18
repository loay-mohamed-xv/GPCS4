#pragma once

namespace util
{;

template <typename T, typename U = T>
inline bool isAligned(T size, U align)
{
	return !(size % align);
}

template <typename T, typename U = T>
inline T alignDown(T size, U align)
{
	return ((size / align) + ((size % align) ? 1 : 0)) * align;
}

template <typename T, typename U = T>
inline T alignRound(T size, U align)
{
	return (size + align - 1) & ~(align - 1);
}

template <typename T>
inline bool isBitSet(T value, uint32_t pos)
{
	return value & (1 << pos);
}

inline uint64_t buildUint64(uint32_t high, uint32_t low)
{
	return (uint64_t)(high) << 32 | low;
}

// Garlic memory address is supposed to be within 0x000000FFFFFFFFFF
// in this case, gnmGpuAbsAddr actually does nothing
inline void* gnmGpuAbsAddr(void* refAddr, void* relaAddr)
{
	return reinterpret_cast<void*>(((uintptr_t)(refAddr)&0x0000FF0000000000) | (uintptr_t)(relaAddr));
}

}  // namespace util