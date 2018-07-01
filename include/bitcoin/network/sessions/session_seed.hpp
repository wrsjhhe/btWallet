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
#ifndef LIBBITCOIN_NETWORK_SESSION_SEED_HPP
#define LIBBITCOIN_NETWORK_SESSION_SEED_HPP

#include <cstddef>
#include <memory>
#include <vector>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/network/channel.hpp>
#include <bitcoin/network/connector.hpp>
#include <bitcoin/network/define.hpp>
#include <bitcoin/network/sessions/session.hpp>
#include <bitcoin/network/settings.hpp>

namespace libbitcoin {
namespace network {

class p2p;

/// Seed connections session, thread safe.
class BCT_API session_seed
  : public session, track<session_seed>
{
public:
    typedef std::shared_ptr<session_seed> ptr;

    /// Construct an instance.
    session_seed(p2p& network);

    /// Start the session.
    void start(result_handler handler) override;

protected:
    /// Overridden to set service and version mins upon session start.
    void attach_handshake_protocols(channel::ptr channel,
        result_handler handle_started) override;

    /// Override to attach specialized protocols upon channel start.
    virtual void attach_protocols(channel::ptr channel,
        result_handler handler);

private:
    void start_seeding(size_t start_size, result_handler handler);
    void start_seed(const config::endpoint& seed, result_handler handler);
    void handle_started(const code& ec, result_handler handler);
    void handle_connect(const code& ec, channel::ptr channel,
        const config::endpoint& seed, connector::ptr connector,
        result_handler handler);
    void handle_complete(size_t start_size, result_handler handler);

    void handle_channel_start(const code& ec, channel::ptr channel,
        result_handler handler);
    void handle_channel_stop(const code& ec);
};

} // namespace network
} // namespace libbitcoin

#endif

