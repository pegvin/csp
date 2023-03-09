#include "pixel.h"

bool PixelRGBA::operator == (const PixelRGBA& other) {
	return (
		this->r == other.r &&
		this->g == other.g &&
		this->b == other.b &&
		this->a == other.a
	);
}

bool PixelRGBA::operator != (const PixelRGBA& other) {
	return !(*this == other);
}

