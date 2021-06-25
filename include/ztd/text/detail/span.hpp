// =============================================================================
//
// ztd.text
// Copyright © 2021 JeanHeyd "ThePhD" Meneide and Shepherd's Oasis, LLC
// Contact: opensource@soasis.org
//
// Commercial License Usage
// Licensees holding valid commercial ztd.text licenses may use this file in
// accordance with the commercial license agreement provided with the
// Software or, alternatively, in accordance with the terms contained in
// a written agreement between you and Shepherd's Oasis, LLC.
// For licensing terms and conditions see your agreement. For
// further information contact opensource@soasis.org.
//
// Apache License Version 2 Usage
// Alternatively, this file may be used under the terms of Apache License
// Version 2.0 (the "License") for non-commercial use; you may not use this
// file except in compliance with the License. You may obtain a copy of the
// License at
//
//		http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// ============================================================================>

#pragma once

#ifndef ZTD_TEXT_DETAIL_SPAN_HPP
#define ZTD_TEXT_DETAIL_SPAN_HPP

#include <ztd/text/version.hpp>

#include <type_traits>

#if ZTD_TEXT_IS_ON(ZTD_TEXT_STD_LIBRARY_SPAN_I_)

#include <span>

#include <ztd/text/detail/prologue.hpp>

namespace ztd { namespace text {
	ZTD_TEXT_INLINE_ABI_NAMESPACE_OPEN_I_

	//////
	/// @brief dynamic extent copycat
	///
	//////
	inline constexpr decltype(::std::dynamic_extent) dynamic_extent = ::std::dynamic_extent;

	using ::std::as_bytes;
	using ::std::as_writable_bytes;
	using ::std::span;

	ZTD_TEXT_INLINE_ABI_NAMESPACE_CLOSE_I_
}} // namespace ztd::text

#else

// Use home-grown span from Martin Moene
#include <ztd/text/detail/span.implementation.hpp>

#include <ztd/text/detail/prologue.hpp>

namespace ztd { namespace text {
	ZTD_TEXT_INLINE_ABI_NAMESPACE_OPEN_I_

	//////
	/// @brief dynamic extent copycat
	///
	//////
	inline constexpr decltype(::nonstd::dynamic_extent) dynamic_extent = ::nonstd::dynamic_extent;

	using ::nonstd::as_bytes;
	using ::nonstd::as_writable_bytes;
	using ::nonstd::span;

	ZTD_TEXT_INLINE_ABI_NAMESPACE_CLOSE_I_
}} // namespace ztd::text

#endif

namespace ztd { namespace text {
	ZTD_TEXT_INLINE_ABI_NAMESPACE_OPEN_I_

	namespace __txt_detail {
		template <typename _Ty>
		class __is_std_span : public ::std::false_type { };

		template <typename _Ty, decltype(::ztd::text::dynamic_extent) _N>
		class __is_std_span<::ztd::text::span<_Ty, _N>> : public ::std::true_type { };

		template <typename _Ty>
		inline constexpr bool __is_std_span_v = __is_std_span<_Ty>::value;
	} // namespace __txt_detail

	ZTD_TEXT_INLINE_ABI_NAMESPACE_CLOSE_I_
}} // namespace ztd::text

#include <ztd/text/detail/epilogue.hpp>

#endif // ZTD_TEXT_DETAIL_SPAN_HPP
