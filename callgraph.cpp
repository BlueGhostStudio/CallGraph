#include "callgraph.h"

CallGraph::CallGraph(QObject* parent) : QObject(parent) {}

void
CallGraph::to(const QString& cgName, const QVariant& data) {
    if (m_nodes.contains(cgName)) m_nodes[cgName](this, data);
}

void
CallGraph::toFinal() {
    delete this;
}

CallGraph*
CallGraph::start(const QString& next, QObject* parent) {
    CallGraph* __callGraph__ = new CallGraph(parent);

    __callGraph__->nodes("__START__",
                         [&](QPointer<CallGraph> cg, const QVariant& data) {
                             cg->to(next, data);
                         });

    return __callGraph__;
}

void
CallGraph::exec(const QVariant& data) {
    to("__START__", data);
}
