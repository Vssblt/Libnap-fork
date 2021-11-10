#include "aes.h"
_NAP_BEGIN


const uint8_t gm_2[]{
	0x00, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e,
	0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e,
	0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e,
	0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e,
	0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e,
	0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 0xbe,
	0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0xde,
	0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe,
	0x1b, 0x19, 0x1f, 0x1d, 0x13, 0x11, 0x17, 0x15, 0x0b, 0x09, 0x0f, 0x0d, 0x03, 0x01, 0x07, 0x05,
	0x3b, 0x39, 0x3f, 0x3d, 0x33, 0x31, 0x37, 0x35, 0x2b, 0x29, 0x2f, 0x2d, 0x23, 0x21, 0x27, 0x25,
	0x5b, 0x59, 0x5f, 0x5d, 0x53, 0x51, 0x57, 0x55, 0x4b, 0x49, 0x4f, 0x4d, 0x43, 0x41, 0x47, 0x45,
	0x7b, 0x79, 0x7f, 0x7d, 0x73, 0x71, 0x77, 0x75, 0x6b, 0x69, 0x6f, 0x6d, 0x63, 0x61, 0x67, 0x65,
	0x9b, 0x99, 0x9f, 0x9d, 0x93, 0x91, 0x97, 0x95, 0x8b, 0x89, 0x8f, 0x8d, 0x83, 0x81, 0x87, 0x85,
	0xbb, 0xb9, 0xbf, 0xbd, 0xb3, 0xb1, 0xb7, 0xb5, 0xab, 0xa9, 0xaf, 0xad, 0xa3, 0xa1, 0xa7, 0xa5,
	0xdb, 0xd9, 0xdf, 0xdd, 0xd3, 0xd1, 0xd7, 0xd5, 0xcb, 0xc9, 0xcf, 0xcd, 0xc3, 0xc1, 0xc7, 0xc5,
	0xfb, 0xf9, 0xff, 0xfd, 0xf3, 0xf1, 0xf7, 0xf5, 0xeb, 0xe9, 0xef, 0xed, 0xe3, 0xe1, 0xe7, 0xe5,
};

const uint8_t gm_3[]{
	0x00, 0x03, 0x06, 0x05, 0x0c, 0x0f, 0x0a, 0x09, 0x18, 0x1b, 0x1e, 0x1d, 0x14, 0x17, 0x12, 0x11,
	0x30, 0x33, 0x36, 0x35, 0x3c, 0x3f, 0x3a, 0x39, 0x28, 0x2b, 0x2e, 0x2d, 0x24, 0x27, 0x22, 0x21,
	0x60, 0x63, 0x66, 0x65, 0x6c, 0x6f, 0x6a, 0x69, 0x78, 0x7b, 0x7e, 0x7d, 0x74, 0x77, 0x72, 0x71,
	0x50, 0x53, 0x56, 0x55, 0x5c, 0x5f, 0x5a, 0x59, 0x48, 0x4b, 0x4e, 0x4d, 0x44, 0x47, 0x42, 0x41,
	0xc0, 0xc3, 0xc6, 0xc5, 0xcc, 0xcf, 0xca, 0xc9, 0xd8, 0xdb, 0xde, 0xdd, 0xd4, 0xd7, 0xd2, 0xd1,
	0xf0, 0xf3, 0xf6, 0xf5, 0xfc, 0xff, 0xfa, 0xf9, 0xe8, 0xeb, 0xee, 0xed, 0xe4, 0xe7, 0xe2, 0xe1,
	0xa0, 0xa3, 0xa6, 0xa5, 0xac, 0xaf, 0xaa, 0xa9, 0xb8, 0xbb, 0xbe, 0xbd, 0xb4, 0xb7, 0xb2, 0xb1,
	0x90, 0x93, 0x96, 0x95, 0x9c, 0x9f, 0x9a, 0x99, 0x88, 0x8b, 0x8e, 0x8d, 0x84, 0x87, 0x82, 0x81,
	0x9b, 0x98, 0x9d, 0x9e, 0x97, 0x94, 0x91, 0x92, 0x83, 0x80, 0x85, 0x86, 0x8f, 0x8c, 0x89, 0x8a,
	0xab, 0xa8, 0xad, 0xae, 0xa7, 0xa4, 0xa1, 0xa2, 0xb3, 0xb0, 0xb5, 0xb6, 0xbf, 0xbc, 0xb9, 0xba,
	0xfb, 0xf8, 0xfd, 0xfe, 0xf7, 0xf4, 0xf1, 0xf2, 0xe3, 0xe0, 0xe5, 0xe6, 0xef, 0xec, 0xe9, 0xea,
	0xcb, 0xc8, 0xcd, 0xce, 0xc7, 0xc4, 0xc1, 0xc2, 0xd3, 0xd0, 0xd5, 0xd6, 0xdf, 0xdc, 0xd9, 0xda,
	0x5b, 0x58, 0x5d, 0x5e, 0x57, 0x54, 0x51, 0x52, 0x43, 0x40, 0x45, 0x46, 0x4f, 0x4c, 0x49, 0x4a,
	0x6b, 0x68, 0x6d, 0x6e, 0x67, 0x64, 0x61, 0x62, 0x73, 0x70, 0x75, 0x76, 0x7f, 0x7c, 0x79, 0x7a,
	0x3b, 0x38, 0x3d, 0x3e, 0x37, 0x34, 0x31, 0x32, 0x23, 0x20, 0x25, 0x26, 0x2f, 0x2c, 0x29, 0x2a,
	0x0b, 0x08, 0x0d, 0x0e, 0x07, 0x04, 0x01, 0x02, 0x13, 0x10, 0x15, 0x16, 0x1f, 0x1c, 0x19, 0x1a,
};

