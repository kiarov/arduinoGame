int charPos = 26;
int charFrame = 0;

static const unsigned char PROGMEM hilario[][48] = {
  { 0x00, 0x00, 0x1F, 0xE0, 0x3F, 0xD0, 0x7F, 0xC8, 0x7F, 0xFF, 0x30, 0x08, 0x38, 0x24, 0x48, 0x02,
    0x41, 0x02, 0x21, 0x82, 0x11, 0xFC, 0x10, 0xF8, 0x1F, 0xE0, 0x24, 0x50, 0x44, 0x4C, 0x84, 0x42,
    0x9C, 0x72, 0xEF, 0xEE, 0xAF, 0xEA, 0xEC, 0x6E, 0x0C, 0x60, 0x0C, 0x60, 0x7C, 0x7C, 0x7C, 0x7C
  },
  {
    0x00, 0x00, 0x1F, 0xE0, 0x3F, 0xB0, 0x7F, 0x98, 0x7F, 0xFE, 0x30, 0x08, 0x38, 0xA8, 0x48, 0x04,
0x41, 0x04, 0x21, 0x84, 0x11, 0xF8, 0x10, 0xF0, 0x1F, 0xE0, 0x14, 0xA0, 0x14, 0xA0, 0x14, 0x78,
0x1E, 0x28, 0x1F, 0x28, 0x0F, 0xF8, 0x7F, 0x80, 0x7D, 0x80, 0x61, 0x80, 0x61, 0xE0, 0x01, 0xE0
  },
  { 0x00, 0x00, 0x1F, 0xE0, 0x3F, 0xD0, 0x7F, 0xC8, 0x7F, 0xFF, 0x30, 0x08, 0x38, 0x24, 0x48, 0x02,
    0x41, 0x02, 0x21, 0x82, 0x11, 0xFC, 0x10, 0xF8, 0x1F, 0xE0, 0x24, 0x50, 0x44, 0x53, 0x84, 0x53,
    0x9C, 0x73, 0xEF, 0xFF, 0xAF, 0xFF, 0xE6, 0x00, 0x06, 0x00, 0x03, 0x00, 0x1F, 0x00, 0x1F, 0x00
  }
};
