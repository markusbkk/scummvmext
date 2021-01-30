/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "sci/sci.h"
#include "sci/engine/state.h"
#include "sci/graphics/screen.h"
#include "sci/graphics/scifont.h"
#include <common/config-manager.h>
#include <image/png.h>

namespace Sci {

#ifdef ENABLE_SCI32
static const byte sci32SystemFont[] = {
	0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x06, 0x01,
	0x09, 0x01, 0x0c, 0x01, 0x0f, 0x01, 0x12, 0x01,
	0x15, 0x01, 0x18, 0x01, 0x1b, 0x01, 0x1e, 0x01,
	0x21, 0x01, 0x26, 0x01, 0x29, 0x01, 0x2c, 0x01,
	0x2f, 0x01, 0x32, 0x01, 0x35, 0x01, 0x38, 0x01,
	0x3b, 0x01, 0x3e, 0x01, 0x41, 0x01, 0x44, 0x01,
	0x47, 0x01, 0x4a, 0x01, 0x4d, 0x01, 0x50, 0x01,
	0x53, 0x01, 0x56, 0x01, 0x59, 0x01, 0x5c, 0x01,
	0x5f, 0x01, 0x62, 0x01, 0x65, 0x01, 0x68, 0x01,
	0x71, 0x01, 0x7a, 0x01, 0x83, 0x01, 0x8c, 0x01,
	0x95, 0x01, 0x9e, 0x01, 0xa7, 0x01, 0xb0, 0x01,
	0xb9, 0x01, 0xc2, 0x01, 0xc9, 0x01, 0xd3, 0x01,
	0xdc, 0x01, 0xe5, 0x01, 0xee, 0x01, 0xf7, 0x01,
	0x00, 0x02, 0x09, 0x02, 0x12, 0x02, 0x1b, 0x02,
	0x24, 0x02, 0x2d, 0x02, 0x36, 0x02, 0x3f, 0x02,
	0x48, 0x02, 0x51, 0x02, 0x5a, 0x02, 0x63, 0x02,
	0x6c, 0x02, 0x75, 0x02, 0x7e, 0x02, 0x87, 0x02,
	0x90, 0x02, 0x99, 0x02, 0xa2, 0x02, 0xab, 0x02,
	0xb4, 0x02, 0xbd, 0x02, 0xc6, 0x02, 0xcf, 0x02,
	0xd8, 0x02, 0xe1, 0x02, 0xea, 0x02, 0xf3, 0x02,
	0xfc, 0x02, 0x05, 0x03, 0x0e, 0x03, 0x17, 0x03,
	0x20, 0x03, 0x29, 0x03, 0x32, 0x03, 0x3b, 0x03,
	0x44, 0x03, 0x4d, 0x03, 0x56, 0x03, 0x5f, 0x03,
	0x68, 0x03, 0x71, 0x03, 0x7a, 0x03, 0x83, 0x03,
	0x8c, 0x03, 0x95, 0x03, 0x9e, 0x03, 0xa7, 0x03,
	0xb0, 0x03, 0xb9, 0x03, 0xc2, 0x03, 0xcb, 0x03,
	0xd4, 0x03, 0xdd, 0x03, 0xe6, 0x03, 0xef, 0x03,
	0xf8, 0x03, 0x01, 0x04, 0x0a, 0x04, 0x13, 0x04,
	0x1c, 0x04, 0x25, 0x04, 0x2e, 0x04, 0x37, 0x04,
	0x40, 0x04, 0x49, 0x04, 0x52, 0x04, 0x5b, 0x04,
	0x64, 0x04, 0x6d, 0x04, 0x76, 0x04, 0x7f, 0x04,
	0x88, 0x04, 0x91, 0x04, 0x9b, 0x04, 0xa4, 0x04,
	0xad, 0x04, 0xb6, 0x04, 0xbf, 0x04, 0x02, 0x01,
	0x00, 0x02, 0x01, 0x00, 0x02, 0x01, 0x40, 0x02,
	0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40,
	0x02, 0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01,
	0x40, 0x13, 0x01, 0x00, 0x00, 0x00, 0x02, 0x01,
	0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40, 0x02,
	0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40,
	0x02, 0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01,
	0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40, 0x02,
	0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40,
	0x02, 0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01,
	0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40, 0x02,
	0x01, 0x40, 0x02, 0x01, 0x40, 0x02, 0x01, 0x40,
	0x04, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x02, 0x07, 0x40, 0x40, 0x40, 0x40, 0x00,
	0x40, 0x00, 0x05, 0x07, 0x50, 0x50, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x06, 0x07, 0x28, 0x7c, 0x28,
	0x28, 0x7c, 0x28, 0x00, 0x04, 0x07, 0x20, 0x30,
	0x40, 0x20, 0x10, 0x60, 0x20, 0x06, 0x07, 0x24,
	0x58, 0x34, 0x28, 0x40, 0x00, 0x00, 0x04, 0x07,
	0x20, 0x30, 0x40, 0x20, 0x40, 0x30, 0x20, 0x03,
	0x07, 0x20, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00,
	0x04, 0x07, 0x10, 0x20, 0x40, 0x40, 0x40, 0x20,
	0x10, 0x04, 0x07, 0x40, 0x20, 0x10, 0x10, 0x10,
	0x20, 0x40, 0x06, 0x05, 0x10, 0x54, 0x38, 0x54,
	0x10, 0x04, 0x08, 0x00, 0x20, 0x20, 0x70, 0x20,
	0x20, 0x00, 0x00, 0x03, 0x07, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x20, 0x40, 0x05, 0x07, 0x00, 0x00,
	0x00, 0x70, 0x00, 0x00, 0x00, 0x04, 0x07, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x05, 0x07,
	0x08, 0x10, 0x10, 0x20, 0x20, 0x40, 0x00, 0x05,
	0x07, 0x30, 0x48, 0x58, 0x68, 0x48, 0x30, 0x00,
	0x05, 0x07, 0x20, 0x60, 0x20, 0x20, 0x20, 0x70,
	0x00, 0x05, 0x07, 0x30, 0x48, 0x08, 0x30, 0x40,
	0x78, 0x00, 0x05, 0x07, 0x70, 0x08, 0x30, 0x08,
	0x08, 0x70, 0x00, 0x05, 0x07, 0x18, 0x28, 0x48,
	0x78, 0x08, 0x08, 0x00, 0x05, 0x07, 0x78, 0x40,
	0x70, 0x08, 0x08, 0x70, 0x00, 0x05, 0x07, 0x30,
	0x40, 0x70, 0x48, 0x48, 0x30, 0x00, 0x05, 0x07,
	0x78, 0x08, 0x10, 0x20, 0x20, 0x20, 0x00, 0x05,
	0x07, 0x30, 0x48, 0x30, 0x48, 0x48, 0x30, 0x00,
	0x05, 0x07, 0x30, 0x48, 0x48, 0x38, 0x08, 0x30,
	0x00, 0x02, 0x07, 0x00, 0x40, 0x00, 0x00, 0x40,
	0x00, 0x00, 0x03, 0x07, 0x00, 0x20, 0x00, 0x00,
	0x20, 0x20, 0x40, 0x04, 0x07, 0x00, 0x10, 0x20,
	0x40, 0x20, 0x10, 0x00, 0x04, 0x07, 0x00, 0x00,
	0x70, 0x00, 0x70, 0x00, 0x00, 0x04, 0x07, 0x00,
	0x40, 0x20, 0x10, 0x20, 0x40, 0x00, 0x04, 0x07,
	0x20, 0x50, 0x10, 0x20, 0x20, 0x00, 0x20, 0x08,
	0x07, 0x1c, 0x2a, 0x55, 0x55, 0x2e, 0x18, 0x00,
	0x05, 0x07, 0x30, 0x48, 0x48, 0x78, 0x48, 0x48,
	0x00, 0x05, 0x07, 0x70, 0x48, 0x70, 0x48, 0x48,
	0x70, 0x00, 0x05, 0x07, 0x30, 0x48, 0x40, 0x40,
	0x48, 0x30, 0x00, 0x05, 0x07, 0x70, 0x48, 0x48,
	0x48, 0x48, 0x70, 0x00, 0x05, 0x07, 0x78, 0x40,
	0x70, 0x40, 0x40, 0x78, 0x00, 0x05, 0x07, 0x78,
	0x40, 0x70, 0x40, 0x40, 0x40, 0x00, 0x05, 0x07,
	0x30, 0x48, 0x40, 0x58, 0x48, 0x30, 0x00, 0x05,
	0x07, 0x48, 0x48, 0x78, 0x48, 0x48, 0x48, 0x00,
	0x04, 0x07, 0x70, 0x20, 0x20, 0x20, 0x20, 0x70,
	0x00, 0x05, 0x07, 0x08, 0x08, 0x08, 0x08, 0x48,
	0x30, 0x00, 0x05, 0x07, 0x48, 0x50, 0x60, 0x50,
	0x48, 0x48, 0x00, 0x05, 0x07, 0x40, 0x40, 0x40,
	0x40, 0x40, 0x78, 0x00, 0x06, 0x07, 0x44, 0x6c,
	0x54, 0x44, 0x44, 0x44, 0x00, 0x06, 0x07, 0x44,
	0x64, 0x54, 0x4c, 0x44, 0x44, 0x00, 0x05, 0x07,
	0x30, 0x48, 0x48, 0x48, 0x48, 0x30, 0x00, 0x05,
	0x07, 0x70, 0x48, 0x48, 0x70, 0x40, 0x40, 0x00,
	0x06, 0x07, 0x30, 0x48, 0x48, 0x48, 0x48, 0x38,
	0x04, 0x05, 0x07, 0x70, 0x48, 0x48, 0x70, 0x48,
	0x48, 0x00, 0x05, 0x07, 0x30, 0x48, 0x20, 0x10,
	0x48, 0x30, 0x00, 0x06, 0x07, 0x7c, 0x10, 0x10,
	0x10, 0x10, 0x10, 0x00, 0x05, 0x07, 0x48, 0x48,
	0x48, 0x48, 0x48, 0x30, 0x00, 0x06, 0x07, 0x44,
	0x44, 0x44, 0x44, 0x28, 0x10, 0x00, 0x06, 0x07,
	0x44, 0x44, 0x44, 0x54, 0x54, 0x28, 0x00, 0x06,
	0x07, 0x44, 0x28, 0x10, 0x10, 0x28, 0x44, 0x00,
	0x06, 0x07, 0x44, 0x44, 0x28, 0x10, 0x10, 0x10,
	0x00, 0x05, 0x07, 0x78, 0x08, 0x10, 0x20, 0x40,
	0x78, 0x00, 0x03, 0x07, 0x60, 0x40, 0x40, 0x40,
	0x40, 0x40, 0x60, 0x05, 0x07, 0x40, 0x20, 0x20,
	0x10, 0x10, 0x08, 0x00, 0x03, 0x07, 0x60, 0x20,
	0x20, 0x20, 0x20, 0x20, 0x60, 0x04, 0x07, 0x20,
	0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x03,
	0x07, 0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x05, 0x07, 0x00, 0x30, 0x08, 0x38, 0x48, 0x38,
	0x00, 0x05, 0x07, 0x40, 0x40, 0x70, 0x48, 0x48,
	0x70, 0x00, 0x05, 0x07, 0x00, 0x30, 0x48, 0x40,
	0x48, 0x30, 0x00, 0x05, 0x07, 0x08, 0x08, 0x38,
	0x48, 0x48, 0x38, 0x00, 0x05, 0x07, 0x00, 0x30,
	0x48, 0x78, 0x40, 0x38, 0x00, 0x05, 0x07, 0x18,
	0x20, 0x70, 0x20, 0x20, 0x20, 0x00, 0x05, 0x07,
	0x00, 0x30, 0x48, 0x48, 0x38, 0x48, 0x30, 0x05,
	0x07, 0x40, 0x40, 0x50, 0x68, 0x48, 0x48, 0x00,
	0x02, 0x07, 0x40, 0x00, 0x40, 0x40, 0x40, 0x40,
	0x00, 0x04, 0x07, 0x10, 0x00, 0x10, 0x10, 0x10,
	0x10, 0x60, 0x04, 0x07, 0x40, 0x50, 0x50, 0x60,
	0x50, 0x50, 0x00, 0x02, 0x07, 0x40, 0x40, 0x40,
	0x40, 0x40, 0x40, 0x00, 0x06, 0x07, 0x00, 0x68,
	0x54, 0x54, 0x54, 0x54, 0x00, 0x05, 0x07, 0x00,
	0x50, 0x68, 0x48, 0x48, 0x48, 0x00, 0x05, 0x07,
	0x00, 0x30, 0x48, 0x48, 0x48, 0x30, 0x00, 0x05,
	0x07, 0x00, 0x70, 0x48, 0x48, 0x70, 0x40, 0x40,
	0x05, 0x07, 0x00, 0x30, 0x48, 0x48, 0x38, 0x08,
	0x08, 0x05, 0x07, 0x00, 0x58, 0x60, 0x40, 0x40,
	0x40, 0x00, 0x05, 0x07, 0x00, 0x38, 0x40, 0x30,
	0x08, 0x70, 0x00, 0x04, 0x07, 0x20, 0x70, 0x20,
	0x20, 0x20, 0x20, 0x00, 0x05, 0x07, 0x00, 0x48,
	0x48, 0x48, 0x48, 0x38, 0x00, 0x06, 0x07, 0x00,
	0x44, 0x44, 0x44, 0x28, 0x10, 0x00, 0x06, 0x07,
	0x00, 0x54, 0x54, 0x54, 0x54, 0x28, 0x00, 0x05,
	0x07, 0x00, 0x48, 0x48, 0x30, 0x48, 0x48, 0x00,
	0x05, 0x07, 0x00, 0x48, 0x48, 0x48, 0x38, 0x08,
	0x70, 0x05, 0x08, 0x00, 0x78, 0x08, 0x30, 0x40,
	0x78, 0x00, 0x00, 0x04, 0x07, 0x10, 0x20, 0x20,
	0x40, 0x20, 0x20, 0x10, 0x03, 0x07, 0x40, 0x40,
	0x40, 0x00, 0x40, 0x40, 0x40, 0x04, 0x07, 0x40,
	0x20, 0x20, 0x10, 0x20, 0x20, 0x40, 0x05, 0x07,
	0x28, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
	0x01, 0x40
};
#endif

GfxFontFromResource::GfxFontFromResource(ResourceManager *resMan, GfxScreen *screen, GuiResourceId resourceId)
	: _resourceId(resourceId), _screen(screen), _resMan(resMan) {
	if (getSciVersion() < SCI_VERSION_2) {
		assert(resourceId != -1);
	}

#ifdef ENABLE_SCI32
	if (getSciVersion() >= SCI_VERSION_2 && resourceId == kSci32SystemFont) {
		_resource = nullptr;
		_resourceData = SciSpan<const byte>(sci32SystemFont, sizeof(sci32SystemFont), "system font");
	} else {
#endif
		// Workaround: lsl1sci mixes its own internal fonts with the global
		// SCI ones, so we translate them here, by removing their extra bits
		if (!resMan->testResource(ResourceId(kResourceTypeFont, resourceId)))
			resourceId = resourceId & 0x7ff;

		_resource = resMan->findResource(ResourceId(kResourceTypeFont, resourceId), true);
		if (!_resource) {
			error("font resource %d not found", resourceId);
		}
		_resourceData = *_resource;
#ifdef ENABLE_SCI32
	}
#endif

	if (_resource) {
		_numChars = _resourceData.getUint16SE32At(2);
		_fontHeight = _resourceData.getUint16SE32At(4);
	} else {
		_numChars = _resourceData.getUint16LEAt(2);
		_fontHeight = _resourceData.getUint16LEAt(4);
	}
	_chars = new Charinfo[_numChars];
	// filling info for every char
	for (int16 i = 0; i < _numChars; i++) {
		uint32 charOffsetIndex = 6 + i * 2;
		if (_resource) {
			_chars[i].offset = _resourceData.getUint16SE32At(charOffsetIndex);
		} else {
			_chars[i].offset = _resourceData.getUint16LEAt(charOffsetIndex);
		}
		_chars[i].width = _resourceData.getUint8At(_chars[i].offset);
		_chars[i].height = _resourceData.getUint8At(_chars[i].offset + 1);
	}
}

GfxFontFromResource::~GfxFontFromResource() {
	delete[] _chars;
	if (_resource) {
		_resMan->unlockResource(_resource);
	}
}

GuiResourceId GfxFontFromResource::getResourceId() {
	return _resourceId;
}

uint8 GfxFontFromResource::getHeight() {
	return _fontHeight;
}

uint8 GfxFontFromResource::getCharWidth(uint16 chr) {
	return chr < _numChars ? _chars[chr].width : 0;
}

uint8 GfxFontFromResource::getCharHeight(uint16 chr) {
	return chr < _numChars ? _chars[chr].height : 0;
}

SciSpan<const byte> GfxFontFromResource::getCharData(uint16 chr) {
	if (chr >= _numChars) {
		return SciSpan<const byte>();
	}

	const uint32 bytesPerRow = (_chars[chr].width + 7) / 8;
	const uint32 charDataSize = bytesPerRow * _chars[chr].height;
	return _resourceData.subspan(_chars[chr].offset + 2, charDataSize);
}

Graphics::Surface *loadFontPNG(Common::SeekableReadStream *s) {
	Image::PNGDecoder d;

	if (!s)
		return nullptr;
	d.loadStream(*s);
	delete s;

	Graphics::Surface *srf = d.getSurface()->convertTo(Graphics::PixelFormat(4, 8, 8, 8, 8, 0, 8, 16, 24));
	return srf;
}

void GfxFontFromResource::draw(uint16 chr, int16 top, int16 left, byte color, bool greyedOutput) {
	if (chr >= _numChars) {
		// SSCI silently ignores attempts to draw characters that do not exist
		// in the font; for now, emit warnings if this happens, to learn if
		// it leads to any bugs
		warning("%s is missing glyph %d", _resource->name().c_str(), chr);
		return;
	}

	// Make sure we're comparing against the correct dimensions
	// If the font we're drawing is already upscaled, make sure we use the full screen width/height
	uint16 screenWidth = _screen->fontIsUpscaled() ? _screen->getDisplayWidth() : _screen->getWidth() * g_sci->_enhancementMultiplier;
	uint16 screenHeight = _screen->fontIsUpscaled() ? _screen->getDisplayHeight() : _screen->getHeight() * g_sci->_enhancementMultiplier;

	int charWidth = getCharWidth(chr);
	int charHeight = getCharHeight(chr);
	
	byte b = 0, mask = 0xFF;
	int16 greyedTop = top;

	Graphics::Surface *png;
	const byte *enh;
	bool enhancedFont = false;
	int pixelsLength = 0;

	Common::FSNode folder;
	char charNoStr[5];
	sprintf(charNoStr, "%d", chr);
	if (ConfMan.hasKey("extrapath")) {
		if ((folder = Common::FSNode(ConfMan.get("extrapath"))).exists() && folder.getChild(_resource->name() + '.' + charNoStr + ".png").exists()) {
			Common::String fileName = folder.getChild(_resource->name() + '.' + charNoStr + ".png").getName();
			Common::SeekableReadStream *file = SearchMan.createReadStreamForMember(fileName);
			if (!file) {
				debug("Enhanced Bitmap %s DOES NOT EXIST, yet would have been loaded.. 2", fileName.c_str());
			} else {
				debug("Enhanced Bitmap %s EXISTS, and has been loaded..", fileName.c_str());
				png = loadFontPNG(file);
				if (png) {
					enh = (const byte *)png->getPixels();
					if (enh) {
						pixelsLength = png->w * png->h * 4;
						enhancedFont = true;
					}
				}
			}
		}
	}
	if (!enhancedFont)
	{
		SciSpan<const byte> charData = getCharData(chr);
		bool exportFontToPNG = false;
		Common::String exportFileName;

		for (int y = 0; y < charHeight; y++) {
			if (greyedOutput)
				mask = ((greyedTop++) % 2) ? 0xAA : 0x55;
			for (int x = 0; x < charWidth; x++) {
				if ((x & 7) == 0) // fetching next data byte
					b = *(charData++) & mask;
				if (b & 0x80) { // if MSB is set - paint it
					int screenX = left + x;
					int screenY = top + y;
					if (0 <= screenX && screenX < screenWidth && 0 <= screenY && screenY < screenHeight) {
						_screen->putFontPixel(top, screenX, y, color);
					} else {
						warning("%s glpyh %d drawn out of bounds: %d, %d", _resource->name().c_str(), chr, screenX, screenY);
					}
				}
				b = b << 1;
			}
		}

	}
	if (enhancedFont) {
		extern byte *_palette;
		left *= g_sci->_enhancementMultiplier;
		top *= g_sci->_enhancementMultiplier;
		for (int y = 0; y < charHeight * g_sci->_enhancementMultiplier; y++) {

			for (int x = 0; x < charWidth * g_sci->_enhancementMultiplier; x++) {
				
				int screenX = (left) + x;
				int screenY = (top) + y;
				//if (0 <= screenX && screenX < screenWidth && 0 <= screenY && screenY < screenHeight) {
				
					//_screen->putFontPixelX(top, screenX, y, color, enh[(((y * (charWidth * g_sci->_enhancementMultiplier)) + x) * 4)], enh[(((y * (charWidth * g_sci->_enhancementMultiplier)) + x) * 4) + 1], enh[(((y * (charWidth * g_sci->_enhancementMultiplier)) + x) * 4) + 2], enh[(((y * (charWidth * g_sci->_enhancementMultiplier)) + x) * 4) + 3]);
				_screen->putFontPixelR(screenX, screenY, 255, color, enh[(((y * (charWidth * g_sci->_enhancementMultiplier)) + x) * 4) + 3], 15, 0);
				    _screen->putFontPixelG(screenX, screenY, 255, color, enh[(((y * (charWidth * g_sci->_enhancementMultiplier)) + x) * 4) + 3], 15, 0);
				_screen->putFontPixelB(screenX, screenY, 255, color, enh[(((y * (charWidth * g_sci->_enhancementMultiplier)) + x) * 4) + 3], 15, 0);

					//} else {
					//warning("%s glpyh %d drawn out of bounds: %d, %d", _resource->name().c_str(), chr, screenX, screenY);
				//}
				   
			}
		}
	}
}

#ifdef ENABLE_SCI32
void GfxFontFromResource::drawToBuffer(uint16 chr, int16 top, int16 left, byte color, bool greyedOutput, byte *buffer, int16 bufWidth, int16 bufHeight) {
	if (chr >= _numChars) {
		// SSCI silently ignores attempts to draw characters that do not exist
		// in the font; for now, emit warnings if this happens, to learn if
		// it leads to any bugs
		warning("%s is missing glyph %d", _resource->name().c_str(), chr);
		return;
	}

	int charWidth = getCharWidth(chr);
	int charHeight = getCharHeight(chr);
	byte b = 0, mask = 0xFF;
	int16 greyedTop = top;

	SciSpan<const byte> charData = getCharData(chr);
	for (int y = 0; y < charHeight; y++) {
		if (greyedOutput)
			mask = ((greyedTop++) % 2) ? 0xAA : 0x55;
		for (int x = 0; x < charWidth; x++) {
			if ((x & 7) == 0) // fetching next data byte
				b = *(charData++) & mask;
			if (b & 0x80) {	// if MSB is set - paint it
				int bufX = left + x;
				int bufY = top + y;
				if (0 <= bufX && bufX < bufWidth && 0 <= bufY && bufY < bufHeight) {
					int offset = bufY * bufWidth + bufX;
					buffer[offset] = color;
				} else {
					warning("%s glpyh %d drawn out of bounds: %d, %d", _resource->name().c_str(), chr, bufX, bufY);
				}
			}
			b = b << 1;
		}
	}
}
#endif

} // End of namespace Sci
