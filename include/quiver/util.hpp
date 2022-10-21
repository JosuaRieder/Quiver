/*
 *	Quiver - A graph theory library
 *	Copyright (C) 2018 Josua Rieder (josua.rieder@protonmail.com)
 *	Distributed under the MIT License.
 *	See the enclosed file LICENSE.txt for further information.
 */

#ifndef QUIVER_UTIL_HPP_INCLUDED
#define QUIVER_UTIL_HPP_INCLUDED

#include <type_traits>
#include <utility>
#include <limits>

namespace quiver
{
	struct empty_class
	{
	};

	template<typename T>
	using void2empty = std::conditional_t<std::is_same_v<T, void>, empty_class, T>;

	template<typename from, typename to>
	using copy_const =
		std::conditional_t<
			std::is_const_v<from>,
			std::add_const_t<std::remove_cv_t<to>>,
			std::remove_cv_t<to>
		>;

	template<typename T>
	constexpr T sq(T const& x)
	{
		return x * x;
	}

	template<typename... T>
	constexpr bool get_false() noexcept
	{
		return false;
	}

	template<typename T>
	inline constexpr T inf = std::numeric_limits<T>::has_infinity ? std::numeric_limits<T>::infinity() : std::numeric_limits<T>::max();
}

#endif // !QUIVER_UTIL_HPP_INCLUDED
