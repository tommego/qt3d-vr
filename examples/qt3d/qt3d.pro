TEMPLATE = subdirs

SUBDIRS += \
    simple-qml \
    simple-cpp \
    multiviewport \
    wireframe \
    shadow-map-qml \
    materials \
    wave \
    materials-cpp \
    scene3d \
    scene3d-rendercontrol \
    scene3d-vr \
    vr-window \
    #virtual-reality \
    controls \
    anaglyph-rendering \
    planets-qml \
    instanced-arrays-qml \
    lights \
    compute-particles \
    3d-text \
    qardboard \
    advancedcustommaterial \
    simplecustommaterial

qtHaveModule(multimedia): SUBDIRS += audio-visualizer-qml

# qmake seems to break in some CI configurations, disable this for now
#SUBDIRS += qgltf

# TODO Port the old examples to new APIs
#SUBDIRS += qt3d

qtHaveModule(widgets): SUBDIRS += basicshapes-cpp

EXAMPLE_FILES += \
    exampleresources

