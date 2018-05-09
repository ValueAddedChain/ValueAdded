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

#ifndef VAC_PEERFINDER_SOURCESTRINGS_H_INCLUDED
#define VAC_PEERFINDER_SOURCESTRINGS_H_INCLUDED

#include <valueAdd/peerfinder/impl/Source.h>
#include <valueAdd/beast/core/SharedPtr.h>

namespace valueAdd {
namespace PeerFinder {

/** Provides addresses from a static set of strings. */
class SourceStrings : public Source
{
public:
    using Strings = std::vector <std::string>;

    static beast::SharedPtr <Source> New (std::string const& name, Strings const& strings);
};

}
}

#endif