const uint8_t gm_9[]{
	0x00, 0x09, 0x12, 0x1b, 0x24, 0x2d, 0x36, 0x3f, 0x48, 0x41, 0x5a, 0x53, 0x6c, 0x65, 0x7e, 0x77,
	0x90, 0x99, 0x82, 0x8b, 0xb4, 0xbd, 0xa6, 0xaf, 0xd8, 0xd1, 0xca, 0xc3, 0xfc, 0xf5, 0xee, 0xe7,
	0x3b, 0x32, 0x29, 0x20, 0x1f, 0x16, 0x0d, 0x04, 0x73, 0x7a, 0x61, 0x68, 0x57, 0x5e, 0x45, 0x4c,
	0xab, 0xa2, 0xb9, 0xb0, 0x8f, 0x86, 0x9d, 0x94, 0xe3, 0xea, 0xf1, 0xf8, 0xc7, 0xce, 0xd5, 0xdc,
	0x76, 0x7f, 0x64, 0x6d, 0x52, 0x5b, 0x40, 0x49, 0x3e, 0x37, 0x2c, 0x25, 0x1a, 0x13, 0x08, 0x01,
	0xe6, 0xef, 0xf4, 0xfd, 0xc2, 0xcb, 0xd0, 0xd9, 0xae, 0xa7, 0xbc, 0xb5, 0x8a, 0x83, 0x98, 0x91,
	0x4d, 0x44, 0x5f, 0x56, 0x69, 0x60, 0x7b, 0x72, 0x05, 0x0c, 0x17, 0x1e, 0x21, 0x28, 0x33, 0x3a,
	0xdd, 0xd4, 0xcf, 0xc6, 0xf9, 0xf0, 0xeb, 0xe2, 0x95, 0x9c, 0x87, 0x8e, 0xb1, 0xb8, 0xa3, 0xaa,
	0xec, 0xe5, 0xfe, 0xf7, 0xc8, 0xc1, 0xda, 0xd3, 0xa4, 0xad, 0xb6, 0xbf, 0x80, 0x89, 0x92, 0x9b,
	0x7c, 0x75, 0x6e, 0x67, 0x58, 0x51, 0x4a, 0x43, 0x34, 0x3d, 0x26, 0x2f, 0x10, 0x19, 0x02, 0x0b,
	0xd7, 0xde, 0xc5, 0xcc, 0xf3, 0xfa, 0xe1, 0xe8, 0x9f, 0x96, 0x8d, 0x84, 0xbb, 0xb2, 0xa9, 0xa0,
	0x47, 0x4e, 0x55, 0x5c, 0x63, 0x6a, 0x71, 0x78, 0x0f, 0x06, 0x1d, 0x14, 0x2b, 0x22, 0x39, 0x30,
	0x9a, 0x93, 0x88, 0x81, 0xbe, 0xb7, 0xac, 0xa5, 0xd2, 0xdb, 0xc0, 0xc9, 0xf6, 0xff, 0xe4, 0xed,
	0x0a, 0x03, 0x18, 0x11, 0x2e, 0x27, 0x3c, 0x35, 0x42, 0x4b, 0x50, 0x59, 0x66, 0x6f, 0x74, 0x7d,
	0xa1, 0xa8, 0xb3, 0xba, 0x85, 0x8c, 0x97, 0x9e, 0xe9, 0xe0, 0xfb, 0xf2, 0xcd, 0xc4, 0xdf, 0xd6,
	0x31, 0x38, 0x23, 0x2a, 0x15, 0x1c, 0x07, 0x0e, 0x79, 0x70, 0x6b, 0x62, 0x5d, 0x54, 0x4f, 0x46
};

