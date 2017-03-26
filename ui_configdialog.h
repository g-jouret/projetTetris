/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbName;
    QSpacerItem *horizontalSpacer;
    QLineEdit *leName;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbHeight;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *sbHeight;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbWidth;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *sbWidth;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbLevel;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *sbLevel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QStringLiteral("ConfigDialog"));
        ConfigDialog->resize(222, 252);
        widget = new QWidget(ConfigDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(21, 21, 185, 211));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbName = new QLabel(widget);
        lbName->setObjectName(QStringLiteral("lbName"));

        horizontalLayout->addWidget(lbName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        leName = new QLineEdit(widget);
        leName->setObjectName(QStringLiteral("leName"));

        horizontalLayout->addWidget(leName);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbHeight = new QLabel(widget);
        lbHeight->setObjectName(QStringLiteral("lbHeight"));

        horizontalLayout_2->addWidget(lbHeight);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        sbHeight = new QSpinBox(widget);
        sbHeight->setObjectName(QStringLiteral("sbHeight"));

        horizontalLayout_2->addWidget(sbHeight);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbWidth = new QLabel(widget);
        lbWidth->setObjectName(QStringLiteral("lbWidth"));

        horizontalLayout_3->addWidget(lbWidth);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        sbWidth = new QSpinBox(widget);
        sbWidth->setObjectName(QStringLiteral("sbWidth"));

        horizontalLayout_3->addWidget(sbWidth);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lbLevel = new QLabel(widget);
        lbLevel->setObjectName(QStringLiteral("lbLevel"));

        horizontalLayout_4->addWidget(lbLevel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        sbLevel = new QSpinBox(widget);
        sbLevel->setObjectName(QStringLiteral("sbLevel"));

        horizontalLayout_4->addWidget(sbLevel);


        verticalLayout->addLayout(horizontalLayout_4);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ConfigDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "Configuration de la partie", Q_NULLPTR));
        lbName->setText(QApplication::translate("ConfigDialog", "Nom", Q_NULLPTR));
        lbHeight->setText(QApplication::translate("ConfigDialog", "Hauteur", Q_NULLPTR));
        lbWidth->setText(QApplication::translate("ConfigDialog", "Largeur", Q_NULLPTR));
        lbLevel->setText(QApplication::translate("ConfigDialog", "Niveau de difficult\303\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
