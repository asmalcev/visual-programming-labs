import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.0

Window {
    property var _margin: 12



    visible: true

    title: qsTr("Calculator")

    width: 412
    height: 468
    minimumWidth: 320
    maximumHeight: 468
    minimumHeight: 468

    color: "#E0E0E0"


    Rectangle {
        id: output

        width: parent.width - _margin * 2
        height: 64

        x: _margin
        y: _margin

        Text {
            id: output_text
            text: ""

            anchors.right: parent.right
            anchors.rightMargin: _margin
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Button {
        id: btn7
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: output.bottom
        anchors.topMargin: _margin
        x: _margin

        Text {
            text: "7"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '7' }
    }

    Button {
        id: btn8
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: output.bottom
        anchors.topMargin: _margin
        anchors.left: btn7.right
        anchors.leftMargin: _margin

        Text {
            text: "8"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '8' }
    }

    Button {
        id: btn9
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: output.bottom
        anchors.topMargin: _margin
        anchors.left: btn8.right
        anchors.leftMargin: _margin

        Text {
            text: "9"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '9' }
    }

    Button {
        id: btn_divide
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: output.bottom
        anchors.topMargin: _margin
        anchors.left: btn9.right
        anchors.leftMargin: _margin

        Text {
            text: "/"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '/' }
    }

    Button {
        id: btn4
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn7.bottom
        anchors.topMargin: _margin
        x: _margin

        Text {
            text: "4"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '4' }
    }

    Button {
        id: btn5
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn7.bottom
        anchors.topMargin: _margin
        anchors.left: btn4.right
        anchors.leftMargin: _margin

        Text {
            text: "5"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '5' }
    }

    Button {
        id: btn6
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn7.bottom
        anchors.topMargin: _margin
        anchors.left: btn5.right
        anchors.leftMargin: _margin

        Text {
            text: "6"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '6' }
    }

    Button {
        id: btn_multiply
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn7.bottom
        anchors.topMargin: _margin
        anchors.left: btn6.right
        anchors.leftMargin: _margin

        Text {
            text: "*"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '*' }
    }

    Button {
        id: btn1
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn4.bottom
        anchors.topMargin: _margin
        x: _margin

        Text {
            text: "1"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '1' }
    }

    Button {
        id: btn2
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn4.bottom
        anchors.topMargin: _margin
        anchors.left: btn1.right
        anchors.leftMargin: _margin

        Text {
            text: "2"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '2' }
    }

    Button {
        id: btn3
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn4.bottom
        anchors.topMargin: _margin
        anchors.left: btn2.right
        anchors.leftMargin: _margin

        Text {
            text: "3"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '3' }
    }

    Button {
        id: btn_minus
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn4.bottom
        anchors.topMargin: _margin
        anchors.left: btn3.right
        anchors.leftMargin: _margin

        Text {
            text: "-"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '-' }
    }

    Button {
        id: btn0
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn1.bottom
        anchors.topMargin: _margin
        x: _margin

        Text {
            text: "0"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '0' }
    }

    Button {
        id: btn_comma
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn1.bottom
        anchors.topMargin: _margin
        anchors.left: btn0.right
        anchors.leftMargin: _margin

        Text {
            text: "."
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '.' }
    }

    Button {
        id: btn_backspace
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn1.bottom
        anchors.topMargin: _margin
        anchors.left: btn_comma.right
        anchors.leftMargin: _margin

        Text {
            text: "Del"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text = output_text.text.slice(0, output_text.text.length - 1) }
    }

    Button {
        id: btn_plus
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn1.bottom
        anchors.topMargin: _margin
        anchors.left: btn_backspace.right
        anchors.leftMargin: _margin

        Text {
            text: "+"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '+' }
    }

    Button {
        id: btn_ac
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn0.bottom
        anchors.topMargin: _margin
        x: _margin

        Text {
            text: "AC"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text = '' }
    }

    Button {
        id: btn_bracket_open
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn0.bottom
        anchors.topMargin: _margin
        anchors.left: btn_ac.right
        anchors.leftMargin: _margin

        Text {
            text: "("
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += '(' }
    }

    Button {
        id: btn_bracket_close
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn0.bottom
        anchors.topMargin: _margin
        anchors.left: btn_bracket_open.right
        anchors.leftMargin: _margin

        Text {
            text: ")"
            anchors.centerIn: parent
        }

        onClicked: { output_text.text += ')' }
    }

    Button {
        id: btn_equals
        width: (parent.width - _margin * 5) / 4
        height: 64

        anchors.top: btn0.bottom
        anchors.topMargin: _margin
        anchors.left: btn_bracket_close.right
        anchors.leftMargin: _margin

        Text {
            text: "="
            anchors.centerIn: parent
        }

        onClicked: { output_text.text = eval(output_text.text) }
    }
}