const uint8_t gm_B[]{
	0x00, 0x0b, 0x16, 0x1d, 0x2c, 0x27, 0x3a, 0x31, 0x58, 0x53, 0x4e, 0x45, 0x74, 0x7f, 0x62, 0x69,
	0xb0, 0xbb, 0xa6, 0xad, 0x9c, 0x97, 0x8a, 0x81, 0xe8, 0xe3, 0xfe, 0xf5, 0xc4, 0xcf, 0xd2, 0xd9,
	0x7b, 0x70, 0x6d, 0x66, 0x57, 0x5c, 0x41, 0x4a, 0x23, 0x28, 0x35, 0x3e, 0x0f, 0x04, 0x19, 0x12,
	0xcb, 0xc0, 0xdd, 0xd6, 0xe7, 0xec, 0xf1, 0xfa, 0x93, 0x98, 0x85, 0x8e, 0xbf, 0xb4, 0xa9, 0xa2,
	0xf6, 0xfd, 0xe0, 0xeb, 0xda, 0xd1, 0xcc, 0xc7, 0xae, 0xa5, 0xb8, 0xb3, 0x82, 0x89, 0x94, 0x9f,
	0x46, 0x4d, 0x50, 0x5b, 0x6a, 0x61, 0x7c, 0x77, 0x1e, 0x15, 0x08, 0x03, 0x32, 0x39, 0x24, 0x2f,
	0x8d, 0x86, 0x9b, 0x90, 0xa1, 0xaa, 0xb7, 0xbc, 0xd5, 0xde, 0xc3, 0xc8, 0xf9, 0xf2, 0xef, 0xe4,
	0x3d, 0x36, 0x2b, 0x20, 0x11, 0x1a, 0x07, 0x0c, 0x65, 0x6e, 0x73, 0x78, 0x49, 0x42, 0x5f, 0x54,
	0xf7, 0xfc, 0xe1, 0xea, 0xdb, 0xd0, 0xcd, 0xc6, 0xaf, 0xa4, 0xb9, 0xb2, 0x83, 0x88, 0x95, 0x9e,
	0x47, 0x4c, 0x51, 0x5a, 0x6b, 0x60, 0x7d, 0x76, 0x1f, 0x14, 0x09, 0x02, 0x33, 0x38, 0x25, 0x2e,
	0x8c, 0x87, 0x9a, 0x91, 0xa0, 0xab, 0xb6, 0xbd, 0xd4, 0xdf, 0xc2, 0xc9, 0xf8, 0xf3, 0xee, 0xe5,
	0x3c, 0x37, 0x2a, 0x21, 0x10, 0x1b, 0x06, 0x0d, 0x64, 0x6f, 0x72, 0x79, 0x48, 0x43, 0x5e, 0x55,
	0x01, 0x0a, 0x17, 0x1c, 0x2d, 0x26, 0x3b, 0x30, 0x59, 0x52, 0x4f, 0x44, 0x75, 0x7e, 0x63, 0x68,
	0xb1, 0xba, 0xa7, 0xac, 0x9d, 0x96, 0x8b, 0x80, 0xe9, 0xe2, 0xff, 0xf4, 0xc5, 0xce, 0xd3, 0xd8,
	0x7a, 0x71, 0x6c, 0x67, 0x56, 0x5d, 0x40, 0x4b, 0x22, 0x29, 0x34, 0x3f, 0x0e, 0x05, 0x18, 0x13,
	0xca, 0xc1, 0xdc, 0xd7, 0xe6, 0xed, 0xf0, 0xfb, 0x92, 0x99, 0x84, 0x8f, 0xbe, 0xb5, 0xa8, 0xa3,
};

const uint8_t gm_D[]{
	0x00, 0x0d, 0x1a, 0x17, 0x34, 0x39, 0x2e, 0x23, 0x68, 0x65, 0x72, 0x7f, 0x5c, 0x51, 0x46, 0x4b,
	0xd0, 0xdd, 0xca, 0xc7, 0xe4, 0xe9, 0xfe, 0xf3, 0xb8, 0xb5, 0xa2, 0xaf, 0x8c, 0x81, 0x96, 0x9b,
	0xbb, 0xb6, 0xa1, 0xac, 0x8f, 0x82, 0x95, 0x98, 0xd3, 0xde, 0xc9, 0xc4, 0xe7, 0xea, 0xfd, 0xf0,
	0x6b, 0x66, 0x71, 0x7c, 0x5f, 0x52, 0x45, 0x48, 0x03, 0x0e, 0x19, 0x14, 0x37, 0x3a, 0x2d, 0x20,
	0x6d, 0x60, 0x77, 0x7a, 0x59, 0x54, 0x43, 0x4e, 0x05, 0x08, 0x1f, 0x12, 0x31, 0x3c, 0x2b, 0x26,
	0xbd, 0xb0, 0xa7, 0xaa, 0x89, 0x84, 0x93, 0x9e, 0xd5, 0xd8, 0xcf, 0xc2, 0xe1, 0xec, 0xfb, 0xf6,
	0xd6, 0xdb, 0xcc, 0xc1, 0xe2, 0xef, 0xf8, 0xf5, 0xbe, 0xb3, 0xa4, 0xa9, 0x8a, 0x87, 0x90, 0x9d,
	0x06, 0x0b, 0x1c, 0x11, 0x32, 0x3f, 0x28, 0x25, 0x6e, 0x63, 0x74, 0x79, 0x5a, 0x57, 0x40, 0x4d,
	0xda, 0xd7, 0xc0, 0xcd, 0xee, 0xe3, 0xf4, 0xf9, 0xb2, 0xbf, 0xa8, 0xa5, 0x86, 0x8b, 0x9c, 0x91,
	0x0a, 0x07, 0x10, 0x1d, 0x3e, 0x33, 0x24, 0x29, 0x62, 0x6f, 0x78, 0x75, 0x56, 0x5b, 0x4c, 0x41,
	0x61, 0x6c, 0x7b, 0x76, 0x55, 0x58, 0x4f, 0x42, 0x09, 0x04, 0x13, 0x1e, 0x3d, 0x30, 0x27, 0x2a,
	0xb1, 0xbc, 0xab, 0xa6, 0x85, 0x88, 0x9f, 0x92, 0xd9, 0xd4, 0xc3, 0xce, 0xed, 0xe0, 0xf7, 0xfa,
	0xb7, 0xba, 0xad, 0xa0, 0x83, 0x8e, 0x99, 0x94, 0xdf, 0xd2, 0xc5, 0xc8, 0xeb, 0xe6, 0xf1, 0xfc,
	0x67, 0x6a, 0x7d, 0x70, 0x53, 0x5e, 0x49, 0x44, 0x0f, 0x02, 0x15, 0x18, 0x3b, 0x36, 0x21, 0x2c,
	0x0c, 0x01, 0x16, 0x1b, 0x38, 0x35, 0x22, 0x2f, 0x64, 0x69, 0x7e, 0x73, 0x50, 0x5d, 0x4a, 0x47,
	0xdc, 0xd1, 0xc6, 0xcb, 0xe8, 0xe5, 0xf2, 0xff, 0xb4, 0xb9, 0xae, 0xa3, 0x80, 0x8d, 0x9a, 0x97
};

