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
#ifndef LIBBITCOIN_NETWORK_PROTOCOL_EVENTS_HPP
#define LIBBITCOIN_NETWORK_PROTOCOL_EVENTS_HPP

#include <string>
#include <bitcoin/bitcoin.hpp>
#include <bitcoin/network/channel.hpp>
#include <bitcoin/network/define.hpp>
#include <bitcoin/network/protocols/protocol.hpp>

namespace libbitcoin {
namespace network {

class p2p;

/**
 * Base class for stateful protocol implementation, thread and lock safe.
 */
class BCT_API protocol_events
  : public protocol
{
protected:

    /**
     * Construct a protocol instance.
     * @param[in]  network   The network interface.
     * @param[in]  channel   The channel on which to start the protocol.
     * @param[in]  name      The instance name for logging purposes.
     */
    protocol_events(p2p& network, channel::ptr channel,
        const std::string& name);

    /**
     * Start the protocol with no event handler.
     */
    virtual void start();

    /**
     * Start the protocol.
     * The event handler may be invoked one or more times.
     * @param[in]  handler  The handler to call at each completion event.
     */
    virtual void start(event_handler handler);

    /**
     * Invoke the event handler.
     * @param[in]  ec  The error code of the preceding operation.
     */
    virtual void set_event(const code& ec);

    /**
     * Determine if the event handler has been cleared.
     */
    virtual bool stopped() const;

    /**
     * Determine if the code is a stop code or the handler has been cleared.
     */
    virtual bool stopped(const code& ec) const;

private:
    void handle_started(completion_handler handler);
    void handle_stopped(const code& ec);
    void do_set_event(const code& ec);

    bc::atomic<event_handler> handler_;
};

} // namespace network
} // namespace libbitcoin

#endif
