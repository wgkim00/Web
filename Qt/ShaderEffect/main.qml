import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.13

Window {
    visible: true
    width: 350
    height: 200
    title: qsTr("Hello https://makersweb.net")

    Rectangle {
        anchors.fill: parent
        Row {
            anchors.centerIn: parent
            Image {
                id: img
                source: "me.jpg"
                width: 153
                height: 69
            }

            ShaderEffect {
                width: img.width;
                height: img.height
                property variant src: img
                vertexShader: "
                    uniform highp mat4 qt_Matrix;
                    attribute highp vec4 qt_Vertex;
                    attribute highp vec2 qt_MultiTexCoord0;
                    varying highp vec2 coord;
                    void main() {
                        coord = qt_MultiTexCoord0;
                        gl_Position = qt_Matrix * qt_Vertex;
                    }"
                fragmentShader: "
                    varying highp vec2 coord;
                    uniform sampler2D src;
                    uniform lowp float qt_Opacity;
                    void main() {
                        lowp vec4 tex = texture2D(src, coord);
                        gl_FragColor = vec4(vec3(dot(tex.rgb,
                                            vec3(0.344, 0.5, 0.156))),
                                                 tex.a) * qt_Opacity;
                    }"
            }
        }
    }
}
