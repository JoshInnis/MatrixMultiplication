/*
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <https://unlicense.org>
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"

typedef struct Edge Edge;
typedef struct Vertex Vertex;

typedef struct Graph {
	Tag tag;
	List *vertices;
} Graph;

typedef struct Vertex {
	Tag tag;
	List *edges;
} Vertex;

typedef struct Edge {
	Tag tag;
	Vertex *vertex;
} Edge;

static inline Graph *makeGraph(List *vertices) {
	Graph *graph;

	graph = (Graph *) malloc(sizeof(*graph));
	graph->tag = T_Graph;
	graph->vertices = vertices;

	return graph;
}

static inline Vertex *makeVertex(List *edges) {
	Vertex *vertex;

	vertex = (Vertex *) malloc(sizeof(*vertex));
	vertex->tag = T_Vertex;
	vertex->edges = edges;

	return vertex;
}

Edge *makeEdge(Vertex *vertex) {
	Edge *edge;

	edge = (Edge *) malloc(sizeof(*edge));
	edge->tag = T_Edge;
	edge->vertex = vertex;

	return edge;
}

#endif
