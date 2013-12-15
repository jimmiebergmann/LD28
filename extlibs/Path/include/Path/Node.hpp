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

#ifndef PATH_NODE_HPP
#define PATH_NODE_HPP

#include <Path/Point.hpp>

namespace Path
{

	class Node
	{

	public:

		// Constructor
		Node(	Node * p_pTail,
				Node * p_pHead,
				Point_ui p_Position );

		// Set functions
		void SetTail( Node * p_pNode );
		void SetHead( Node * p_pNode );

		// Get functions
		Node * GetTail( ) const;
		Node * GetHead( ) const;
		Point_ui GetPosition( ) const;

	private:

		Node * m_pTail;
		Node * m_pHead;
		Point_ui m_Position;

	};

}

#endif