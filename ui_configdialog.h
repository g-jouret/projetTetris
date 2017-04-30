/********************************************************************************
** Form generated from reading UI file 'configdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbName;
    QSpacerItem *horizontalSpacer;
    QLineEdit *leName;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbWinScore;
    QSpacerItem *horizontalSpacer_5;
    QSpinBox *sbWinScore;
    QCheckBox *hasWinByScore;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbWinLines;
    QSpacerItem *horizontalSpacer_7;
    QSpinBox *sbWinLines;
    QCheckBox *hasWinByLines;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lbWinTime;
    QSpacerItem *horizontalSpacer_8;
    QTimeEdit *timeEdit;
    QCheckBox *HasWinByTime;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbLevel;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *sbLevel;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbWidth;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *sbWidth;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbHeight;
    QSpacerItem *horizontalSpacer_2;
    QSpinBox *sbHeight;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *defaultBrics;
    QCheckBox *keepBag;
    QPushButton *bricSetter;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *playDuo;
    QHBoxLayout *ipLayout;
    QLabel *lbHost;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *leHost;
    QHBoxLayout *portLayout;
    QLabel *lbPort;
    QSpacerItem *horizontalSpacer_9;
    QSpinBox *sbPort;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QStringLiteral("ConfigDialog"));
        ConfigDialog->resize(542, 244);
        gridLayout = new QGridLayout(ConfigDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbName = new QLabel(ConfigDialog);
        lbName->setObjectName(QStringLiteral("lbName"));

        horizontalLayout->addWidget(lbName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        leName = new QLineEdit(ConfigDialog);
        leName->setObjectName(QStringLiteral("leName"));

        horizontalLayout->addWidget(leName);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lbWinScore = new QLabel(ConfigDialog);
        lbWinScore->setObjectName(QStringLiteral("lbWinScore"));

        horizontalLayout_5->addWidget(lbWinScore);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        sbWinScore = new QSpinBox(ConfigDialog);
        sbWinScore->setObjectName(QStringLiteral("sbWinScore"));

        horizontalLayout_5->addWidget(sbWinScore);

        hasWinByScore = new QCheckBox(ConfigDialog);
        hasWinByScore->setObjectName(QStringLiteral("hasWinByScore"));
        hasWinByScore->setChecked(true);

        horizontalLayout_5->addWidget(hasWinByScore);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lbWinLines = new QLabel(ConfigDialog);
        lbWinLines->setObjectName(QStringLiteral("lbWinLines"));

        horizontalLayout_7->addWidget(lbWinLines);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        sbWinLines = new QSpinBox(ConfigDialog);
        sbWinLines->setObjectName(QStringLiteral("sbWinLines"));

        horizontalLayout_7->addWidget(sbWinLines);

        hasWinByLines = new QCheckBox(ConfigDialog);
        hasWinByLines->setObjectName(QStringLiteral("hasWinByLines"));
        hasWinByLines->setChecked(true);

        horizontalLayout_7->addWidget(hasWinByLines);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        lbWinTime = new QLabel(ConfigDialog);
        lbWinTime->setObjectName(QStringLiteral("lbWinTime"));

        horizontalLayout_8->addWidget(lbWinTime);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        timeEdit = new QTimeEdit(ConfigDialog);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));

        horizontalLayout_8->addWidget(timeEdit);

        HasWinByTime = new QCheckBox(ConfigDialog);
        HasWinByTime->setObjectName(QStringLiteral("HasWinByTime"));
        HasWinByTime->setChecked(true);

        horizontalLayout_8->addWidget(HasWinByTime);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lbLevel = new QLabel(ConfigDialog);
        lbLevel->setObjectName(QStringLiteral("lbLevel"));

        horizontalLayout_4->addWidget(lbLevel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        sbLevel = new QSpinBox(ConfigDialog);
        sbLevel->setObjectName(QStringLiteral("sbLevel"));

        horizontalLayout_4->addWidget(sbLevel);


        verticalLayout_3->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 2, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbWidth = new QLabel(ConfigDialog);
        lbWidth->setObjectName(QStringLiteral("lbWidth"));

        horizontalLayout_3->addWidget(lbWidth);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        sbWidth = new QSpinBox(ConfigDialog);
        sbWidth->setObjectName(QStringLiteral("sbWidth"));

        horizontalLayout_3->addWidget(sbWidth);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbHeight = new QLabel(ConfigDialog);
        lbHeight->setObjectName(QStringLiteral("lbHeight"));

        horizontalLayout_2->addWidget(lbHeight);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        sbHeight = new QSpinBox(ConfigDialog);
        sbHeight->setObjectName(QStringLiteral("sbHeight"));

        horizontalLayout_2->addWidget(sbHeight);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        defaultBrics = new QCheckBox(ConfigDialog);
        defaultBrics->setObjectName(QStringLiteral("defaultBrics"));
        defaultBrics->setChecked(true);

        verticalLayout_4->addWidget(defaultBrics);

        keepBag = new QCheckBox(ConfigDialog);
        keepBag->setObjectName(QStringLiteral("keepBag"));
        keepBag->setEnabled(false);
        keepBag->setCheckable(true);
        keepBag->setChecked(true);

        verticalLayout_4->addWidget(keepBag);

        bricSetter = new QPushButton(ConfigDialog);
        bricSetter->setObjectName(QStringLiteral("bricSetter"));

        verticalLayout_4->addWidget(bricSetter);


        gridLayout->addLayout(verticalLayout_4, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ConfigDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        playDuo = new QCheckBox(ConfigDialog);
        playDuo->setObjectName(QStringLiteral("playDuo"));

        verticalLayout->addWidget(playDuo);

        ipLayout = new QHBoxLayout();
        ipLayout->setObjectName(QStringLiteral("ipLayout"));
        lbHost = new QLabel(ConfigDialog);
        lbHost->setObjectName(QStringLiteral("lbHost"));

        ipLayout->addWidget(lbHost);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        ipLayout->addItem(horizontalSpacer_6);

        leHost = new QLineEdit(ConfigDialog);
        leHost->setObjectName(QStringLiteral("leHost"));

        ipLayout->addWidget(leHost);


        verticalLayout->addLayout(ipLayout);

        portLayout = new QHBoxLayout();
        portLayout->setObjectName(QStringLiteral("portLayout"));
        lbPort = new QLabel(ConfigDialog);
        lbPort->setObjectName(QStringLiteral("lbPort"));

        portLayout->addWidget(lbPort);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        portLayout->addItem(horizontalSpacer_9);

        sbPort = new QSpinBox(ConfigDialog);
        sbPort->setObjectName(QStringLiteral("sbPort"));
        sbPort->setMinimum(49153);
        sbPort->setMaximum(65535);
        sbPort->setValue(49200);

        portLayout->addWidget(sbPort);


        verticalLayout->addLayout(portLayout);


        gridLayout->addLayout(verticalLayout, 2, 1, 1, 1);


        retranslateUi(ConfigDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigDialog, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "Configuration de la partie", Q_NULLPTR));
        lbName->setText(QApplication::translate("ConfigDialog", "Nom", Q_NULLPTR));
        lbWinScore->setText(QApplication::translate("ConfigDialog", "Score de victoire ", Q_NULLPTR));
        hasWinByScore->setText(QApplication::translate("ConfigDialog", "Activer?", Q_NULLPTR));
        lbWinLines->setText(QApplication::translate("ConfigDialog", "Nombre de lignes de victoire", Q_NULLPTR));
        hasWinByLines->setText(QApplication::translate("ConfigDialog", "Activer?", Q_NULLPTR));
        lbWinTime->setText(QApplication::translate("ConfigDialog", "Temps de jeu ", Q_NULLPTR));
        timeEdit->setDisplayFormat(QApplication::translate("ConfigDialog", "mm:ss", Q_NULLPTR));
        HasWinByTime->setText(QApplication::translate("ConfigDialog", "Activer?", Q_NULLPTR));
        lbLevel->setText(QApplication::translate("ConfigDialog", "Niveau de difficult\303\251", Q_NULLPTR));
        lbWidth->setText(QApplication::translate("ConfigDialog", "Largeur du cadre (cases)", Q_NULLPTR));
        lbHeight->setText(QApplication::translate("ConfigDialog", "Hauteur du cadre (cases)", Q_NULLPTR));
        defaultBrics->setText(QApplication::translate("ConfigDialog", "Utiliser les briques par d\303\251faut?", Q_NULLPTR));
        keepBag->setText(QApplication::translate("ConfigDialog", "Conserver l'ancien sac de briques?", Q_NULLPTR));
        bricSetter->setText(QApplication::translate("ConfigDialog", "Nouvelle brique personnalis\303\251e", Q_NULLPTR));
        playDuo->setText(QApplication::translate("ConfigDialog", "Jouer en duo?", Q_NULLPTR));
        lbHost->setText(QApplication::translate("ConfigDialog", "Nom d'host de votre adversaire", Q_NULLPTR));
        lbPort->setText(QApplication::translate("ConfigDialog", "Port \303\240 utiliser", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
