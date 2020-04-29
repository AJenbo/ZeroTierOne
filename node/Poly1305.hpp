/*
 * Copyright (c)2013-2020 ZeroTier, Inc.
 *
 * Use of this software is governed by the Business Source License included
 * in the LICENSE.TXT file in the project's root directory.
 *
 * Change Date: 2024-01-01
 *
 * On the date above, in accordance with the Business Source License, use
 * of this software will be governed by version 2.0 of the Apache License.
 */
/****/

#ifndef ZT_POLY1305_HPP
#define ZT_POLY1305_HPP

namespace ZeroTier {

#define ZT_POLY1305_KEY_SIZE 32
#define ZT_POLY1305_MAC_SIZE 16

/**
 * Poly1305 one-time MAC calculator
 */
class Poly1305
{
public:
	ZT_INLINE Poly1305() {}
	ZT_INLINE Poly1305(const void *key) { this->init(key); }

	void init(const void *key) noexcept;
	void update(const void *data,unsigned int len) noexcept;
	void finish(void *auth) noexcept;

private:
	struct {
	  size_t aligner;
  	unsigned char opaque[136];
	} ctx;
};

} // namespace ZeroTier

#endif
