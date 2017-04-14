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
    QGridLayout *gridLayout;
    QVBoxLayout *infoBox;
    QHBoxLayout *horizontalLayout;
    QLabel *lbName;
    QSpacerItem *horizontalSpacer;
    QLabel *lbPlayerName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbScore;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lbPlayerScore;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbLines;
    QSpacerItem *horizontalSpacer_8;
    QLabel *lbPlayerLines;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbTimer;
    QSpacerItem *horizontalSpacer_7;
    QLabel *lbTime;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lbLevel;
    QLabel *lbLevelGame;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_13;
    QGridLayout *boardNext;
    QSpacerItem *horizontalSpacer_12;
    QPushButton *btnStart;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnUp;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *btnLeft;
    QPushButton *btnRight;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnDown;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *boardGrid;
    QMenuBar *menuBar;
    QMenu *menu_Jeu;

    void setupUi(QMainWindow *MWTetris)
    {
        if (MWTetris->objectName().isEmpty())
            MWTetris->setObjectName(QStringLiteral("MWTetris"));
        MWTetris->resize(270, 658);
        MWTetris->setStyleSheet(QStringLiteral("background: QLinearGradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #eef, stop: 1 #ccf);"));
        MWTetris->setIconSize(QSize(2, 2));
        action_Nouveau = new QAction(MWTetris);
        action_Nouveau->setObjectName(QStringLiteral("action_Nouveau"));
        action_Quitter = new QAction(MWTetris);
        action_Quitter->setObjectName(QStringLiteral("action_Quitter"));
        centralWidget = new QWidget(MWTetris);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        infoBox = new QVBoxLayout();
        infoBox->setSpacing(10);
        infoBox->setObjectName(QStringLiteral("infoBox"));
        infoBox->setSizeConstraint(QLayout::SetFixedSize);
        infoBox->setContentsMargins(10, 10, 10, 10);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbName = new QLabel(centralWidget);
        lbName->setObjectName(QStringLiteral("lbName"));
        lbName->setStyleSheet(QStringLiteral("QLabel {font-weight: bold; }"));

        horizontalLayout->addWidget(lbName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lbPlayerName = new QLabel(centralWidget);
        lbPlayerName->setObjectName(QStringLiteral("lbPlayerName"));

        horizontalLayout->addWidget(lbPlayerName);


        infoBox->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbScore = new QLabel(centralWidget);
        lbScore->setObjectName(QStringLiteral("lbScore"));
        lbScore->setStyleSheet(QStringLiteral("QLabel {font-weight: bold; }"));

        horizontalLayout_2->addWidget(lbScore);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lbPlayerScore = new QLabel(centralWidget);
        lbPlayerScore->setObjectName(QStringLiteral("lbPlayerScore"));

        horizontalLayout_2->addWidget(lbPlayerScore);


        infoBox->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lbLines = new QLabel(centralWidget);
        lbLines->setObjectName(QStringLiteral("lbLines"));
        lbLines->setStyleSheet(QStringLiteral("QLabel {font-weight: bold; }"));

        horizontalLayout_7->addWidget(lbLines);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);

        lbPlayerLines = new QLabel(centralWidget);
        lbPlayerLines->setObjectName(QStringLiteral("lbPlayerLines"));

        horizontalLayout_7->addWidget(lbPlayerLines);


        infoBox->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        lbTimer = new QLabel(centralWidget);
        lbTimer->setObjectName(QStringLiteral("lbTimer"));
        lbTimer->setStyleSheet(QStringLiteral("QLabel {font-weight: bold; }"));

        horizontalLayout_6->addWidget(lbTimer);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);

        lbTime = new QLabel(centralWidget);
        lbTime->setObjectName(QStringLiteral("lbTime"));

        horizontalLayout_6->addWidget(lbTime);


        infoBox->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        infoBox->addItem(verticalSpacer);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        lbLevel = new QLabel(centralWidget);
        lbLevel->setObjectName(QStringLiteral("lbLevel"));
        lbLevel->setEnabled(true);

        horizontalLayout_8->addWidget(lbLevel);

        lbLevelGame = new QLabel(centralWidget);
        lbLevelGame->setObjectName(QStringLiteral("lbLevelGame"));

        horizontalLayout_8->addWidget(lbLevelGame);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);


        infoBox->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_13);

        boardNext = new QGridLayout();
        boardNext->setSpacing(5);
        boardNext->setObjectName(QStringLiteral("boardNext"));
        boardNext->setSizeConstraint(QLayout::SetMaximumSize);

        horizontalLayout_9->addLayout(boardNext);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_12);


        infoBox->addLayout(horizontalLayout_9);

        btnStart = new QPushButton(centralWidget);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setStyleSheet(QLatin1String("QPushButton {\n"
"color: BLACK;\n"
"font-weight: bold;\n"
"border: none;\n"
"background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.0100503 rgba(255, 0, 0, 255), stop:0.1 rgba(255, 0, 0, 255), stop:0.2 rgba(255, 0, 0, 255), stop:0.3 rgba(255, 0, 0, 255), stop:0.4 rgba(255, 0, 0, 255), stop:0.502513 rgba(164, 0, 0, 205), stop:0.52 rgba(139, 0, 0, 205), stop:0.562814 rgba(0, 0, 0, 205), stop:0.6 rgba(255, 180, 180, 97), stop:1 rgba(255, 255, 255, 0));\n"
"max-width: 150px;\n"
"height: 150px;\n"
"}"));

        infoBox->addWidget(btnStart);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));

        infoBox->addLayout(horizontalLayout_10);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        infoBox->addItem(verticalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btnUp = new QPushButton(centralWidget);
        btnUp->setObjectName(QStringLiteral("btnUp"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(80);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(btnUp->sizePolicy().hasHeightForWidth());
        btnUp->setSizePolicy(sizePolicy);
        btnUp->setStyleSheet(QLatin1String("QPushButton {\n"
"color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);\n"
"border-width: 1px;\n"
"border-color: #339;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 10px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"min-width: 50px;\n"
"max-width: 50px;\n"
"min-height: 13px;\n"
"max-height: 13px;\n"
"}\n"
"QPushButton:pressed {	\n"
"background-color: rgb(0, 0, 180);\n"
" border-style: inset;\n"
"border-color: rgb(0, 0, 200);\n"
"}\n"
" QPushButton:disabled{\n"
"background-color: grey;\n"
"}"));

        horizontalLayout_3->addWidget(btnUp);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        infoBox->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        btnLeft = new QPushButton(centralWidget);
        btnLeft->setObjectName(QStringLiteral("btnLeft"));
        sizePolicy.setHeightForWidth(btnLeft->sizePolicy().hasHeightForWidth());
        btnLeft->setSizePolicy(sizePolicy);
        btnLeft->setStyleSheet(QLatin1String("QPushButton {\n"
"color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);\n"
"border-width: 1px;\n"
"border-color: #339;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 10px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"min-width: 50px;\n"
"max-width: 50px;\n"
"min-height: 13px;\n"
"max-height: 13px;\n"
"}\n"
"QPushButton:pressed {	\n"
"background-color: rgb(0, 0, 180);\n"
" border-style: inset;\n"
"border-color: rgb(0, 0, 200);\n"
"}\n"
" QPushButton:disabled{\n"
"background-color: grey;\n"
"}"));

        horizontalLayout_4->addWidget(btnLeft);

        btnRight = new QPushButton(centralWidget);
        btnRight->setObjectName(QStringLiteral("btnRight"));
        btnRight->setStyleSheet(QLatin1String("QPushButton {\n"
"color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);\n"
"border-width: 1px;\n"
"border-color: #339;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 10px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"min-width: 50px;\n"
"max-width: 50px;\n"
"min-height: 13px;\n"
"max-height: 13px;\n"
"}\n"
"QPushButton:pressed {	\n"
"background-color: rgb(0, 0, 180);\n"
" border-style: inset;\n"
"border-color: rgb(0, 0, 200);\n"
"}\n"
" QPushButton:disabled{\n"
"background-color: grey;\n"
"}"));

        horizontalLayout_4->addWidget(btnRight);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        infoBox->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        btnDown = new QPushButton(centralWidget);
        btnDown->setObjectName(QStringLiteral("btnDown"));
        sizePolicy.setHeightForWidth(btnDown->sizePolicy().hasHeightForWidth());
        btnDown->setSizePolicy(sizePolicy);
        btnDown->setStyleSheet(QLatin1String("QPushButton {\n"
"color: white;\n"
"background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);\n"
"border-width: 1px;\n"
"border-color: #339;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 10px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"min-width: 50px;\n"
"max-width: 50px;\n"
"min-height: 13px;\n"
"max-height: 13px;\n"
"}\n"
"QPushButton:pressed {	\n"
"background-color: rgb(0, 0, 180);\n"
" border-style: inset;\n"
"border-color: rgb(0, 0, 200);\n"
"}\n"
" QPushButton:disabled{\n"
"background-color: grey;\n"
"}"));

        horizontalLayout_5->addWidget(btnDown);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        infoBox->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        infoBox->addItem(verticalSpacer_2);


        gridLayout->addLayout(infoBox, 0, 1, 1, 1);

        boardGrid = new QGridLayout();
        boardGrid->setSpacing(3);
        boardGrid->setObjectName(QStringLiteral("boardGrid"));
        boardGrid->setSizeConstraint(QLayout::SetFixedSize);
        boardGrid->setContentsMargins(10, 10, 10, 10);

        gridLayout->addLayout(boardGrid, 0, 0, 1, 1);

        MWTetris->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MWTetris);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 270, 20));
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
        lbName->setText(QApplication::translate("MWTetris", "lbName", Q_NULLPTR));
        lbPlayerName->setText(QApplication::translate("MWTetris", "lbPlayerName", Q_NULLPTR));
        lbScore->setText(QApplication::translate("MWTetris", "lbScore", Q_NULLPTR));
        lbPlayerScore->setText(QApplication::translate("MWTetris", "00", Q_NULLPTR));
        lbLines->setText(QApplication::translate("MWTetris", "lbLines", Q_NULLPTR));
        lbPlayerLines->setText(QApplication::translate("MWTetris", "00", Q_NULLPTR));
        lbTimer->setText(QApplication::translate("MWTetris", "lbTimer", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        lbTime->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        lbTime->setText(QApplication::translate("MWTetris", "00:00", Q_NULLPTR));
        lbLevel->setText(QApplication::translate("MWTetris", "lbLevel", Q_NULLPTR));
        lbLevelGame->setText(QApplication::translate("MWTetris", "0", Q_NULLPTR));
        btnStart->setText(QApplication::translate("MWTetris", "COMMENCER", Q_NULLPTR));
        btnUp->setText(QApplication::translate("MWTetris", "Haut", Q_NULLPTR));
        btnUp->setShortcut(QApplication::translate("MWTetris", "Up", Q_NULLPTR));
        btnLeft->setText(QApplication::translate("MWTetris", "Gauche", Q_NULLPTR));
        btnLeft->setShortcut(QApplication::translate("MWTetris", "Left", Q_NULLPTR));
        btnRight->setText(QApplication::translate("MWTetris", "Droite", Q_NULLPTR));
        btnRight->setShortcut(QApplication::translate("MWTetris", "Right", Q_NULLPTR));
        btnDown->setText(QApplication::translate("MWTetris", "Bas", Q_NULLPTR));
        btnDown->setShortcut(QApplication::translate("MWTetris", "Down", Q_NULLPTR));
        menu_Jeu->setTitle(QApplication::translate("MWTetris", "&Jeu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MWTetris: public Ui_MWTetris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWTETRIS_H
