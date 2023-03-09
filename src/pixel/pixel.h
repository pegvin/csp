#ifndef __APP_PIXEL_H_INCLUDED
#define __APP_PIXEL_H_INCLUDED 1
#pragma once

#include <cstdint>

struct PixelRGBA {
	uint8_t r, g, b, a;

	bool operator == (const PixelRGBA& other);
	bool operator != (const PixelRGBA& other);
};

#endif

