/****************************************************************************
**
** Copyright (C) Qxt Foundation. Some rights reserved.
**
** This file is part of the QxtCore module of the Qt eXTension library
**
** This library is free software; you can redistribute it and/or modify it
** under the terms of th Common Public License, version 1.0, as published by
** IBM.
**
** This file is provided "AS IS", without WARRANTIES OR CONDITIONS OF ANY
** KIND, EITHER EXPRESS OR IMPLIED INCLUDING, WITHOUT LIMITATION, ANY
** WARRANTIES OR CONDITIONS OF TITLE, NON-INFRINGEMENT, MERCHANTABILITY OR
** FITNESS FOR A PARTICULAR PURPOSE. 
**
** You should have received a copy of the CPL along with this file.
** See the LICENSE file and the cpl1.0.txt file included with the source
** distribution for more information. If you did not receive a copy of the
** license, contact the Qxt Foundation.
** 
** <http://libqxt.sourceforge.net>  <libqxt@gmail.com>
**
****************************************************************************/
#include "qxttablewidget.h"
#include "qxtitemdelegate.h"
#include "qxttablewidget_p.h"

QxtTableWidgetPrivate::QxtTableWidgetPrivate()
{
}

void QxtTableWidgetPrivate::informStartEditing(const QModelIndex& index)
{
	QTableWidgetItem* item = qxt_p().itemFromIndex(index);
	Q_ASSERT(item);
	emit qxt_p().itemEditingStarted(item);
}

void QxtTableWidgetPrivate::informFinishEditing(const QModelIndex& index)
{
	QTableWidgetItem* item = qxt_p().itemFromIndex(index);
	Q_ASSERT(item);
	emit qxt_p().itemEditingFinished(item);
}

/*!
    \class QxtTableWidget QxtTableWidget
    \ingroup gui
    \brief An extended QTableWidget with additional signals.

    QxtTableWidget offers a few most commonly requested signals.

    \image html qxttablewidget.png "QxtTableWidget in Plastique style."
 */

/*!
    \fn QxtTableWidget::itemEditingStarted(QTableWidgetItem* item)

    This signal is emitted after the editing of \a item has been started.

    \sa itemEditingFinished()
 */

/*!
    \fn QxtTableWidget::itemEditingFinished(QTableWidgetItem* item)

    This signal is emitted after the editing of \a item has been finished.

    \sa itemEditingStarted()
 */

/*!
    \fn QxtTableWidget::itemCheckStateChanged(QxtTableWidgetItem* item)

    This signal is emitted whenever the check state of \a item has changed.

    \note Use QxtTableWidgetItem in order to enable this feature.

    \sa QxtTableWidgetItem, QTableWidgetItem::checkState()
 */

/*!
    Constructs a new QxtTableWidget with \a parent.
 */
QxtTableWidget::QxtTableWidget(QWidget* parent)
	: QTableWidget(parent)
{
	QXT_INIT_PRIVATE(QxtTableWidget);
	setItemPrototype(new QxtTableWidgetItem);
	QxtItemDelegate* delegate = new QxtItemDelegate(this);
	connect(delegate, SIGNAL(editingStarted(const QModelIndex&)),
		&qxt_d(), SLOT(informStartEditing(const QModelIndex&)));
	connect(delegate, SIGNAL(editingFinished(const QModelIndex&)),
		&qxt_d(), SLOT(informFinishEditing(const QModelIndex&)));
	setItemDelegate(delegate);
}

/*!
    Constructs a new QxtTableWidget with \a rows, \a columns and \a parent.
 */
QxtTableWidget::QxtTableWidget(int rows, int columns, QWidget* parent)
	: QTableWidget(rows, columns, parent)
{
	QXT_INIT_PRIVATE(QxtTableWidget);
	setItemPrototype(new QxtTableWidgetItem);
	QxtItemDelegate* delegate = new QxtItemDelegate(this);
	connect(delegate, SIGNAL(editingStarted(const QModelIndex&)),
		&qxt_d(), SLOT(informStartEditing(const QModelIndex&)));
	connect(delegate, SIGNAL(editingFinished(const QModelIndex&)),
		&qxt_d(), SLOT(informFinishEditing(const QModelIndex&)));
	setItemDelegate(delegate);
}

/*!
    Destructs the table widget.
 */
QxtTableWidget::~QxtTableWidget()
{
}