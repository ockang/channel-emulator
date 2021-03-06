/* -*- C++ -*- */

//=============================================================================
/**
 * @file    utils.hpp
 * @author Tad Kollar  
 *
 * $Id: utils.hpp 1670 2012-08-28 13:25:28Z tkollar $ 
 * Copyright (c) 2008.
 *      NASA Glenn Research Center.  All rights reserved.
 */
//=============================================================================

#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <string>
#include <list>
#include <stdexcept>

#include <ace/OS_main.h>
#include <ace/Basic_Types.h>

namespace nasaCE {

const std::string IPV4_QUAD_REGEX("(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})");
const std::string IPV4_FULL_REGEX("(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})");

/// @brief Read the top line of a text file.
/// @param file_name The name of the file to be read.
/// @return A copy of a std::string containing the contents of the top line.
///
/// Many of the configuration and statistics files generated by Linux
/// are a single line.
std::string read_one_liner(const std::string& file_name);

/// @brief Spawn a new process and return the output.
/// @param cmd The command line to run.
/// @return A std::list of std::strings holding the complete output of the command.
/// @throw std::runtime_error Thrown if the command cannot be started.
std::list<std::string>* popen(const std::string& cmd);

/// @brief Spawn a new process, ignore output, and return the exit code.
/// @param cmd The command line to run.
/// @return The exit code of the child process.
/// @throw std::runtime_error Thrown if the command cannot be started.
int run(const std::string& cmd);

/// Converts a dotted-quad string to a network-ordered data.
ACE_UINT32 inet_ston(const std::string& ip_str);

/// Convert network-ordered data to dotted-quad notation.
std::string inet_ntos(const int ip_int);

/// Reverse the bits within a byte.
/// 
/// Adapted from a patch to Samba suggested by Eric Crossman.
ACE_UINT8 revbits8(const ACE_UINT8 a);

/// Reverse the bits in each byte of a uint32.
/// 
/// Adapted from a patch to Samba suggested by Eric Crossman.
ACE_UINT32 revbits(const ACE_UINT32 a);

ACE_HANDLE get_ctl_fd();

template <class T>
T GetMax (T a, T b) {
  return (a>b?a:b);
}

template <class T>
T GetMin (T a, T b) {
  return (a<b?a:b);
}

} // namespace nasaCE

#endif // _UTILS_HPP_
