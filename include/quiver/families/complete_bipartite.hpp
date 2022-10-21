/*
 *	Quiver - A graph theory library
 *	Copyright (C) 2018 Josua Rieder (josua.rieder@protonmail.com)
 *	Distributed under the MIT License.
 *	See the enclosed file LICENSE.txt for further information.
 */

#ifndef QUIVER_FAMILIES_COMPLETE_BIPARTITE_HPP_INCLUDED
#define QUIVER_FAMILIES_COMPLETE_BIPARTITE_HPP_INCLUDED

#include <quiver/adjacency_list.hpp>
#include <cstddef>

namespace quiver
{
	template<
		typename edge_properties_t = void,
		typename vertex_properties_t = void,
		template<typename> class out_edge_container = vector,
		template<typename> class vertex_container = vector
	>
	adjacency_list<undirected, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>
	complete_bipartite(std::size_t m, std::size_t n)
	{
		adjacency_list<undirected, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container> result(m + n);
		{
			std::size_t i = 0;
			while(i < n)
				result.V[i++].out_edges.reserve(m);
			while(i < m + n)
				result.V[i++].out_edges.reserve(n);
		}
		for(std::size_t i = 0; i < n; ++i)
			for(std::size_t j = 0; j < m; ++j)
				result.E.emplace(i, j + n);
		return result;
	}
	inline auto complete_bipartite(std::size_t m, std::size_t n)
	{
		return complete_bipartite<>(m, n);
	}

	template<
		typename edge_properties_t = void,
		typename vertex_properties_t = void,
		template<typename> class out_edge_container = vector,
		template<typename> class vertex_container = vector
	>
	adjacency_list<undirected, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>
	star(std::size_t n)
	{
		return complete_bipartite<edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>(n, 1);
	}
	inline auto star(std::size_t n)
	{
		return star<>(n);
	}

	template<
		typename edge_properties_t = void,
		typename vertex_properties_t = void,
		template<typename> class out_edge_container = vector,
		template<typename> class vertex_container = vector
	>
	adjacency_list<undirected, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>
	claw()
	{
		return star<edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>(3);
	}
	inline auto claw()
	{
		return claw<>();
	}
}

#endif // !QUIVER_FAMILIES_COMPLETE_BIPARTITE_HPP_INCLUDED
