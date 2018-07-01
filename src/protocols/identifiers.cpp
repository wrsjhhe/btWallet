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
#include <bitcoin/protocol/zmq/socket.hpp>

#include <algorithm>
#include <bitcoin/protocol/zmq/identifiers.hpp>

namespace libbitcoin {
namespace protocol {
namespace zmq {

bool identifiers::empty() const
{
    return ids_.empty();
}

bool identifiers::contains(identifier value) const
{
    return std::find(ids_.begin(), ids_.end(), value) != ids_.end();
}

void identifiers::push(const void* socket)
{
    const auto value = reinterpret_cast<identifier>(socket);
    ids_.push_back(value);
}

} // namespace zmq
} // namespace protocol
} // namespace libbitcoin
