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

#ifndef PATH_POINT_HPP
#define PATH_POINT_HPP

namespace Path
{

	template< typename T>
	class Point
	{

	public:

		Point( ) :
			x( (T)0),
			y( (T)0),
			z( (T)0)
		{
		}

		Point( const T p_X, const T p_Y ) :
			x( p_X ),
			y( p_Y ),
			z( 0 )
		{
		}

		Point( const T p_X, const T p_Y, const T p_Z ) :
			x( p_X ),
			y( p_Y ),
			z( p_Z )
		{
		}

		Point( const Point< int > & p_Vector )
		{
			x = static_cast< T >( p_Vector.x );
			y = static_cast< T >( p_Vector.y );
			z = static_cast< T >( p_Vector.z );
		}

		Point( const Point< unsigned int > & p_Vector )
		{
			x = static_cast< T >( p_Vector.x );
			y = static_cast< T >( p_Vector.y );
			z = static_cast< T >( p_Vector.z );
		}

		Point( const Point< float > & p_Vector )
		{
			x = static_cast< T >( p_Vector.x );
			y = static_cast< T >( p_Vector.y );
			z = static_cast< T >( p_Vector.z );
		}


		bool operator == ( const Point<T> p_Point ) const
		{
			return x == p_Point.x && y == p_Point.y && z == p_Point.z;
		}

		T x;
		T y;
		T z;
	};

	typedef Point<float> Point_f;
	typedef Point<int> Point_i;
	typedef Point<unsigned int> Point_ui;

}

#endif