const uint8_t gm_E[]{
	0x00, 0x0e, 0x1c, 0x12, 0x38, 0x36, 0x24, 0x2a, 0x70, 0x7e, 0x6c, 0x62, 0x48, 0x46, 0x54, 0x5a,
	0xe0, 0xee, 0xfc, 0xf2, 0xd8, 0xd6, 0xc4, 0xca, 0x90, 0x9e, 0x8c, 0x82, 0xa8, 0xa6, 0xb4, 0xba,
	0xdb, 0xd5, 0xc7, 0xc9, 0xe3, 0xed, 0xff, 0xf1, 0xab, 0xa5, 0xb7, 0xb9, 0x93, 0x9d, 0x8f, 0x81,
	0x3b, 0x35, 0x27, 0x29, 0x03, 0x0d, 0x1f, 0x11, 0x4b, 0x45, 0x57, 0x59, 0x73, 0x7d, 0x6f, 0x61,
	0xad, 0xa3, 0xb1, 0xbf, 0x95, 0x9b, 0x89, 0x87, 0xdd, 0xd3, 0xc1, 0xcf, 0xe5, 0xeb, 0xf9, 0xf7,
	0x4d, 0x43, 0x51, 0x5f, 0x75, 0x7b, 0x69, 0x67, 0x3d, 0x33, 0x21, 0x2f, 0x05, 0x0b, 0x19, 0x17,
	0x76, 0x78, 0x6a, 0x64, 0x4e, 0x40, 0x52, 0x5c, 0x06, 0x08, 0x1a, 0x14, 0x3e, 0x30, 0x22, 0x2c,
	0x96, 0x98, 0x8a, 0x84, 0xae, 0xa0, 0xb2, 0xbc, 0xe6, 0xe8, 0xfa, 0xf4, 0xde, 0xd0, 0xc2, 0xcc,
	0x41, 0x4f, 0x5d, 0x53, 0x79, 0x77, 0x65, 0x6b, 0x31, 0x3f, 0x2d, 0x23, 0x09, 0x07, 0x15, 0x1b,
	0xa1, 0xaf, 0xbd, 0xb3, 0x99, 0x97, 0x85, 0x8b, 0xd1, 0xdf, 0xcd, 0xc3, 0xe9, 0xe7, 0xf5, 0xfb,
	0x9a, 0x94, 0x86, 0x88, 0xa2, 0xac, 0xbe, 0xb0, 0xea, 0xe4, 0xf6, 0xf8, 0xd2, 0xdc, 0xce, 0xc0,
	0x7a, 0x74, 0x66, 0x68, 0x42, 0x4c, 0x5e, 0x50, 0x0a, 0x04, 0x16, 0x18, 0x32, 0x3c, 0x2e, 0x20,
	0xec, 0xe2, 0xf0, 0xfe, 0xd4, 0xda, 0xc8, 0xc6, 0x9c, 0x92, 0x80, 0x8e, 0xa4, 0xaa, 0xb8, 0xb6,
	0x0c, 0x02, 0x10, 0x1e, 0x34, 0x3a, 0x28, 0x26, 0x7c, 0x72, 0x60, 0x6e, 0x44, 0x4a, 0x58, 0x56,
	0x37, 0x39, 0x2b, 0x25, 0x0f, 0x01, 0x13, 0x1d, 0x47, 0x49, 0x5b, 0x55, 0x7f, 0x71, 0x63, 0x6d,
	0xd7, 0xd9, 0xcb, 0xc5, 0xef, 0xe1, 0xf3, 0xfd, 0xa7, 0xa9, 0xbb, 0xb5, 0x9f, 0x91, 0x83, 0x8d
};

const uint32_t aes_rcon[11] = {
		0x01000000UL,0x01000000UL, 0x02000000UL, 0x04000000UL, 0x08000000UL,
		0x10000000UL,0x20000000UL, 0x40000000UL, 0x80000000UL, 0x1B000000UL,
		0x36000000UL
};
const uint8_t aes_s_box[256] = {
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};
const uint8_t aes_inv_s_box[256] = {
	0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
	0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
	0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
	0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
	0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
	0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
	0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
	0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
	0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
	0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
	0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
	0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
	0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
	0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
	0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
	0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};



/*
	Nb = 4; 4 * 32bit = 128bit
	Nk  4,6,8    Nk * word(32bit) = Key Length
	Nr(number of rounds) : 10,12,14
	The Key Expansion generates a total of Nb(4) (Nr + 1) words
	Nb (Nr + 1) = 44,52,60 ��word��
*/

//static const uint8_t aes_3mt[4][4] = {
//	0x02, 0x03, 0x01, 0x01,
//	0x01, 0x02, 0x03, 0x01,
//	0x01, 0x01, 0x02, 0x03,
//	0x03, 0x01, 0x01, 0x02 };
//static const uint8_t aes_inv_3mt[4][4] = {
//	0x0E, 0x0B, 0x0D, 0x09,
//	0x09, 0x0E, 0x0B, 0x0D,
//	0x0D, 0x09, 0x0E, 0x0B,
//	0x0B, 0x0D, 0x09, 0x0E };


////-------------------------------------------------------------AesKey



