//------------------------------------------------------------------------------
/*
    This file is part of valueAdded: https://github.com/valueAdd/valueAdded
    Copyright (c) 2012, 2013 valueAdd Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#ifndef VAC_CORE_LOADMONITOR_H_INCLUDED
#define VAC_CORE_LOADMONITOR_H_INCLUDED

#include <valueAdd/core/LoadEvent.h>
#include <valueAdd/beast/utility/Journal.h>
#include <chrono>
#include <mutex>

namespace valueAdd {

// Monitors load levels and response times

// VFALCO TODO Rename this. Having both LoadManager and LoadMonitor is confusing.
//
class LoadMonitor
{
public:
    explicit
    LoadMonitor (beast::Journal j);

    void addLoadSample (LoadEvent const& sample);

    void addSamples (int count, std::chrono::milliseconds latency);

    void setTargetLatency (std::uint64_t avg, std::uint64_t pk);

    bool isOverTarget (std::uint64_t avg, std::uint64_t peak);

    // VFALCO TODO make this return the values in a struct.
    struct Stats
    {
        Stats();

        std::uint64_t count;
        std::uint64_t latencyAvg;
        std::uint64_t latencyPeak;
        bool isOverloaded;
    };

    Stats getStats ();

    bool isOver ();

private:
    void update ();

    std::mutex mutex_;

    std::uint64_t mCounts;
    int           mLatencyEvents;
    std::uint64_t mLatencyMSAvg;
    std::uint64_t mLatencyMSPeak;
    std::uint64_t mTargetLatencyAvg;
    std::uint64_t mTargetLatencyPk;
    int           mLastUpdate;
    beast::Journal j_;
};

} // valueAdd

#endif
