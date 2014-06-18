/****************************************************************************
**
** Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QT3D_TECHNIQUECRITERION_H
#define QT3D_TECHNIQUECRITERION_H

#include <Qt3DRenderer/qt3drenderer_global.h>
#include <QObject>
#include <QVariant>

QT_BEGIN_NAMESPACE

namespace Qt3D {

class TechniqueCriterionPrivate;

class QT3DRENDERERSHARED_EXPORT TechniqueCriterion : public QObject
{
    Q_OBJECT
    Q_ENUMS(CriterionType)
    Q_PROPERTY(Qt3D::TechniqueCriterion::CriterionType criterionType READ criterionType WRITE setCriterionType NOTIFY criterionTypeChanged)
    Q_PROPERTY(QVariant criterionValue READ criterionValue WRITE setCriterionValue NOTIFY criterionValueChanged)
    Q_PROPERTY(QString criterionCustomType READ criterionCustomType WRITE setCriterionCustomType NOTIFY criterionCustomTypeChanged)
public:
    explicit TechniqueCriterion(QObject *parent = 0);

    enum CriterionType
    {
        CustomType = 0,
        RenderingStyle,
        OpenGLVersion,
        Extension,
        Vendor
    };

    bool operator ==(const TechniqueCriterion &other);
    bool operator !=(const TechniqueCriterion &other);
    void setCriterionType(CriterionType type);
    void setCriterionValue(const QVariant &value);
    void setCriterionCustomType(const QString &customType);

    CriterionType criterionType() const;
    QVariant criterionValue() const;
    QString criterionCustomType() const;

Q_SIGNALS:
    void criterionTypeChanged();
    void criterionValueChanged();
    void criterionCustomTypeChanged();

private:
    Q_DECLARE_PRIVATE(TechniqueCriterion)
    TechniqueCriterionPrivate *d_ptr;

};

class TechniqueCriterionPrivate
{
public:
    TechniqueCriterionPrivate(TechniqueCriterion *qq)
        : q_ptr(qq)
        , m_criterionType(TechniqueCriterion::CustomType)
    {}

    Q_DECLARE_PUBLIC(TechniqueCriterion)
    TechniqueCriterion *q_ptr;
    TechniqueCriterion::CriterionType m_criterionType;
    QString m_criterionCustomType;
    QVariant m_criterionValue;
};


} // Qt3D

QT_END_NAMESPACE

Q_DECLARE_METATYPE(Qt3D::TechniqueCriterion *)

#endif // QT3D_TECHNIQUECRITERION_H
