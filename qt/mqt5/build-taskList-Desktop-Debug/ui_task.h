/********************************************************************************
** Form generated from reading UI file 'task.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkbox;
    QSpacerItem *horizontalSpacer;
    QPushButton *editButton;
    QPushButton *removeButton;

    void setupUi(QWidget *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName(QStringLiteral("Task"));
        Task->resize(653, 563);
        horizontalLayout = new QHBoxLayout(Task);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkbox = new QCheckBox(Task);
        checkbox->setObjectName(QStringLiteral("checkbox"));

        horizontalLayout->addWidget(checkbox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        editButton = new QPushButton(Task);
        editButton->setObjectName(QStringLiteral("editButton"));

        horizontalLayout->addWidget(editButton);

        removeButton = new QPushButton(Task);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        horizontalLayout->addWidget(removeButton);


        retranslateUi(Task);

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QWidget *Task)
    {
        Task->setWindowTitle(QApplication::translate("Task", "Form", Q_NULLPTR));
        checkbox->setText(QApplication::translate("Task", "Buy Milk", Q_NULLPTR));
        editButton->setText(QApplication::translate("Task", "Edit", Q_NULLPTR));
        removeButton->setText(QApplication::translate("Task", "Remove", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
