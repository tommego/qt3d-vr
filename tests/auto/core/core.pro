TEMPLATE = subdirs

SUBDIRS = \
    handle \
    handlemanager \
    arrayresourcesmanager \
    listresourcesmanager \
    qcircularbuffer \
    qboundedcircularbuffer \
    nodes \
    qchangearbiter \
    qscene

contains(QT_CONFIG, private_tests) {
    SUBDIRS += qframeallocator
}