AesKey::AesKey(const char* key, size_t length){
	if (length <= 16) {
		if (length != 16) {
			char tmp[16] = { 0 };
			memcpy(tmp, key, length);
			_init(tmp, Type::T_128);
		}else {
			_init(key, Type::T_128);
		}
		return;
	}
	if (length <= 24) {
		if (length != 24) {
			char tmp[24] = { 0 };
			memcpy(tmp, key, length);
			_init(tmp, Type::T_192);
		} else {
			_init(key, Type::T_192);
		}
		return;
	}
	if (length > 32) length = 32;

	if (length != 32) {
		char tmp[32] = { 0 };
		memcpy(tmp, key, length);
		_init(tmp, Type::T_256);
	} else {
		_init(key, Type::T_256);
	}
}
AesKey::AesKey(const char* key, Type _type) {
	//û���жϱ߽�
	_init(key, _type);
}
AesKey::AesKey(const btring& key, Type _type){

	//��ֹ���ʹ���
	btring _key = key;
	switch (_type) {
	case Type::T_128: _key.resize(16); break;
	case Type::T_192: _key.resize(24); break;
	case Type::T_256: _key.resize(32); break;
	}
	
	_init((const char*)_key.str(), _type);
}
AesKey::AesKey(AesKey&& old)noexcept :type(old.type) {
	this->_array_length = old._array_length;

	this->_keys_e = old._keys_e;
	this->_keys_d = old._keys_d;
	old._keys_e = nullptr;
	old._keys_d = nullptr;
}
AesKey::AesKey(const AesKey& old) :type(old.type) {
	uint32_t length = old._array_length;

	this->_keys_e = new uint32_t[length];
	this->_keys_d = new uint32_t[length];
	memcpy(this->_keys_e, old._keys_e, sizeof(uint32_t) * length);
	memcpy(this->_keys_d, old._keys_d, sizeof(uint32_t) * length);
	this->_array_length = length;

}
AesKey::~AesKey() {
	if (_keys_e != nullptr) {
		delete[] _keys_e;
	}
	if (_keys_d != nullptr) {
		delete[] _keys_d;
	}
}
uint32_t AesKey::round() const {
	switch (type) {
	case Type::T_128: return 10;
	case Type::T_192: return 12;
	case Type::T_256: return 14;
	}
	assert(false);
	return 0;
}
void AesKey::_init(const char* key, Type _type){
	this->type = _type;
	_array_length = 4 * (round() + 1);
	_keys_e = new uint32_t[_array_length];
	_keys_d = new uint32_t[_array_length];

	_key_expansion((const uint8_t*)key);
}
void AesKey::_key_expansion(const uint8_t* key) {

	const uint32_t Nk = (uint32_t)type; //key length
	const uint32_t exp_length = _array_length; //Nb (Nr + 1) 

	//Nk = key_length

	/*
		����Կ����˳�򿽱�����Կ������
		ÿ�ο����ĸ��ֽڵ���Կ���뵽һ��u32������
	*/
	for (uint32_t i = 0; i < Nk; i++) {
		int t = i * 4;
		_keys_e[i] = INT32(key[t], key[t + 1], key[t + 2], key[t + 3]);
	}

	auto subword = [](uint32_t v)-> uint32_t {
		uint8_t* p = (uint8_t*)&v;
		for (int i = 0; i < 4; i++) {
			p[i] = aes_s_box[p[i]];
		}
		return v;
	};

	//ѭ������8bitȻ���ֽ��滻
	auto mix = [subword](uint32_t n)-> uint32_t {
		uint32_t ret = 0, _ret;

		//rotword
		uint8_t temp = (n & 0xff000000) >> 24;
		n <<= 8;
		_ret = n | temp;
		ret = subword(_ret);

		return ret;
	};

	/*
		��������Ŀ�������
		������Կ
	*/
	for (uint32_t i = Nk; i < exp_length; i++) {
		uint32_t temp = _keys_e[i - 1]; //��һ��u32
		if (i % Nk == 0) {
			temp = mix(temp) ^ aes_rcon[i / Nk];
		}
		else if ((Nk > 6) && ((i % Nk) == 4)) {
			temp = subword(temp);
		}
		_keys_e[i] = _keys_e[i - Nk] ^ temp;

	}

#ifdef AESNI
	for (uint32_t i = Nk; i < exp_length; i++) {
		uint32_t temp = _keys_e[i];
		_keys_e[i] = 0;

		_keys_e[i] |= (temp & 0xff000000) >> 24;
		_keys_e[i] |= (temp & 0x00ff0000) >> 8;
		_keys_e[i] |= (temp & 0x0000ff00) << 8;
		_keys_e[i] |= (temp & 0x000000ff) << 24;

	}
#endif


	//���������Կ
	//��d[0-3]=e[40-43]
	uint32_t* p_e = _keys_e;
	uint32_t* p_d = _keys_d + exp_length - 4;

	for (uint32_t i = 0; i < exp_length; i += 4) {
		p_d[0] = p_e[0];
		p_d[1] = p_e[1];
		p_d[2] = p_e[2];
		p_d[3] = p_e[3];

		p_d -= 4;
		p_e += 4;
	}
}

////-------------------------------------------------------------AesFun



void AesFun::g_num128(const uint8_t* x,const uint8_t* y, uint8_t* z) {
	uint8_t v[16];
	int i, j;
	memset(z, 0, 16);
	memcpy(v, y, 16);


	for (i = 0; i < 16; i++) {
		for (j = 0; j < 8; j++) {
			if (x[i] & 1 << (7 - j)) {
				/* Z_(i + 1) = Z_i XOR V_i */
				uint32_t* d = (uint32_t*)z;
				uint32_t* s = (uint32_t*)v;
				*d++ ^= *s++;
				*d++ ^= *s++;
				*d++ ^= *s++;
				*d++ ^= *s++;
			} else {
				/* Z_(i + 1) = Z_i */
			}

			if (v[15] & 0x01) {
				/* V_(i + 1) = (V_i >> 1) XOR R */
				shift_right_block(v);
				/* R = 11100001 || 0^120 */
				v[0] ^= 0xe1;
			} else {
				/* V_(i + 1) = V_i >> 1 */
				shift_right_block(v);
			}
		}
	}
}

