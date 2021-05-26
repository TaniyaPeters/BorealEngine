#pragma once

namespace Boreal {
	/**
	* @brief Structure that describes the components of a vertex
	*
	*/
	typedef struct Vertex {
		float x; ///< The X coordinate of the vertex as a float
		float y; ///< The Y coordinate of the vertex as a float
		float z; ///< The Z coordinate of the vertex as a float

		float u; ///< The U coordinate for UV textures as a float
		float v; ///< The V coordinate for UV textures as a float

		float r; ///< The red value of the vertex colour as a float (0.0 - 1.0)
		float g; ///< The green value of the vertex colour as a float (0.0 - 1.0)
		float b; ///< The blue value of the vertex colour as a float (0.0 - 1.0)
		float a; ///< The alpha value of the vertex colour as a float (0.0 - 1.0)
	} Vertex;
}