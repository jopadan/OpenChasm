#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <math.hpp>

namespace fmt
{
	namespace car
	{
	};
	namespace gltf
	{
	};
	namespace m3o
	{
		static const sca::u32 texture_width = 64u;
		static const sca::f32 coords_scale  = 1.0f / 2048.0f;
		static const sca::u16 texture_height_mask = 1023u;


		struct face
		{
			enum mask : sca::u8
			{
				none         = 0 << 0,
				two_sided    = 1 << 0,
				alpha_tested = 1 << 1,
				translucent  = ((1 << 2) | (1 << 3)),
				last
			};
			vec::u16<4>    v;
			mat::u16<2, 4> t;

			sca::i16 next;
			sca::i16 distant;

			sca::u8  group_id_num;
			mask     flags;

			sca::u16 sprite_v_offset;

			//		face();

			//		void load(OC::BinaryInputStream& stream);
		};

		struct header
		{
			std::array<m3o::face  , 400> faces;
			std::array<vec::i16<3>, 256> overt;
			std::array<vec::i16<3>, 256> rvert;
			std::array<vec::i16<3>, 256> shvert;
			std::array<vec::i16<2>, 256> scvert;

			sca::u16 vert_count;
			sca::u16 face_count;

			sca::u16 texture_height;
			std::vector<sca::u8> ptr;

			//		header();

			//		void load(const OC::Path& filename);
			//		void load(OC::BinaryInputStream& stream);
		};
	};
};
