/********************************************************************************
** Form generated from reading UI file 'mwtetris.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MWTETRIS_H
#define UI_MWTETRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MWTetris
{
public:
    QAction *action_Nouveau;
    QAction *action_Fermer;
    QAction *action_Quitter;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbName;
    QSpacerItem *horizontalSpacer;
    QLabel *lbPlayerName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbScore;
    QSpacerItem *horizontalSpacer_2;
    QLCDNumber *lcdNumPlayerScore;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnUp;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnLeft;
    QPushButton *btnRight;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnDown;
    QSpacerItem *horizontalSpacer_6;
    QWidget *gridLayoutWidget;
    QGridLayout *boardGrid;
    QMenuBar *menuBar;
    QMenu *menu_Jeu;

    void setupUi(QMainWindow *MWTetris)
    {
        if (MWTetris->objectName().isEmpty())
            MWTetris->setObjectName(QStringLiteral("MWTetris"));
        MWTetris->resize(572, 570);
        MWTetris->setIconSize(QSize(2, 2));
        action_Nouveau = new QAction(MWTetris);
        action_Nouveau->setObjectName(QStringLiteral("action_Nouveau"));
        action_Fermer = new QAction(MWTetris);
        action_Fermer->setObjectName(QStringLiteral("action_Fermer"));
        action_Fermer->setEnabled(false);
        action_Quitter = new QAction(MWTetris);
        action_Quitter->setObjectName(QStringLiteral("action_Quitter"));
        centralWidget = new QWidget(MWTetris);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(380, 40, 180, 391));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbName = new QLabel(layoutWidget);
        lbName->setObjectName(QStringLiteral("lbName"));

        horizontalLayout->addWidget(lbName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lbPlayerName = new QLabel(layoutWidget);
        lbPlayerName->setObjectName(QStringLiteral("lbPlayerName"));

        horizontalLayout->addWidget(lbPlayerName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbScore = new QLabel(layoutWidget);
        lbScore->setObjectName(QStringLiteral("lbScore"));

        horizontalLayout_2->addWidget(lbScore);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lcdNumPlayerScore = new QLCDNumber(layoutWidget);
        lcdNumPlayerScore->setObjectName(QStringLiteral("lcdNumPlayerScore"));

        horizontalLayout_2->addWidget(lcdNumPlayerScore);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btnUp = new QPushButton(layoutWidget);
        btnUp->setObjectName(QStringLiteral("btnUp"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(80);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(btnUp->sizePolicy().hasHeightForWidth());
        btnUp->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(btnUp);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        btnLeft = new QPushButton(layoutWidget);
        btnLeft->setObjectName(QStringLiteral("btnLeft"));
        sizePolicy.setHeightForWidth(btnLeft->sizePolicy().hasHeightForWidth());
        btnLeft->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(btnLeft);

        btnRight = new QPushButton(layoutWidget);
        btnRight->setObjectName(QStringLiteral("btnRight"));

        horizontalLayout_4->addWidget(btnRight);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        btnDown = new QPushButton(layoutWidget);
        btnDown->setObjectName(QStringLiteral("btnDown"));
        sizePolicy.setHeightForWidth(btnDown->sizePolicy().hasHeightForWidth());
        btnDown->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(btnDown);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_5);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 341, 501));
        boardGrid = new QGridLayout(gridLayoutWidget);
        boardGrid->setSpacing(6);
        boardGrid->setContentsMargins(11, 11, 11, 11);
        boardGrid->setObjectName(QStringLiteral("boardGrid"));
        boardGrid->setSizeConstraint(QLayout::SetNoConstraint);
        boardGrid->setContentsMargins(0, 0, 0, 0);
        MWTetris->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MWTetris);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 572, 20));
        menu_Jeu = new QMenu(menuBar);
        menu_Jeu->setObjectName(QStringLiteral("menu_Jeu"));
        MWTetris->setMenuBar(menuBar);

        menuBar->addAction(menu_Jeu->menuAction());
        menu_Jeu->addAction(action_Nouveau);
        menu_Jeu->addAction(action_Fermer);
        menu_Jeu->addAction(action_Quitter);

        retranslateUi(MWTetris);

        QMetaObject::connectSlotsByName(MWTetris);
    } // setupUi

    void retranslateUi(QMainWindow *MWTetris)
    {
        MWTetris->setWindowTitle(QApplication::translate("MWTetris", "Tetris", 0));
        action_Nouveau->setText(QApplication::translate("MWTetris", "&Nouveau", 0));
        action_Nouveau->setShortcut(QApplication::translate("MWTetris", "Ctrl+N", 0));
        action_Fermer->setText(QApplication::translate("MWTetris", "&Fermer", 0));
        action_Fermer->setShortcut(QApplication::translate("MWTetris", "Ctrl+X", 0));
        action_Quitter->setText(QApplication::translate("MWTetris", "&Quitter", 0));
        action_Quitter->setShortcut(QApplication::translate("MWTetris", "Ctrl+Q", 0));
        lbName->setText(QApplication::translate("MWTetris", "Joueur :", 0));
        lbPlayerName->setText(QApplication::translate("MWTetris", "Joueur", 0));
        lbScore->setText(QApplication::translate("MWTetris", "score :", 0));
        btnUp->setText(QApplication::translate("MWTetris", "Haut", 0));
        btnUp->setShortcut(QApplication::translate("MWTetris", "Up", 0));
        btnLeft->setText(QApplication::translate("MWTetris", "Gauche", 0));
        btnLeft->setShortcut(QApplication::translate("MWTetris", "Left", 0));
        btnRight->setText(QApplication::translate("MWTetris", "Droite", 0));
        btnRight->setShortcut(QApplication::translate("MWTetris", "Right", 0));
        btnDown->setText(QApplication::translate("MWTetris", "Bas", 0));
        menu_Jeu->setTitle(QApplication::translate("MWTetris", "&Jeu", 0));
    } // retranslateUi

};

namespace Ui {
    class MWTetris: public Ui_MWTetris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWTETRIS_H
