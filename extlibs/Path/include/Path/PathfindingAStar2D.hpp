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

#ifndef PATH_PATHFINDING_ASTAR_2D_HPP
#define PATH_PATHFINDING_ASTAR_2D_HPP

#include <Path/PathfindingAStar.hpp>
#include <Path/Path.hpp>
#include <map>

namespace Path
{

	class PathfindingAStar2D : public PathfindingAStar
	{

	public:

		// Constructor/Destructor
		PathfindingAStar2D( bool * p_ppCollisionData, Point_ui p_Size );
		~PathfindingAStar2D( );

		// Public functions
		virtual bool Generate( const Point_ui & p_Start, const Point_ui & p_End );

		// Get functions
		virtual Path & GetPath( );
		virtual bool GetTile( const unsigned int p_Index ) const;
		virtual bool GetTile( const Point_ui & p_TilePos) const;

	private:

		// Internal help functions
		struct InternalNode
		{
			InternalNode(	const unsigned int p_Index,
							const unsigned int p_Distance,
							Node * p_pNode ) :
				index( p_Index ),
				distance( p_Distance ),
				pNode( p_pNode )
			{ };

			unsigned int index;
			unsigned int distance;
			Node * pNode;
		};

		typedef std::multimap<unsigned int, InternalNode*> InternalNodeMap;
		typedef std::pair<unsigned int, InternalNode*> InternalNodePair;

		// Internal help function
		void UpdateSuroundingNodes( InternalNode * p_pNode, unsigned int p_Index, const Point_ui & p_End );

		Path m_Path;
		bool *** m_pppCollisionData;
		Node *** m_pppClosedList;
		Point_ui m_Size;
		InternalNodeMap m_OpenList;

	};

}

#endif