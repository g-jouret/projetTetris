/********************************************************************************
** Form generated from reading UI file 'mwtetris.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
    QLabel *lbPlayerScore;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbTimer;
    QSpacerItem *horizontalSpacer_7;
    QLabel *lbTime;
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
    QLabel *lbEnd;
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

        lbPlayerScore = new QLabel(layoutWidget);
        lbPlayerScore->setObjectName(QStringLiteral("lbPlayerScore"));

        horizontalLayout_2->addWidget(lbPlayerScore);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lbTimer = new QLabel(layoutWidget);
        lbTimer->setObjectName(QStringLiteral("lbTimer"));

        horizontalLayout_6->addWidget(lbTimer);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        lbTime = new QLabel(layoutWidget);
        lbTime->setObjectName(QStringLiteral("lbTime"));

        horizontalLayout_6->addWidget(lbTime);


        verticalLayout->addLayout(horizontalLayout_6);

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
        lbEnd = new QLabel(centralWidget);
        lbEnd->setObjectName(QStringLiteral("lbEnd"));
        lbEnd->setEnabled(true);
        lbEnd->setGeometry(QRect(440, 470, 61, 16));
        MWTetris->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MWTetris);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 572, 20));
        menu_Jeu = new QMenu(menuBar);
        menu_Jeu->setObjectName(QStringLiteral("menu_Jeu"));
        MWTetris->setMenuBar(menuBar);

        menuBar->addAction(menu_Jeu->menuAction());
        menu_Jeu->addAction(action_Nouveau);
        menu_Jeu->addAction(action_Quitter);

        retranslateUi(MWTetris);

        QMetaObject::connectSlotsByName(MWTetris);
    } // setupUi

    void retranslateUi(QMainWindow *MWTetris)
    {
        MWTetris->setWindowTitle(QApplication::translate("MWTetris", "Tetris", Q_NULLPTR));
        action_Nouveau->setText(QApplication::translate("MWTetris", "&Nouveau", Q_NULLPTR));
        action_Nouveau->setShortcut(QApplication::translate("MWTetris", "Ctrl+N", Q_NULLPTR));
        action_Quitter->setText(QApplication::translate("MWTetris", "&Quitter", Q_NULLPTR));
        action_Quitter->setShortcut(QApplication::translate("MWTetris", "Ctrl+Q", Q_NULLPTR));
        lbName->setText(QApplication::translate("MWTetris", "Joueur :", Q_NULLPTR));
        lbPlayerName->setText(QApplication::translate("MWTetris", "Joueur", Q_NULLPTR));
        lbScore->setText(QApplication::translate("MWTetris", "score :", Q_NULLPTR));
        lbPlayerScore->setText(QApplication::translate("MWTetris", "0", Q_NULLPTR));
        lbTimer->setText(QApplication::translate("MWTetris", "Temps \303\251coul\303\251 :", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        lbTime->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        lbTime->setText(QApplication::translate("MWTetris", "0 : 00 : 00", Q_NULLPTR));
        btnUp->setText(QApplication::translate("MWTetris", "Haut", Q_NULLPTR));
        btnUp->setShortcut(QApplication::translate("MWTetris", "Up", Q_NULLPTR));
        btnLeft->setText(QApplication::translate("MWTetris", "Gauche", Q_NULLPTR));
        btnLeft->setShortcut(QApplication::translate("MWTetris", "Left", Q_NULLPTR));
        btnRight->setText(QApplication::translate("MWTetris", "Droite", Q_NULLPTR));
        btnRight->setShortcut(QApplication::translate("MWTetris", "Right", Q_NULLPTR));
        btnDown->setText(QApplication::translate("MWTetris", "Bas", Q_NULLPTR));
        lbEnd->setText(QApplication::translate("MWTetris", "Game Over", Q_NULLPTR));
        menu_Jeu->setTitle(QApplication::translate("MWTetris", "&Jeu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MWTetris: public Ui_MWTetris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWTETRIS_H
