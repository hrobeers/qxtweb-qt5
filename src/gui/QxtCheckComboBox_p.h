/*******************************************************************
Qt extended Library 
Copyright (C) 2007 J-P Nurmi <jpnurmi@gmail.com>
released under the Terms of LGPL (see the LICENSE file)
*******************************************************************/

#ifndef QXTCHECKCOMBOBOX_P_H
#define QXTCHECKCOMBOBOX_P_H

#include <QListView>
#include <QStandardItemModel>
#include <QxtPimpl.h>
#include "QxtCheckComboBox.h"

class QxtCheckComboView : public QListView
{
	Q_OBJECT
	
public:
	explicit QxtCheckComboView(QWidget* parent = 0);
	~QxtCheckComboView();
	
	virtual bool eventFilter(QObject* object, QEvent* event);
	QxtCheckComboBox::CheckMode mode;
	bool handleIndicatorRelease(QMouseEvent* event, const QModelIndex& index);
	bool handleItemRelease(QMouseEvent* event, const QModelIndex& index);
	
signals:
	void hideRequested();
};

class QxtCheckComboModel : public QStandardItemModel
{
	Q_OBJECT
	
public:
	explicit QxtCheckComboModel(QObject* parent = 0);
	~QxtCheckComboModel();
	
	virtual Qt::ItemFlags flags(const QModelIndex& index) const;
	virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
	virtual bool setItemData(const QModelIndex& index, const QMap<int, QVariant>& roles);
	
signals:
	void checkStateChanged();
};

class QxtCheckComboBoxPrivate : public QObject, public QxtPrivate<QxtCheckComboBox>
{
	Q_OBJECT
	
public:
	QXT_DECLARE_PUBLIC(QxtCheckComboBox);
	QxtCheckComboBoxPrivate();
	QString separator;
	QString defaultText;
	QStringList checkedItems;
	QxtCheckComboView* view;
	
public slots:
	void hidePopup();
	void updateCheckedItems();
};

#endif // QXTCHECKCOMBOBOX_P_H