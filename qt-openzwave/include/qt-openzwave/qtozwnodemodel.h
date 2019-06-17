#ifndef QTOZWNODEMODEL_H
#define QTOZWNODEMODEL_H

#include <QObject>
#include <QAbstractItemModel>

class QTOZW_Nodes : public QAbstractTableModel {
    Q_OBJECT
public:
    enum NodeColumns {
        NodeID,
        NodeName,
        NodeLocation,
        NodeManufacturerName,
        NodeProductName,
        NodeBasicString,
        NodeBasic,
        NodeGenericString,
        NodeGeneric,
        NodeSpecificString,
        NodeSpecific,
        NodeDeviceTypeString,
        NodeDeviceType,
        NodeRole,
        NodeRoleString,
        NodePlusType,
        NodePlusTypeString,
        NodeQueryStage,
        NodeManufacturerID,
        NodeProductType,
        NodeProductID,
        NodeBaudRate,
        NodeVersion,
        NodeGroups,
        NodeFlags,
        NodeCount
    };
    Q_ENUM(NodeColumns)

    enum nodeFlags {
        isListening,
        isFlirs,
        isBeaming,
        isRouting,
        isSecurityv1,
        isZWavePlus,
        isNIFRecieved,
        isAwake,
        isFailed,
        flagCount
    };

    Q_ENUM(nodeFlags)

    QTOZW_Nodes(QObject *parent=nullptr);
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole) override;

protected:
    QVariant getNodeData(quint8, NodeColumns);
    int32_t getNodeRow(quint8 _node);

    QMap<int32_t, QMap<NodeColumns, QVariant> > m_nodeData;
};
#endif // QTOZWNODEMODEL_H