// -- replaced by lookup table 
//static inline uint8_t g_num(uint8_t u, uint8_t v) {//���ֽڵ�٤�޻���˷�����
//	uint8_t p = 0;
//	for (int i = 0; i < 8; i++) {
//		if (u & 0x01) {
//			p ^= v;
//		}
//		uint32_t flag = (v & 0x80);
//		v <<= 1;
//		if (flag)
//			v ^= 0x1B; /* x^8 + x^4 + x^3 + x + 1 */
//		u >>= 1;
//	}
//	return p;
//}


void AesFun::shift_right_block(uint8_t* v) {
	uint32_t val;

	val = INT32(v[12], v[13], v[14], v[15]);
	val >>= 1;
	if (v[11] & 0x01)
		val |= 0x80000000;
	INT32TOCHAR(v + 12, val);

	val = INT32(v[8], v[9], v[10], v[11]);
	val >>= 1;
	if (v[7] & 0x01)
		val |= 0x80000000;
	INT32TOCHAR(v + 8, val);

	val = INT32(v[4], v[5], v[6], v[7]);
	val >>= 1;
	if (v[3] & 0x01)
		val |= 0x80000000;
	INT32TOCHAR(v + 4, val);

	val = INT32(v[0], v[1], v[2], v[3]);
	val >>= 1;
	INT32TOCHAR(v, val);
}
void AesFun::xor_128block(uint8_t* dst, const uint8_t* src)  {
	uint64_t* d = (uint64_t*)dst;
	uint64_t* s = (uint64_t*)src;
	*d++ ^= *s++;
	*d++ ^= *s++;
}

////-------------------------------------------------------------AesPadding

int AesPadding::addPadding(char* buf, uint8_t len) {
	uint8_t fill = 16 - len; //������䳤��

	switch (this->_padding_type) {
	case AesPaddingType::None:
		return 0;
	case AesPaddingType::PKCS5:
	case AesPaddingType::PKCS7:
		memset(buf + len, fill, fill);
		break;
	case AesPaddingType::ISO10126:
		buf[15] = fill;
		for (uint32_t i = len; i < 15; i++) {
			buf[i] = (uint8_t)random<uint16_t>(0, 255);;
		}
		break;
	case AesPaddingType::Zeros:
		memset(buf + len, 0x00, fill);
		break;
	default:
		assert(false);//not support padding mode
	};
	return fill;
}

//len��buf�ĳ��ȣ���addPadding��ͬ,������䳤��ȴ���������в���
int AesPadding::removePadding(char* buf, uint8_t len) {
	switch (this->_padding_type) {
	case AesPaddingType::None:
		return 0;
	case AesPaddingType::PKCS5:
	case AesPaddingType::PKCS7:
	case AesPaddingType::ISO10126:
		if (buf[len - 1] > 16) {
			return -1;
		}
		else {
			return buf[len - 1];
		}
	case AesPaddingType::Zeros:
		return 0;
	default:
		assert(false);//not support padding mode
	};
	return -1;
}

////------------------------------------------------------------- Aes - ECB - Encryption

AesECBEncryption::AesECBEncryption(AesKey key, AesPaddingType t)
	: AesPadding(t), _key(key) {

};

void AesECBEncryption::handle(const char* buf, char* out, size_t len){
	assert(len % 16 == 0);
	uint8_t matrix4x4[16];
	for (uint32_t i = 0; i < len / 16; i++) {
		char2matrix4x4(matrix4x4, (uint8_t*)buf + (i * 16));
		AesFun::encrypt_block(matrix4x4, _key);
		char2matrix4x4((uint8_t*)out + (i * 16), matrix4x4);
	}
}

btring AesECBEncryption::endinput(uint8_t* buf, uint8_t len) {
	int pad = this->addPadding((char*)buf, (uint8_t)len);
	this->add((char*)buf + 16 - pad, pad); // ��Ҫ������������һ���ⲿ��
	btring res = std::move(_result);
	return res;
}

////------------------------------------------------------------- Aes - ECB - Decryption

AesECBDecryption::AesECBDecryption(AesKey key, AesPaddingType t) :
	AesECBEncryption(key, t) {
};

void AesECBDecryption::handle(const char* buf, char* out, size_t len) {
	assert(len % 16 == 0);
	uint8_t matrix4x4[16];
	for (uint32_t i = 0; i < len / 16; i++) {
		char2matrix4x4(matrix4x4, (uint8_t*)buf + (i * 16));
		AesFun::decrypt_block(matrix4x4, _key);
		char2matrix4x4((uint8_t*)out + (i * 16), matrix4x4);
	}
}

btring AesECBDecryption::endinput(uint8_t*, uint8_t) {
	uint8_t* str = this->_result.str();
	size_t len = this->_result.size();

	int removepad = this->removePadding((char*)str + len - 1, 1);
	this->_result.resize(len - removepad);

	btring res = std::move(_result);
	return res;
}

////------------------------------------------------------------- Aes - CBC - Encryption

AesCBCEncryption::AesCBCEncryption(AesKey key, AesIV iv, AesPaddingType t)
	: AesPadding(t), _key(key), _iv(iv), _original_iv(iv) {
};

