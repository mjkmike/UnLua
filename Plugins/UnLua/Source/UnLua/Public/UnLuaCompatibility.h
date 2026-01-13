// UnLua UE 5.7 Compatibility Header
// Provides compatibility definitions for removed/deprecated UE type traits

#pragma once

#include "CoreMinimal.h"
#include <type_traits>

// UE 5.7+ removed these type traits, so we always define our own versions
// that delegate to the standard library equivalents

// TChooseClass was deprecated in UE 5.0 and removed in UE 5.7
// Replace with std::conditional
template <bool Predicate, typename TrueClass, typename FalseClass>
struct TChooseClass
{
	typedef typename std::conditional<Predicate, TrueClass, FalseClass>::type Result;
};

// TIsTriviallyDestructible was deprecated in UE 5.5 and removed in UE 5.7
// Replace with std::is_trivially_destructible_v
template <typename T>
struct TIsTriviallyDestructible
{
	enum
	{
		Value = std::is_trivially_destructible_v<T>
	};
};
