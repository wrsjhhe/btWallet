/**
 * Copyright (c) 2011-2017 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef LIBBITCOIN_CLIENT_DEFINE_HPP
#define LIBBITCOIN_CLIENT_DEFINE_HPP

#include <bitcoin/bitcoin.hpp>

// We use the generic helper definitions in libbitcoin to define BCX_API
// and BCX_INTERNAL. BCX_API is used for the public API symbols. It either DLL
// imports or DLL exports (or does nothing for static build) BCX_INTERNAL is
// used for non-api symbols.

#if defined BCC_STATIC
#define BCC_API
#define BCC_INTERNAL
#elif defined BCC_DLL
#define BCC_API      BC_HELPER_DLL_EXPORT
#define BCC_INTERNAL BC_HELPER_DLL_LOCAL
#else
#define BCC_API      BC_HELPER_DLL_IMPORT
#define BCC_INTERNAL BC_HELPER_DLL_LOCAL
#endif

#endif