void AesCBCEncryption::handle(const char* buf, char* out, size_t len) {
	assert(len % 16 == 0);
	memcpy(out, buf, len);

	const uint8_t* _piv = _iv.get().str();

	uint8_t matrix4x4[16];
	for (uint32_t i = 0; i < len / 16; i++) {

		for (int n = 0; n < 16; n++) {
			*(out + (i * 16) + n) ^= _piv[n];
		}

		char2matrix4x4(matrix4x4, (uint8_t*)out + (i * 16));
		AesFun::encrypt_block(matrix4x4, this->_key);
		char2matrix4x4((uint8_t*)out + (i * 16), matrix4x4);

		_piv = (uint8_t*)out + (i * 16);
	}
	_iv.set(btring(_piv, 16));
}

btring AesCBCEncryption::endinput(uint8_t* buf, uint8_t len) {
	int pad = this->addPadding((char*)buf, (uint8_t)len);
	this->add((char*)buf + 16 - pad, pad); // ��Ҫ������������һ���ⲿ��
	btring res = std::move(_result);
	return res;
}

void AesCBCEncryption::resetdata() {
	this->_iv = this->_original_iv;
};

////------------------------------------------------------------- Aes - CBC - Decryption

AesCBCDecryption::AesCBCDecryption(AesKey key, AesIV iv, AesPaddingType t)
	: AesCBCEncryption(key, iv, t) {

};

void AesCBCDecryption::handle(const char* buf, char* out, size_t len) {
	assert(len % 16 == 0);
	memcpy(out, buf, len);

	const uint8_t* _piv = _iv.get().str();

	uint8_t matrix4x4[16];
	for (uint32_t i = 0; i < len / 16; i++) {

		char2matrix4x4(matrix4x4, (uint8_t*)out + i * 16);
		AesFun::decrypt_block(matrix4x4, this->_key);
		char2matrix4x4((uint8_t*)out + i * 16, matrix4x4);

		for (int n = 0; n < 16; n++)
			*((uint8_t*)out + i * 16 + n) ^= _piv[n];

		_piv = (const uint8_t*)buf + i * 16;
	}
	_iv.set(btring(_piv, 16));
}

btring AesCBCDecryption::endinput(uint8_t*, uint8_t) {
	uint8_t* str = this->_result.str();
	size_t len = this->_result.size();

	int removepad = this->removePadding((char*)str + len - 1, 1);
	this->_result.resize(len - removepad);

	btring res = std::move(_result);
	return res;
}

////------------------------------------------------------------- Aes - CTR - Encryption

AesCTREncryption::AesCTREncryption(AesKey key, AesIV counter)
	:_key(key), _counter(counter), _original_counter(counter) {

};

void AesCTREncryption::handle(const char* buf, char* out, size_t len) {
	memcpy(out, buf, len);

	uint8_t matrix4x4[16];
	for (uint32_t i = 0; i < len / 16; i++) {
		uint8_t temp[16];
		char2matrix4x4(matrix4x4, _counter.get().str());
		AesFun::encrypt_block(matrix4x4, this->_key);
		char2matrix4x4(temp, matrix4x4);

		const uint32_t block = i * 16;
		for (int n = 0; n < 16; n++)
			*(out + block + n) = *(buf + block + n) ^ temp[n];

		_counter++;
	}
}

btring AesCTREncryption::endinput(uint8_t* buf, uint8_t len) {

	if (len != 0) {
		//��Ҫ�ֶ����Ȼ��ɾ����һ����
		int f = 16 - len;
		this->add((const char*)buf + len, f);
		this->_result.resize(this->_result.size() - f);
	}

	btring res = std::move(_result);
	this->_original_counter = this->_counter; //CTR��Ҫ�������������ֹ����ԭ
	return res;
}

void AesCTREncryption::resetdata() {
	this->_counter = this->_original_counter;
};

////------------------------------------------------------------- Aes - GCM - Encryption

AesGCMEncryption::AesGCMEncryption(AesKey key, AesGCMIV iv, btring aad)
	:_aad(aad), _key(key), _original_iv(iv), _iv(iv) {
	encrypt_block(H, H);
	resetdata();
};

void AesGCMEncryption::encrypt_block(const uint8_t* plain, uint8_t* crypt) {
	uint8_t matrix4x4[16];
	char2matrix4x4(matrix4x4, plain);
	AesFun::encrypt_block(matrix4x4, _key);
	char2matrix4x4(crypt, matrix4x4);
}

void AesGCMEncryption::calculate_j0() {
	//uint8_t len_buf[16] = { 0 };

	//Only 96-bit IV allowed 
	memcpy(J0, _iv.get().str(), 12);
	memset(J0 + 12, 0, 16 - 12/*iv_len*/);
	J0[16 - 1] = 0x01;

	memcpy(J0_begin, J0, 16);
	inc32(J0);

	//if (this->_iv.get().size() == 12) {
	//	/* Prepare block J_0 = IV || 0^31 || 1  > if len(IV) = 96 */
	//	memcpy(J0, iv, iv_len);
	//	memset(J0 + iv_len, 0, 16 - 12/*iv_len*/);
	//	J0[16 - 1] = 0x01;
	//} else {
	//	/*
	//	 * s = 128 * ceil(len(IV)/128) - len(IV)
	//	 * J_0 = GHASH_H(IV || 0^(s+64) || [len(IV)]_64) > otherwise
	//	 */
	//	memset(J0, 0, 16);
	//	ghash(H, iv, iv_len, J0);
	//	//U64TOCHAR(len_buf, 0);                   //��8byte ʹ���� 0 ���
	//	INT32TOCHAR(len_buf + 8, iv_len * 8);      //��8byte �����  iv_len * 8
	//	ghash(H, len_buf, sizeof(len_buf), J0);
	//}
}

