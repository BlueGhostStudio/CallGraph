#ifndef CALLGRAPH_GLOBAL_H
#define CALLGRAPH_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CALLGRAPH_LIBRARY)
#  define CALLGRAPH_EXPORT Q_DECL_EXPORT
#else
#  define CALLGRAPH_EXPORT Q_DECL_IMPORT
#endif

#endif // CALLGRAPH_GLOBAL_H
