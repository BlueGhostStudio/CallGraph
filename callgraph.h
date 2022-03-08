#ifndef CALLGRAPH_H
#define CALLGRAPH_H

#include <QtCore>
#include <functional>

#include "CallGraph_global.h"

class CALLGRAPH_EXPORT CallGraph : public QObject {
    Q_OBJECT
public:
    CallGraph(QObject* parent = nullptr);
    virtual ~CallGraph() {}

    CallGraph* nodes() { return this; }
    template <typename... Args>
    CallGraph* nodes(
        const QString& name,
        std::function<void(QPointer<CallGraph>, const QVariant&)> fun,
        Args... rest) {
        m_nodes[name] = fun;
        return nodes(rest...);
    }

    void to(const QString& cgName, const QVariant& data = QVariant());
    void toFinal();

    static CallGraph* start(const QString& next, QObject* parent = nullptr);
    void exec(const QVariant& data = QVariant());

private:
    QMap<QString, std::function<void(CallGraph*, const QVariant&)>> m_nodes;
};

#endif  // CALLGRAPH_H