void AesGCMEncryption::inc32(uint8_t* block) {
	//uint32_t val;
	//val = INT32(block[16 - 4], block[16 - 3], block[16 - 2], block[16 - 1]);
	//val++;
	//INT32TOCHAR(block + 16 - 4, val);

	if (block[16 - 1] < 0xff) {
		(block[16 - 1])++;
		return;
	}
	uint8_t temp[4] = { 0 };

	temp[0] = block[16 - 1];
	temp[1] = block[16 - 2];
	temp[2] = block[16 - 3];
	temp[3] = block[16 - 4];
	uint32_t* t = (uint32_t*)temp;
	(*t)++;
	block[16 - 1] = temp[0];
	block[16 - 2] = temp[1];
	block[16 - 3] = temp[2];
	block[16 - 4] = temp[3];
}

void AesGCMEncryption::gctr(const char* in, char* out, size_t len) {
	assert(len % 16 == 0);

	size_t i, n;
	const uint8_t* xpos = (uint8_t*)in;
	uint8_t* ypos = (uint8_t*)out;

	n = len / 16;

	/* 16Byte blocks */
	for (i = 0; i < n; i++) {
		uint8_t temp_buffer[16];
		encrypt_block(J0, temp_buffer);
		AesFun::xor_128block(temp_buffer, xpos);
		memcpy(ypos, temp_buffer, 16);
		xpos += 16;
		ypos += 16;
		inc32(J0);
	}
}

void AesGCMEncryption::ghash(const uint8_t* x, size_t xlen) {
	//assert(xlen % 16 == 0); _aad

	size_t m, i;
	const uint8_t* xpos = x;
	uint8_t tmp[16];

	m = xlen / 16;

	for (i = 0; i < m; i++) {
		/* Y_i = (Y^(i-1) XOR X_i) dot H */
		AesFun::xor_128block(S, xpos);
		xpos += 16;

		/* dot operation:
		 * multiplication operation for binary Galois (finite) field of
		 * 2^128 elements */
		AesFun::g_num128(S, H, tmp);
		memcpy(S, tmp, 16);
	}

	if (x + xlen > xpos) {
		/* Add zero padded last block */
		size_t last = x + xlen - xpos;
		memcpy(tmp, xpos, last);
		memset(tmp + last, 0, sizeof(tmp) - last);

		/* Y_i = (Y^(i-1) XOR X_i) dot H */
		AesFun::xor_128block(S, tmp);

		/* dot operation:
		 * multiplication operation for binary Galois (finite) field of
		 * 2^128 elements */
		AesFun::g_num128(S, H, tmp);
		memcpy(S, tmp, 16);
	}
}

void AesGCMEncryption::handle(const char* buf, char* out, size_t len) {
	gctr(buf, out, len);
	ghash((const uint8_t*)out, len);
}

std::pair<btring, btring> AesGCMEncryption::endinput(uint8_t* buf, uint8_t len) {

	if (len != 0) {
		//��Ҫ�ֶ����Ȼ��ɾ����һ����
		char tmp[16] = { 0 };
		char tmpout[16] = { 0 };
		memcpy(tmp, buf, len);
		gctr(tmp, tmpout, 16);
		btring b_tmpout(tmpout, len);
		this->_result.append(b_tmpout);

		ghash((const uint8_t*)tmpout, len);
	}
	btring res = std::move(_result);

	//cal tag

	uint8_t len_buf[16];
	U64TOCHAR(len_buf, _aad.size() * 8ULL);
	U64TOCHAR(len_buf + 8, res.size() * 8ULL);
	ghash(len_buf, sizeof(len_buf));

	char tag[16];
	memcpy(J0, J0_begin, 16);
	gctr((const char*)S, tag, sizeof(S));
	btring _tag(tag, 16);
	this->_original_iv++;

	return std::make_pair(_tag, res);
}

void AesGCMEncryption::resetdata() {
	this->_iv = this->_original_iv;
	calculate_j0();
	//ghash
	memset(S, 0, 16);
	ghash(_aad.str(), _aad.size());
};

////------------------------------------------------------------- Aes - GCM - Decryption

AesGCMDecryption::AesGCMDecryption(AesKey key, AesGCMIV iv, btring aad)
	:AesGCMEncryption(key, iv, aad) {
};

void AesGCMDecryption::handle(const char* buf, char* out, size_t len) {
	ghash((const uint8_t*)buf, len);
	gctr(buf, out, len);
}

std::pair<btring, btring> AesGCMDecryption::endinput(uint8_t* buf, uint8_t len) {

	if (len != 0) {
		//��Ҫ�ֶ����Ȼ��ɾ����һ����
		char tmp[16] = { 0 };
		char tmpout[16] = { 0 };
		memcpy(tmp, buf, len);
		gctr(tmp, tmpout, 16);
		btring b_tmpout(tmpout, len);
		this->_result.append(b_tmpout);
		ghash((const uint8_t*)buf, len);
	}
	btring res = std::move(_result);

	//cal tag

	uint8_t len_buf[16];
	U64TOCHAR(len_buf, _aad.size() * 8);
	U64TOCHAR(len_buf + 8, res.size() * 8);
	ghash(len_buf, sizeof(len_buf));

	char tag[16];
	memcpy(J0, J0_begin, 16);
	gctr((const char*)S, tag, sizeof(S));
	btring _tag(tag, 16);
	this->_original_iv++;

	return std::make_pair(_tag, res);
}

_NAP_END