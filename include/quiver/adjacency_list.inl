/*
 *	Quiver - A graph theory library
 *	Copyright (C) 2018 Josua Rieder (josua.rieder@protonmail.com)
 *	Distributed under the MIT License.
 *	See the enclosed file LICENSE.txt for further information.
 */

#ifndef QUIVER_ADJACENCY_LIST_INL_INCLUDED
#define QUIVER_ADJACENCY_LIST_INL_INCLUDED

#include <quiver/adjacency_list.hpp>
#include <quiver/util.hpp>
#include <quiver/properties.hpp>
#include <quiver/container_traits.hpp>
#include <utility>
#include <cassert>

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
template<quiver::directivity_t rhs_dir, typename rhs_edge_properties_t, typename rhs_vertex_properties_t, template<typename> class rhs_out_edge_container, template<typename> class rhs_vertex_container>
quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::adjacency_list(adjacency_list<rhs_dir, rhs_edge_properties_t, rhs_vertex_properties_t, rhs_out_edge_container, rhs_vertex_container> const& rhs)
: base_t(rhs)
{
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
template<quiver::directivity_t rhs_dir, typename rhs_edge_properties_t, typename rhs_vertex_properties_t, template<typename> class rhs_out_edge_container, template<typename> class rhs_vertex_container>
quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::adjacency_list(adjacency_list<rhs_dir, rhs_edge_properties_t, rhs_vertex_properties_t, rhs_out_edge_container, rhs_vertex_container>&& rhs) noexcept
: base_t(std::move(rhs))
{
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr void quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::normalize(vertex_index_t& from, vertex_index_t& to) noexcept
{
	if(from > to)
		std::swap(from, to);
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr std::size_t quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_size() const noexcept
{
	return m_vertices.size();
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr bool quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_empty() const noexcept
{
	return V.size() == 0;
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr std::size_t quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_capacity() const noexcept
{
	return m_vertices.capacity();
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
void quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_reserve(std::size_t vertices)
{
	m_vertices.reserve(vertices);
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_begin() noexcept
{
	return m_vertices.begin();
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_begin() const noexcept
{
	return m_vertices.begin();
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_cbegin() const noexcept
{
	return m_vertices.cbegin();
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_end() noexcept
{
	return m_vertices.end();
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_end() const noexcept
{
	return m_vertices.end();
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_cend() const noexcept
{
	return m_vertices.cend();
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_get(vertex_index_t index) const noexcept -> vertex_t const&
{
	assert(index < V.size());
	return m_vertices[index];
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_get(vertex_index_t index) noexcept -> vertex_t&
{
	return const_cast<vertex_t&>(static_cast<adjacency_list const&>(*this).vertex_get(index));
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
template<typename... args_t>
quiver::vertex_index_t quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_emplace(args_t&&... args)
{
	m_vertices.emplace_back(std::forward<args_t>(args)...);
	// assert(directivity == directed || m_vertices.back().out_edges.empty()); // we mustn't have this check for split_ccs
	m_e += m_vertices.back().out_edges.size();
	return m_v++;
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
bool quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_erase(vertex_index_t index)
{
	assert(index < V.size());

	if(vertex_erase_simple(index))
	{
		for(auto& vertex : m_vertices)
		{
			for(std::size_t i = vertex.out_edges.size(); i-- > 0;)
			{
				if(vertex.out_edges[i].to == index)
				{
					vertex.out_edges.erase(vertex.out_edges.begin() + i);
					++i;
					--m_e;
				}
				else if(vertex.out_edges[i].to > index)
				{
					--vertex.out_edges[i].to;
				}
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
bool quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::vertex_erase_simple(vertex_index_t index)
{
	assert(index < V.size());

	const std::size_t out_degree = m_vertices[index].out_degree();
	m_vertices.erase(m_vertices.begin() + index);
	m_e -= out_degree;
	--m_v;
	return true;
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr std::size_t quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::edge_size() const noexcept
{
	if constexpr(directivity == directed)
		return m_e;
	else if constexpr(directivity == undirected)
		return m_e / 2;
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr bool quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::edge_empty() const noexcept
{
	return E.size() == 0;
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr std::size_t quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::edge_max_size() const noexcept
{
	if constexpr(directivity == directed)
		return V.size() * (V.size() - 1);
	else if constexpr(directivity == undirected)
		return V.size() * (V.size() - 1) / 2;
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::edge_get(vertex_index_t from, vertex_index_t to) const noexcept -> out_edge_t const*
{
	assert(from < V.size());
	assert(to < V.size());

	if constexpr(directivity == undirected)
		normalize(from, to); // so that edge_get(1,0) == edge_get(0,1)
	return edge_get_simple(from, to);
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::edge_get_simple(vertex_index_t from, vertex_index_t to) const noexcept -> out_edge_t const*
{
	assert(from < V.size());
	assert(to < V.size());

	// if(from == to) return nullptr;
	auto& edges = m_vertices[from].out_edges;
	for(auto iter = edges.begin(); iter != edges.end(); ++iter)
		if(iter->to == to)
			return &*iter;
	return nullptr;
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
template<typename... args_t>
bool quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::edge_emplace(vertex_index_t from, vertex_index_t to, args_t&&... args)
{
	assert(from < V.size());
	assert(to < V.size());
	assert(from != to); // no loops

	if constexpr(directivity == directed) {
		return edge_emplace_simple(from, to, std::forward<args_t>(args)...);
	} else if constexpr(directivity == undirected) {
		// TODO: strong exception safety
		[[maybe_unused]] const bool existed1 = edge_emplace_simple(to, from, std::as_const(args)...);
		[[maybe_unused]] const bool existed2 = edge_emplace_simple(from, to, std::forward<args_t>(args)...);
		assert(existed1 == existed2);
		return existed1;
	}
	return true;
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
template<typename... args_t>
bool quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::edge_emplace_simple_nonexistent(vertex_index_t from, vertex_index_t to, args_t&&... args)
{
	assert(from < V.size());
	assert(to < V.size());
	assert(edge_get_simple(from, to) == nullptr);
	assert(from != to); // no loops

	m_vertices[from].out_edges.emplace_back(to, std::forward<args_t>(args)...);
	++m_e;
	return true;
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
template<typename... args_t>
bool quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::edge_emplace_simple(vertex_index_t from, vertex_index_t to, args_t&&... args)
{
	assert(from < V.size());
	assert(to < V.size());
	assert(from != to); // no loops

	if(edge_get_simple(from, to) == nullptr)
		return edge_emplace_simple_nonexistent(from, to, std::forward<args_t>(args)...);
	else
		return false;
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
bool quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::edge_erase(vertex_index_t from, vertex_index_t to)
{
	assert(from < V.size());
	assert(to < V.size());

	// if(from == to) return false;
	if constexpr(directivity == directed) {
		return edge_erase_simple(from, to);
	} else if constexpr(directivity == undirected) {
		if(from == to)
			return edge_erase_simple(from, to);

		assert((edge_get_simple(from, to) == nullptr) == (edge_get_simple(to, from) == nullptr));
		const bool removed = edge_erase_simple(from, to);
		if(removed)
			edge_erase_simple(to, from); // TODO: strong exception safety
		return removed;
	}
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
bool quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::edge_erase_simple(vertex_index_t from, vertex_index_t to)
{
	assert(from < V.size());
	assert(to < V.size());

	// if(from == to) return false;
	auto& edges = m_vertices[from].out_edges;
	for(auto iter = edges.begin(); iter != edges.end(); ++iter)
	{
		if(iter->to == to)
		{
			edges.erase(iter);
			--m_e;
			return true;
		}
	}
	return false;
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::adjacency_list(std::size_t vertices)
: base_t(vertices)
{
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
std::size_t quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::in_degree(vertex_index_t index) const noexcept
{
	if constexpr(directivity == directed) {
		std::size_t count = 0;
		for(auto const& vertex : m_vertices)
			count += vertex.has_edge_to(index);
		return count;
	} else if constexpr(directivity == undirected) {
		return out_degree(index);
	}
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
std::size_t quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::out_degree(vertex_index_t index) const noexcept
{
	return V[index].out_degree();
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
std::size_t quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::degree(vertex_index_t index) const noexcept
{
	static_assert(directivity == undirected, "degree only defined for undirected graphs");
	return out_degree(index);
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::strip_edges() const& -> adjacency_list
{
	adjacency_list result;
	result.V.reserve(V.size());
	for(auto const& vertex : m_vertices)
		result.V.emplace(vertex.properties());
	return result;
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::strip_edges() && -> adjacency_list&&
{
	for(auto& vertex : m_vertices) {
		std::size_t diff_e = vertex.out_edges.size();
		vertex.out_edges.clear();
		m_e -= diff_e;
	}
	assert(m_e == 0);
	return std::move(*this);
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::to_directed() const& -> adjacency_list<directed, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>
{
	using result_t = adjacency_list<directed, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>;
	return result_t(*this);
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::to_directed() && -> adjacency_list<directed, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>
{
	using result_t = adjacency_list<directed, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>;
	return result_t(std::move(*this));
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::to_undirected() const& -> adjacency_list<undirected, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>
{
	using result_t = adjacency_list<undirected, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>;
	if constexpr(directivity == directed)
	{
		// TODO: enforce that there are no back and forths in the original directed graph. this can be caught by checking emplace's return value
		result_t result;
		result.V.reserve(V.size());
		for(auto const& vertex : m_vertices)
			result.V.emplace(vertex.properties());
		for(vertex_index_t v = 0; v < V.size(); ++v)
			for(auto const& out_edge : V[v].out_edges)
				result.E.emplace(v, out_edge.to, out_edge.properties());
		return result;
	}
	else
	{
		return *this;
	}
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
auto quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::to_undirected() && -> adjacency_list<undirected, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>
{
	using result_t = adjacency_list<undirected, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>;
	if constexpr(directivity == directed)
	{
		// TODO: enforce that there are no back and forths in the original directed graph
		result_t result(std::move(*this));
		for(vertex_index_t v = 0; v < result.V.size(); ++v)
			for(auto const& out_edge : result.V[v].out_edges)
				result.edge_emplace_simple(out_edge.to, v, out_edge.properties());
		return result;
	}
	else
	{
		return std::move(*this);
	}
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
template<typename invokable_t>
void quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::transform_outs(invokable_t invokable)
{
	for(auto& vertex : m_vertices)
		for(auto& out_edge : vertex.out_edges)
			out_edge.to = invokable(out_edge.to);
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
void quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::sort_edges()
{
	if constexpr(container_traits<out_edge_list_t>::is_ordered)
		for(auto& vertex : m_vertices)
			vertex.sort_edges();
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
bool quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::contract(vertex_index_t u, vertex_index_t v)
{
	// TODO: this function currently doesn't provide strong exception safety

	assert(u < V.size());
	assert(v < V.size());
	assert(u != v);

	// wlog u < v
	if(u > v)
		std::swap(u, v);

	bool has_uv_or_vu = false;
	const auto rename = [v](vertex_index_t i) noexcept -> vertex_index_t { return i - (i > v); };

	// this block can be implemented more efficiently for different out_edge_container data structures
	{
		std::vector<bool> u_connectivity(V.size(), false);
		{
			// find neighborhood of u
			auto& out_edges = V[u].out_edges;
			for(auto iter = out_edges.begin(); iter != out_edges.end(); ++iter) {
				if(iter->to == v) {
					has_uv_or_vu = true;
					typename out_edge_list_t::iterator uv = iter;

					// do the rest of out_edges here because we can spare us the if above
					for(++iter; iter != out_edges.end(); ++iter)
						u_connectivity[iter->to] = true;

					// remove u -> v edge
					out_edges.erase(uv);
					--m_e;
					break;
				}
				u_connectivity[iter->to] = true;
			}
		}
		// add v's neighborhood to u's neighborhood
		for(auto& out_edge : V[v].out_edges) {
			const bool is_vu = (out_edge.to == u);
			has_uv_or_vu |= is_vu;
			if(!is_vu && !u_connectivity[out_edge.to])
				edge_emplace_simple_nonexistent(u, out_edge.to, std::move(out_edge.properties()));
		}
	}
	vertex_erase_simple(v);

	// relabel all i -> j edges and remove duplicates if j = u,v
	for(vertex_index_t i = 0; i < V.size(); ++i) {
		if(i == u)
			continue;
		auto& out_edges = V[i].out_edges;
		auto iter = out_edges.begin();
		// find the first instance of an i -> u or i -> v edge
		for(; iter != out_edges.end(); ++iter) {
			if(iter->to == u || iter->to == v) {
				iter->to = u;
				++iter;
				break;
			}
			iter->to = rename(iter->to);
		}
		// find the second instance of an i -> u or i -> v edge
		for(; iter != out_edges.end(); ++iter) {
			if(iter->to == u || iter->to == v) {
				iter = std::prev(out_edges.erase(iter));
				--m_e;
				continue; // we need to rename the rest
			}
			iter->to = rename(iter->to);
		}
	}
	// relabel all u -> j edges
	for(auto& out_edge : V[u].out_edges)
		out_edge.to = rename(out_edge.to);

	return has_uv_or_vu;
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
quiver::vertex_index_t quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::cleave(vertex_index_t v)
{
	assert(v < V.size());

	// TODO: currently doesn't provide strong exception safety
	vertex_index_t new_v = V.emplace(V[v]);
	for(vertex_index_t i = 0; i < V.size(); ++i)
		if(i != v && i != new_v)
			for(auto& out_edge : V[i].out_edges)
				if(out_edge.to == v) {
					edge_emplace_simple_nonexistent(i, new_v, out_edge.properties());
					break;
				}
	return new_v;
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
void quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::swap(adjacency_list& rhs) noexcept
{
	using std::swap;
	swap(m_vertices, rhs.m_vertices);
	swap(m_v, rhs.m_v);
	swap(m_e, rhs.m_e);
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr bool quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::is_weighted() noexcept
{
	return is_weighted_v<adjacency_list>;
}
template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
constexpr bool quiver::adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container>::is_simple() noexcept
{
	return !is_weighted() && directivity == undirected;
}

template<quiver::directivity_t dir, typename edge_properties_t, typename vertex_properties_t, template<typename> class out_edge_container, template<typename> class vertex_container>
void quiver::swap(adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container> const& lhs, adjacency_list<dir, edge_properties_t, vertex_properties_t, out_edge_container, vertex_container> const& rhs) noexcept
{
	lhs.swap(rhs);
}

#endif // !QUIVER_ADJACENCY_LIST_INL_INCLUDED
