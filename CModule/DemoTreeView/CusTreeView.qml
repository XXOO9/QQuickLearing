import QtQuick 2.12
import QtQuick.Controls 1.4

Item {
    id: root

    ListModel{
        id: m_list
        ListElement{ val:"val11"; val2: "val12" }
        ListElement{ val:"val21"; val2: "val22" }
        ListElement{ val:"val31"; val2: "val32" }
    }

    TreeView{
        id: m_tree
        width: 300
        height: 200

        model: m_list
        TableViewColumn{
            title: "first"
            role: "val1"

        }
    }
}
