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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
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
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QStringLiteral("ConfigDialog"));
        ConfigDialog->resize(247, 200);
        layoutWidget = new QWidget(ConfigDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 213, 163));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbName = new QLabel(layoutWidget);
        lbName->setObjectName(QStringLiteral("lbName"));

        horizontalLayout->addWidget(lbName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        leName = new QLineEdit(layoutWidget);
        leName->setObjectName(QStringLiteral("leName"));

        horizontalLayout->addWidget(leName);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbHeight = new QLabel(layoutWidget);
        lbHeight->setObjectName(QStringLiteral("lbHeight"));

        horizontalLayout_2->addWidget(lbHeight);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        sbHeight = new QSpinBox(layoutWidget);
        sbHeight->setObjectName(QStringLiteral("sbHeight"));

        horizontalLayout_2->addWidget(sbHeight);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbWidth = new QLabel(layoutWidget);
        lbWidth->setObjectName(QStringLiteral("lbWidth"));

        horizontalLayout_3->addWidget(lbWidth);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        sbWidth = new QSpinBox(layoutWidget);
        sbWidth->setObjectName(QStringLiteral("sbWidth"));

        horizontalLayout_3->addWidget(sbWidth);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


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
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
