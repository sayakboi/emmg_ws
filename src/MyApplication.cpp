#include "MyApplication.h"

using namespace Magnum;
using namespace std;

PrimitivesExample::PrimitivesExample(const Arguments& arguments)
    : Platform::Application{arguments, Configuration{}
        .setTitle("Magnum Primitives Example")}
{
    GL::Renderer::enable(GL::Renderer::Feature::DepthTest);
    GL::Renderer::enable(GL::Renderer::Feature::FaceCulling);

     _mesh = MeshTools::compile(Primitives::cubeSolid());

    _transformation =
        Matrix4::rotationX(Rad(30.0))*Matrix4::rotationY(Rad(40.0));

    _projection =
        Matrix4::perspectiveProjection(
            Rad(35.0f), Vector2{windowSize()}.aspectRatio(), 0.01f, 1000.0f)*
        Matrix4::translation(Vector3::zAxis(-10.0f));
    _color = Color3::fromHsv({Rad(35.0f), 1.0f, 1.0f});
}

void PrimitivesExample::drawEvent() {
    GL::defaultFramebuffer.clear(
        GL::FramebufferClear::Color|GL::FramebufferClear::Depth);

    _shader.setLightPositions({{1.4f, 1.0f, 0.75f, 0.0f}})
        .setDiffuseColor(_color)
        .setAmbientColor(Color3::fromHsv({_color.hue(), 1.0f, 0.3f}))
        .setTransformationMatrix(_transformation)
        .setNormalMatrix(_transformation.normalMatrix())
        .setProjectionMatrix(_projection)
        .draw(_mesh);

    swapBuffers();
}

void PrimitivesExample::mousePressEvent(MouseEvent& event) {
    if(event.button() != MouseEvent::Button::Left) return;

    event.setAccepted();
}

void PrimitivesExample::mouseReleaseEvent(MouseEvent& event) {
    //Magnum::Math::Deg<Magnum::Float>
    float addHue = 50.0f; 
    _color = Color3::fromHsv({_color.hue() + static_cast<Magnum::Math::Deg<Magnum::Float>>(addHue), 1.0f, 1.0f});

    event.setAccepted();
    redraw();
}

void PrimitivesExample::mouseMoveEvent(MouseMoveEvent& event) {
    if(!(event.buttons() & MouseMoveEvent::Button::Left)) return;

    Vector2 delta = -3.0f*Vector2{event.relativePosition()}/Vector2{windowSize()};

    _transformation =
        Matrix4::rotationX(Rad{delta.y()})*
        _transformation*
        Matrix4::rotationY(Rad{delta.x()});

    event.setAccepted();
    redraw();
}
