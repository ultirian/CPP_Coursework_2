//
// Created by x4 on 12/05/2021.
// https://www.boost.org/doc/libs/1_67_0/libs/uuid/doc/uuid.html
// https://www.boost.org/doc/libs/1_54_0/doc/html/hash.html
// (James, n.d.)

#ifndef CW2_MD5HASH_H
#define CW2_MD5HASH_H

#include <iostream>
#include <algorithm>
#include <iterator>
#include <boost/uuid/detail/md5.hpp>
#include <boost/algorithm/hex.hpp>

// Using boost library md5 (James, n.d.).

using boost::uuids::detail::md5;

std::string generate_hash(const md5::digest_type &digest)
{
    const auto charDigest = reinterpret_cast<const char *>(&digest);
    std::string result;
    boost::algorithm::hex(charDigest, charDigest + sizeof(md5::digest_type), std::back_inserter(result));

    return result;
}

// Takes in string and returns hash
std::string generate_hash_output(const std::string &in)
{
    // Hashing Object
    md5 hash;
    // Get Hash
    md5::digest_type digest;

    // Takes getPassword var to generate hash.
    hash.process_bytes(in.data(), in.size());
    hash.get_digest(digest);

    // Outputs hash to console (debugging)
#ifdef DEBUG
    std::cout << "md5(" << in << ") = " << generate_hash(digest) << '\n';
#endif
    std::string hash_out = generate_hash(digest);

    // returns hash
    return hash_out;
}

#endif //CW2_MD5HASH_H
