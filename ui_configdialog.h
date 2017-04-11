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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QWidget *layoutWidget;
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
    QPushButton *bricSetter;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbWinScore;
    QSpacerItem *horizontalSpacer_5;
    QSpinBox *sbWinScore;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbWinLines;
    QSpacerItem *horizontalSpacer_7;
    QSpinBox *sbWinLines;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lbWinTime;
    QSpacerItem *horizontalSpacer_8;
    QTimeEdit *timeEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbLevel;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *sbLevel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QStringLiteral("ConfigDialog"));
        ConfigDialog->resize(256, 329);
        layoutWidget = new QWidget(ConfigDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 21, 231, 291));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
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

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

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

        bricSetter = new QPushButton(layoutWidget);
        bricSetter->setObjectName(QStringLiteral("bricSetter"));

        verticalLayout->addWidget(bricSetter);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lbWinScore = new QLabel(layoutWidget);
        lbWinScore->setObjectName(QStringLiteral("lbWinScore"));

        horizontalLayout_5->addWidget(lbWinScore);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        sbWinScore = new QSpinBox(layoutWidget);
        sbWinScore->setObjectName(QStringLiteral("sbWinScore"));

        horizontalLayout_5->addWidget(sbWinScore);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lbWinLines = new QLabel(layoutWidget);
        lbWinLines->setObjectName(QStringLiteral("lbWinLines"));

        horizontalLayout_7->addWidget(lbWinLines);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        sbWinLines = new QSpinBox(layoutWidget);
        sbWinLines->setObjectName(QStringLiteral("sbWinLines"));

        horizontalLayout_7->addWidget(sbWinLines);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        lbWinTime = new QLabel(layoutWidget);
        lbWinTime->setObjectName(QStringLiteral("lbWinTime"));

        horizontalLayout_8->addWidget(lbWinTime);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        timeEdit = new QTimeEdit(layoutWidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));

        horizontalLayout_8->addWidget(timeEdit);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lbLevel = new QLabel(layoutWidget);
        lbLevel->setObjectName(QStringLiteral("lbLevel"));

        horizontalLayout_4->addWidget(lbLevel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        sbLevel = new QSpinBox(layoutWidget);
        sbLevel->setObjectName(QStringLiteral("sbLevel"));

        horizontalLayout_4->addWidget(sbLevel);


        verticalLayout->addLayout(horizontalLayout_4);

        buttonBox = new QDialogButtonBox(layoutWidget);
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
        lbHeight->setText(QApplication::translate("ConfigDialog", "Hauteur du cadre (cases)", Q_NULLPTR));
        lbWidth->setText(QApplication::translate("ConfigDialog", "Largeur du cadre (cases)", Q_NULLPTR));
        bricSetter->setText(QApplication::translate("ConfigDialog", "Brique personnalis\303\251e", Q_NULLPTR));
        lbWinScore->setText(QApplication::translate("ConfigDialog", "Score de victoire ", Q_NULLPTR));
        lbWinLines->setText(QApplication::translate("ConfigDialog", "Nombre de lignes de victoire", Q_NULLPTR));
        lbWinTime->setText(QApplication::translate("ConfigDialog", "Temps de jeu ", Q_NULLPTR));
        timeEdit->setDisplayFormat(QApplication::translate("ConfigDialog", "mm:ss", Q_NULLPTR));
        lbLevel->setText(QApplication::translate("ConfigDialog", "Niveau de difficult\303\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
