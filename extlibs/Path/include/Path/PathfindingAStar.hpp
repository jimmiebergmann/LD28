// ///////////////////////////////////////////////////////////////////////////
// Copyright (C) 2013 Jimmie Bergmann - jimmiebergmann@gmail.com
//
// This software is provided 'as-is', without any express or
// implied warranty. In no event will the authors be held
// liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute
// it freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but
//    is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any
//    source distribution.
// ///////////////////////////////////////////////////////////////////////////

#ifndef PATH_PATHFINDING_ASTAR_HPP
#define PATH_PATHFINDING_ASTAR_HPP

#include <Path/Pathfinding.hpp>

namespace Path
{

	class PathfindingAStar : public Pathfinding
	{

	public:

		// Destructor
		virtual ~PathfindingAStar( ) { };

		// Public functions
		virtual bool Generate( const Point_ui & p_Start, const Point_ui & p_End ) = 0;

		// Get functions
		virtual Path & GetPath( ) = 0;
		virtual bool GetTile( const unsigned int p_Index ) const = 0;
		virtual bool GetTile( const Point_ui & p_TilePos) const = 0;

	};

}

#endif